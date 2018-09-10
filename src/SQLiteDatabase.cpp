#include "SQLiteDatabase.h"

#include "Exceptions.h"
#include "QueriesManager.h"

#include <qsqlquery.h>
#include <qsqlerror.h>

auto SQLiteDatabase::open() -> void
{
	if (!_database.open())
		throw CouldNotOpenDatabaseException("The SQLite database couldn't be opened.");
}

auto SQLiteDatabase::createMainTable() -> void
{
	static QString const createTableTemplate{ "CREATE TABLE contacts (id INTEGER PRIMARY KEY AUTOINCREMENT, lastname TEXT, firstname TEXT, phonenumber TEXT);" };
	QSqlQuery query;

	if (!query.exec(createTableTemplate))
		throw CouldNotCreateDatabaseTableException(query.lastError().text().toStdString());
}

auto SQLiteDatabase::addContact(QString const & lastName, QString const & firstName, QString const & phoneNumber) -> void
{
	QSqlQuery query = QueriesManager::createAddPersonQuery(lastName, firstName, phoneNumber);

	if (!query.exec())
		throw CouldNotAddContactException(query.lastError().text().toStdString());
}

auto SQLiteDatabase::searchContact(QString const& lastName, QString const& firstName) -> int
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(lastName, firstName);
	
	if (!query.exec())
		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());
	
	int contactId{ QueriesManager::NotFoundContactFlag };
	while (query.next())
	{
		static QString const idField{ "id" };
		contactId = query.value(idField).toInt();
	}

	return contactId;
}

auto SQLiteDatabase::updateContact(QString const & lastName, QString const & firstName, QString const & phoneNumber, int const id) -> void
{
	QSqlQuery query = QueriesManager::createUpdatePersonQuery(lastName, firstName, phoneNumber, id);

	if (!query.exec())
		throw CouldNotUpdateContactException(query.lastError().text().toStdString());
}

auto SQLiteDatabase::retrieveContactData(int const id) -> ContactData
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(id);
	static QString const errorMessage{ "Could not find the requested contact." };

	if (!query.exec())
		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());
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

		return ContactData(lastName, firstName, phoneNumber);
	}

	return ContactData();
}
