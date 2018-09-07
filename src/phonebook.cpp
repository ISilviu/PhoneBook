#include "phonebook.h"
#include "adddialog.h"
#include "searchdialog.h"
#include "updatedecisiondialog.h"

#include <qdir.h>
#include <qsqlquery.h>
#include <qdebug.h>
#include <qsqlerror.h>
#include <qmessagebox.h>

#include "CouldNotOpenDatabaseException.h"
#include "QueriesManager.h"

static int constexpr databaseOffset{ 1 };
static char constexpr space{ ' ' };

PhoneBook::PhoneBook(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	prepareDatabaseForUsage();
}

auto PhoneBook::createDatabaseMainTable() -> void
{
	static QString const createTableQuery{ "CREATE TABLE contacts (id INTEGER PRIMARY KEY AUTOINCREMENT, lastname TEXT, firstname TEXT, phonenumber TEXT);" };
	static QString const errorMessage{ "Could now create the table." };
	QSqlQuery query;

	if (!query.exec(createTableQuery))
	{
		QMessageBox::critical(this, errorMessage, query.lastError().text());
		std::exit(EXIT_FAILURE);
	}
}

auto PhoneBook::createDatabaseFile() -> void
{
	static QString const driver{ "QSQLITE" };

	if (QSqlDatabase::isDriverAvailable(driver))
	{
		_database = QSqlDatabase::addDatabase(driver);

		static QString const databaseName{ ":memory:" };
		_database.setDatabaseName(databaseName);
	}
}

auto PhoneBook::prepareDatabaseForUsage() -> void
{
	createDatabaseFile();

	if (!_database.open())
		throw CouldNotOpenDatabaseException(_database.lastError().text().toStdString()); 
	
	createDatabaseMainTable();
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
			QSqlQuery query = QueriesManager::createAddPersonQuery(lastName, firstName, phoneNumber);
			static QString const errorMessage{ "Could not add the contact." };

			if (!query.exec())
				QMessageBox::warning(&dialog, errorMessage, query.lastError().text());
			else
			{
				QListWidgetItem* item = new QListWidgetItem(lastName + space + firstName + space + phoneNumber, ui.peopleListWidget);
				ui.peopleListWidget->addItem(item);
				ui.peopleListWidget->setCurrentItem(item);
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
			static QString const errorMessage{ "Could not search for the contact." };
			QSqlQuery query = QueriesManager::createSearchPersonQuery(lastName, firstName);

			if (!query.exec())
				QMessageBox::warning(&dialog, errorMessage, query.lastError().text());
			else
			{
				static int constexpr notFoundFlag{ -1 };
				int id{ notFoundFlag };

				while (query.next())
				{
					static QString const idField{ "id" };

					id = query.value(idField).toInt();
					ui.peopleListWidget->setCurrentRow(id - databaseOffset);
				} 

				if (id == notFoundFlag)
				{
					static QString const errorTitle{ "Not found." };
					static QString const errorMessage{ "The contact was not found." };
					QMessageBox::warning(&dialog, errorTitle, errorMessage);
				}

			}
		}
	}
}

void PhoneBook::on_deleteButton_clicked()
{
	QListWidgetItem* item = ui.peopleListWidget->currentItem();

	if (item)
	{
		int row = ui.peopleListWidget->row(item);
		QSqlQuery query = QueriesManager::createDeletePersonQuery(row + databaseOffset);
		static QString const errorMessage{ "Could not delete the contact." };

		if (!query.exec())
			QMessageBox::warning(this, errorMessage, query.lastError().text());
		else
		{
			ui.peopleListWidget->takeItem(row);
			delete item;
		}
	}
}

auto PhoneBook::retrievePersonData(int const row) noexcept -> PersonData
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(row);
	static QString const errorMessage{ "Could not find the requested contact." };

	if (!query.exec())
		QMessageBox::warning(this, errorMessage, query.lastError().text());
	else
	{
		QString lastName;
		QString firstName;
		QString phoneNumber;

		while (query.next())
		{
			 lastName = query.value(0).toString();
			 firstName = query.value(1).toString();
			 phoneNumber = query.value(2).toString();
		} 

		return PersonData(lastName, firstName, phoneNumber);
	}
	
	return PersonData();
}

void PhoneBook::on_updateButton_clicked()
{
	QListWidgetItem* item = ui.peopleListWidget->currentItem();
	
	if (item)
	{
		int row = ui.peopleListWidget->row(item);
		PersonData data = retrievePersonData(row + databaseOffset);

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

				QSqlQuery query = QueriesManager::createUpdatePersonQuery(lastName, firstName, phoneNumber, row + databaseOffset);
				static QString const errorMessage{ "Could not update this person's data." };

				if (!query.exec())
					QMessageBox::warning(&dialog, errorMessage, query.lastError().text());
				else
					item->setText(lastName + space + firstName + space + phoneNumber);
			}
		}
	}
}
