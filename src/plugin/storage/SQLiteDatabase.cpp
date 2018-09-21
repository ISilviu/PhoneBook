#include "SQLiteDatabase.h"

#include "Exceptions.h"
#include "QueriesManager.h"

#include <qsqlquery.h>
#include <qsqlerror.h>

#include "Contact.h"

auto SQLiteDatabase::open() -> void
{
	if (!_database.open())
		throw CouldNotOpenDatabaseException("The SQLite database couldn't be opened.");
}

auto SQLiteDatabase::close() -> void
{
	_database.close();
}

auto SQLiteDatabase::createMainTable() -> void
{
	static QString const createTableTemplate{ "CREATE TABLE contacts (id INTEGER PRIMARY KEY AUTOINCREMENT, lastname TEXT, firstname TEXT, phonenumber TEXT);" };
	QSqlQuery query;

	if (!query.exec(createTableTemplate))
		throw CouldNotCreateDatabaseTableException(query.lastError().text().toStdString());
}

auto SQLiteDatabase::addContact(LastName const & lastName, FirstName const & firstName, PhoneNumber const & phoneNumber) -> void
{
	QSqlQuery query = QueriesManager::createAddPersonQuery(lastName, firstName, phoneNumber);

	if (!query.exec())
		throw CouldNotAddContactException(query.lastError().text().toStdString());
}

//auto SQLiteDatabase::addContact(QString const & lastName, QString const & firstName, QString const & phoneNumber) -> void
//{
//	QSqlQuery query = QueriesManager::createAddPersonQuery(lastName, firstName, phoneNumber);
//
//	if (!query.exec())
//		throw CouldNotAddContactException(query.lastError().text().toStdString());
//}

auto SQLiteDatabase::searchContact(LastName const & lastName, FirstName const & firstName) -> QSqlQuery
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(lastName, firstName);

	if (!query.exec())
		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());

	return query;
}
//
//auto SQLiteDatabase::searchContact(QString const& lastName, QString const& firstName) -> QSqlQuery
//{
//	QSqlQuery query = QueriesManager::createSearchPersonQuery(lastName, firstName);
//	
//	if (!query.exec())
//		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());
//
//	return query;
//}

auto SQLiteDatabase::updateContact(LastName const & lastName, FirstName const & firstName, PhoneNumber const & phoneNumber, ContactId const& id) -> void
{
	QSqlQuery query = QueriesManager::createUpdatePersonQuery(lastName, firstName, phoneNumber, id);

	if (!query.exec())
		throw CouldNotUpdateContactException(query.lastError().text().toStdString());
}

//auto SQLiteDatabase::updateContact(QString const & lastName, QString const & firstName, QString const & phoneNumber, int const id) -> void
//{
//	QSqlQuery query = QueriesManager::createUpdatePersonQuery(lastName, firstName, phoneNumber, id);
//
//	if (!query.exec())
//		throw CouldNotUpdateContactException(query.lastError().text().toStdString());
//}

auto SQLiteDatabase::deleteContact(ContactId const& id) -> void
{
	QSqlQuery query = QueriesManager::createDeletePersonQuery(id);
	
	if (!query.exec())
		throw CouldNotDeleteContactException(query.lastError().text().toStdString());
}

auto SQLiteDatabase::retrieveContactData(ContactId const& id) -> Contact
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(id);

	if (!query.exec())
		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());
	else
	{
		while (query.next())
		{
			LastName lastName = query.value(0).toString().toStdString();
			FirstName firstName = query.value(1).toString().toStdString();
			PhoneNumber phoneNumber = query.value(2).toString().toStdString();
		
			return Contact(lastName, firstName, phoneNumber);
		}

		return Contact();
	}

	return Contact();
}
