#include "phonebook.h"
#include "adddialog.h"
#include "searchdialog.h"

#include <qdir.h>
#include <qsqlquery.h>
#include <qdebug.h>
#include <qsqlerror.h>
#include <qmessagebox.h>

#include "QueriesManager.h"
#include "Exceptions.h"

int constexpr databaseOffset{ 1 };
char constexpr space{ ' ' };

PhoneBook::PhoneBook(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
}

auto PhoneBook::prepareDatabaseForUsage() -> void
{
	_database.prepareForUsage();
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

				QListWidgetItem* item = new QListWidgetItem(lastName + space + firstName + space + phoneNumber, ui.peopleListWidget);
				ui.peopleListWidget->addItem(item);
				ui.peopleListWidget->setCurrentItem(item);
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
				int id = _database.searchContact(lastName, firstName);
				if (id != QueriesManager::NotFoundContactFlag)
					ui.peopleListWidget->setCurrentRow(id - databaseOffset);
				else
				{
					static QString const errorTitle{ "Not found." };
					static QString const errorMessage{ "The contact was not found." };
					QMessageBox::warning(&dialog, errorTitle, errorMessage);
				}
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
	QListWidgetItem* item = ui.peopleListWidget->currentItem();
	
	if (item)
	{
		int row = ui.peopleListWidget->row(item);
		ContactData data = _database.retrieveContactData(row + databaseOffset);

		QString lastName = std::get<0>(data);
		QString firstName = std::get<1>(data);
		QString phoneNumber = std::get<2>(data);

		AddDialog dialog(this);
		dialog.setEditFieldsText(lastName, firstName, phoneNumber);

		if (dialog.exec())
		{
			if (hasAnyLineEditFieldChanged(dialog))
			{
				lastName = dialog.lastNameEdit->text();
				firstName = dialog.firstNameEdit->text();
				phoneNumber = dialog.phoneNumberEdit->text();
				
				try
				{
					_database.updateContact(lastName, firstName, phoneNumber, row + databaseOffset);
					item->setText(lastName + space + firstName + space + phoneNumber);
				}
				catch (CouldNotUpdateContactException const& e)
				{
					static QString const errorMessage{ "Could not update this contact's data." };
					QMessageBox::warning(&dialog, errorMessage, e.what());
				}
			}
		}
	}
}

//void PhoneBook::on_deleteButton_clicked()
//{
//	QListWidgetItem* item = ui.peopleListWidget->currentItem();
//
//	if (item)
//	{
//		int row = ui.peopleListWidget->row(item);
//		QSqlQuery query = QueriesManager::createDeletePersonQuery(row + databaseOffset);
//		static QString const errorMessage{ "Could not delete the contact." };
//
//		if (!query.exec())
//			QMessageBox::warning(this, errorMessage, query.lastError().text());
//		else
//		{
//			ui.peopleListWidget->takeItem(row);
//			delete item;
//		}
//	}
//};
