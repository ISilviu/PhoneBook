#include "QtUiPlugin.h"
#include "Exceptions.h"

#include "adddialog.h"
#include "searchdialog.h"
#include "foundcontactsdialog.h"
#include "idrequestdialog.h"

#include <qmessagebox.h>
#include <qsqlquery.h>

#include "InMemorySQLiteStoragePlugin.h"

std::vector<IPlugin*> QtUiPlugin::getDependencies() const
{
	return _dependencies;
}

void QtUiPlugin::init(std::vector<IPlugin*> const& dependencies)
{
	if (typeid(dependencies.front()) != typeid(_dependencies.front()))
		throw NonMatchingDependencyTypeException("The provided plugin is not the needed one.");

	ui.setupUi(this);

	_storagePlugin = dynamic_cast<InMemorySQLiteStoragePlugin*>(dependencies.front());

	ui.tableView->setModel(_storagePlugin->getModel());
}

QtUiPlugin::QtUiPlugin(QWidget* parent)
	: QWidget(parent)
{
	initializeDependencies();
}

void QtUiPlugin::run()
{
	show();
}

void QtUiPlugin::shutDown()
{
	hide();
}

auto QtUiPlugin::updateView(QSqlQueryModel * model) noexcept -> void
{
	static QString const query{ "SELECT * FROM contacts" };
	model->setQuery(query);
}

auto QtUiPlugin::initializeDependencies() noexcept -> void
{
	InMemorySQLiteStoragePlugin storagePlugin;

	_dependencies.push_back(&storagePlugin);
}

auto QtUiPlugin::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty() && !phoneNumber.isEmpty());
}

auto QtUiPlugin::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept ->bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty());
}

auto QtUiPlugin::hasAnyLineEditFieldChanged(AddDialog const & dialog) const noexcept -> bool
{
	return (dialog.lastNameEdit->isModified() || dialog.firstNameEdit->isModified() || dialog.phoneNumberEdit->isModified());
}

void QtUiPlugin::on_addButton_clicked()
{
	AddDialog dialog(this);
	if (dialog.exec())
	{
		QString lastName = dialog.lastNameEdit->text();
		QString firstName = dialog.firstNameEdit->text();
		QString phoneNumber = dialog.phoneNumberEdit->text();

		if (areAllLineEditFieldsFilled(lastName, firstName, phoneNumber))
		{
			try
			{

				_storagePlugin->_database.addContact(lastName, firstName, phoneNumber);

				_storagePlugin->updateView();
			}
			catch (CouldNotAddContactException const& e)
			{
				static QString const errorMessage{ "Could not add the contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}

}

void QtUiPlugin::on_searchButton_clicked()
{
	SearchDialog dialog(this);
	if (dialog.exec())
	{
		QString lastName = dialog.lastNameEdit->text();
		QString firstName = dialog.firstNameEdit->text();

		if (areAllLineEditFieldsFilled(lastName, firstName))
		{
			try
			{
				FoundContactsDialog foundContactsDialog(&dialog);
				QSqlQueryModel* model = new QSqlQueryModel(&foundContactsDialog);

				model->setQuery(_storagePlugin->_database.searchContact(lastName, firstName));
				foundContactsDialog.foundContactsTableView->setModel(model);
				foundContactsDialog.exec();
			}
			catch (CouldNotSearchForTheContactException const& e)
			{
				static QString const errorMessage{ "Could not search for the contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}
}

void QtUiPlugin::on_updateButton_clicked()
{
	IdRequestDialog dialog(this);
	if (dialog.exec())
	{
		QString const id = dialog.idLineEdit->text();
		if (!id.isEmpty())
		{

			ContactData data = _storagePlugin->_database.retrieveContactData(id.toInt());

			QString lastName = std::get<0>(data);
			QString firstName = std::get<1>(data);
			QString phoneNumber = std::get<2>(data);

			if (!lastName.isEmpty() && !firstName.isEmpty() && !phoneNumber.isEmpty())
			{
				AddDialog updateDialog(&dialog);
				updateDialog.setEditFieldsText(lastName, firstName, phoneNumber);

				if (updateDialog.exec())
				{
					if (hasAnyLineEditFieldChanged(updateDialog))
					{
						lastName = updateDialog.lastNameEdit->text();
						firstName = updateDialog.firstNameEdit->text();
						phoneNumber = updateDialog.phoneNumberEdit->text();

						try
						{
							_storagePlugin->_database.updateContact(lastName, firstName, phoneNumber, id.toInt());

							_storagePlugin->updateView();
						}
						catch (CouldNotUpdateContactException const& e)
						{
							static QString const errorMessage{ "Could not update the contact." };
							QMessageBox::warning(&dialog, errorMessage, e.what());
						}
					}
				}
			}
			else
			{
				static QString const errorTitle{ "Not found." };
				static QString const errorMessage{ "The Id you entered was not found." };
				QMessageBox::warning(&dialog, errorTitle, errorMessage);
			}
		}

	}
}

void QtUiPlugin::on_deleteButton_clicked()
{
	IdRequestDialog dialog(this);
	if (dialog.exec())
	{
		QString const id = dialog.idLineEdit->text();
		if (!id.isEmpty())
		{
			try
			{
				_storagePlugin->_database.deleteContact(id.toInt());

				_storagePlugin->updateView();
			}
			catch (CouldNotDeleteContactException const& e)
			{
				static QString const errorMessage{ "Could not delete this contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}
};
