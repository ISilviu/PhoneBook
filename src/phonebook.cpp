#include "phonebook.h"
#include "adddialog.h"
#include "searchdialog.h"
#include "foundcontactsdialog.h"
#include "idrequestdialog.h"

#include <qdir.h>
#include <qsqlquery.h>
#include <qdebug.h>
#include <qsqlerror.h>
#include <qmessagebox.h>

#include "QueriesManager.h"
#include "Exceptions.h"

PhoneBook::PhoneBook(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	_model = new QSqlQueryModel(this);
	
	connectViewAndModel();
}

auto PhoneBook::prepareDatabaseForUsage() -> void
{
	_database.prepareForUsage();
}

auto PhoneBook::connectViewAndModel() noexcept -> void
{
	ui.tableView->setModel(_model);
}

auto PhoneBook::updateView() noexcept -> void
{
	static QString const query{ "SELECT * FROM contacts" };
	_model->setQuery(query);
}

auto PhoneBook::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty() && !phoneNumber.isEmpty());
}

auto PhoneBook::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept ->bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty());
}

auto PhoneBook::hasAnyLineEditFieldChanged(AddDialog const & dialog) const noexcept -> bool
{
	return (dialog.lastNameEdit->isModified() || dialog.firstNameEdit->isModified() || dialog.phoneNumberEdit->isModified());
}

void PhoneBook::on_addButton_clicked()
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
				_database.addContact(lastName, firstName, phoneNumber);

				updateView();
			}
			catch (CouldNotAddContactException const& e)
			{
				static QString const errorMessage{ "Could not add the contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}

}

void PhoneBook::on_searchButton_clicked()
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

				model->setQuery(_database.searchContact(lastName,firstName));
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

void PhoneBook::on_updateButton_clicked()
{
	IdRequestDialog dialog(this);
	if (dialog.exec())
	{
		QString const id = dialog.idLineEdit->text();
		if (!id.isEmpty())
		{
			ContactData data = _database.retrieveContactData(id.toInt());
			
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
							_database.updateContact(lastName, firstName, phoneNumber, id.toInt());

							updateView();
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

void PhoneBook::on_deleteButton_clicked()
{
	IdRequestDialog dialog(this);
	if (dialog.exec())
	{
		QString const id = dialog.idLineEdit->text();
		if (!id.isEmpty())
		{
			try
			{
				_database.deleteContact(id.toInt());

				updateView();
			}
			catch (CouldNotDeleteContactException const& e)
			{
				static QString const errorMessage{ "Could not delete this contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}

};
