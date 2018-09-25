#include "UiMainWidget.h"
#include "Exceptions.h"

#include "adddialog.h"
#include "searchdialog.h"
#include "foundcontactsdialog.h"
#include "idrequestdialog.h"

#include <qmessagebox.h>
#include <qsqlquery.h>

#include "InMemorySQLiteStoragePlugin.h"

#include "LastName.h"
#include "FirstName.h"
#include "PhoneNumber.h"
#include "ContactId.h"
#include "Contact.h"

#include "StoragePluginSpecificExceptions.h"

UiMainWidget::UiMainWidget(QWidget* parent)
	:QWidget(parent)
{
	ui.setupUi(this);
}

void UiMainWidget::init(InMemorySQLiteDatabase const& readModel)
{
	_readModel = readModel;

	ui.tableView->setModel(_readModel.getModel());
}

auto UiMainWidget::areAllLineEditFieldsFilled(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) const noexcept -> bool
{
	return (!lastName.get().empty() && !firstName.get().empty() && !phoneNumber.get().empty());
}

auto UiMainWidget::areAllLineEditFieldsFilled(LastName const& lastName, FirstName const& firstName) const noexcept ->bool
{
	return (!lastName.get().empty() && !firstName.get().empty());
}

auto UiMainWidget::hasAnyLineEditFieldChanged(AddDialog const & dialog) const noexcept -> bool
{
	return (dialog.lastNameEdit->isModified() || dialog.firstNameEdit->isModified() || dialog.phoneNumberEdit->isModified());
}

void UiMainWidget::on_addButton_clicked()
{
	AddDialog dialog(this);
	if (dialog.exec())
	{
		LastName lastName = dialog.lastNameEdit->text().toStdString();
		FirstName firstName = dialog.firstNameEdit->text().toStdString();
		PhoneNumber phoneNumber = dialog.phoneNumberEdit->text().toStdString();

		if (areAllLineEditFieldsFilled(lastName, firstName, phoneNumber))
		{
			try
			{
				_readModel.addContact(lastName, firstName, phoneNumber);

				_readModel.updateView();
			}
			catch (CouldNotAddContactException const& e)
			{
				static QString const errorMessage{ "Could not add the contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}

}

void UiMainWidget::on_searchButton_clicked()
{
	SearchDialog dialog(this);
	if (dialog.exec())
	{
		LastName lastName = dialog.lastNameEdit->text().toStdString();
		FirstName firstName = dialog.firstNameEdit->text().toStdString();

		if (areAllLineEditFieldsFilled(lastName, firstName))
		{
			try
			{
				FoundContactsDialog foundContactsDialog(&dialog);
				QSqlQueryModel* model = new QSqlQueryModel(&foundContactsDialog);

				model->setQuery(_readModel.searchContact(lastName, firstName));
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

void UiMainWidget::on_updateButton_clicked()
{
	IdRequestDialog dialog(this);
	if (dialog.exec())
	{

		if (!dialog.idLineEdit->text().isEmpty())
		{
			ContactId id = dialog.idLineEdit->text().toInt();

			Contact data = _readModel.retrieveContactData(id.get());

			if (!data.isEmpty())
			{
				AddDialog updateDialog(&dialog);
				updateDialog.setEditFieldsText(QString::fromUtf8(data.lastName().c_str())
					,QString::fromUtf8(data.firstName().c_str()), QString::fromUtf8(data.phoneNumber().c_str()));

				if (updateDialog.exec())
				{
					if (hasAnyLineEditFieldChanged(updateDialog))
					{
						LastName lastName = updateDialog.lastNameEdit->text().toStdString();
						FirstName firstName = updateDialog.firstNameEdit->text().toStdString();
						PhoneNumber phoneNumber = updateDialog.phoneNumberEdit->text().toStdString();

						try
						{
							_readModel.updateContact(lastName, firstName, phoneNumber, id);

							_readModel.updateView();
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

void UiMainWidget::on_deleteButton_clicked()
{
	IdRequestDialog dialog(this);
	if (dialog.exec())
	{
		QString const id = dialog.idLineEdit->text();
		if (!id.isEmpty())
		{
			try
			{
				_readModel.deleteContact(id.toInt());

				_readModel.updateView();
			}
			catch (CouldNotDeleteContactException const& e)
			{
				static QString const errorMessage{ "Could not delete this contact." };
				QMessageBox::warning(&dialog, errorMessage, e.what());
			}
		}
	}
};
