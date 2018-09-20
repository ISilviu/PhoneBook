#include "ContactsSQLiteRepository.h"

#include <qsqlquery.h>
#include <qsqlerror.h>

#include "QueriesManager.h"

#include "Exceptions.h"

void ContactsSQLiteRepository::addDriver(QString const & driver)
{
	_database = QSqlDatabase::addDatabase(driver);
}

void ContactsSQLiteRepository::addName(QString const & name)
{
	_database.setDatabaseName(name);
}

void ContactsSQLiteRepository::open()
{
	if (!_database.open())
		throw CouldNotOpenDatabaseException("The SQLite database couldn't be opened.");
}

void ContactsSQLiteRepository::createMainTable()
{
	static QString const createTableTemplate{ "CREATE TABLE contacts (id INTEGER PRIMARY KEY AUTOINCREMENT, lastname TEXT, firstname TEXT, phonenumber TEXT);" };
	QSqlQuery query;

	if (!query.exec(createTableTemplate))
		throw CouldNotCreateDatabaseTableException(query.lastError().text().toStdString());
}


ContactsSQLiteRepository::ContactsSQLiteRepository()
{
	static QString const driver{ "QSQLITE" };
	static QString const name{ ":memory:" };
	
	addDriver(driver);
	addName(name);
	open();
	createMainTable();
}

void ContactsSQLiteRepository::add(Contact const & item)
{
	QSqlQuery query = QueriesManager::createAddPersonQuery(item.lastName(), item.firstName(), item.phoneNumber());

	if (!query.exec())
		throw CouldNotAddContactException(query.lastError().text().toStdString());
}

void ContactsSQLiteRepository::remove(int const id)
{
	QSqlQuery query = QueriesManager::createDeletePersonQuery(id);

	if (!query.exec())
		throw CouldNotAddContactException(query.lastError().text().toStdString());
}

void ContactsSQLiteRepository::update(Contact const & newProperties, int const id)
{
	QSqlQuery query = QueriesManager::createUpdatePersonQuery(newProperties.lastName(), newProperties.firstName(), newProperties.phoneNumber(), id);

	if (!query.exec())
		throw CouldNotAddContactException(query.lastError().text().toStdString());
}

std::vector<Contact> ContactsSQLiteRepository::search(Contact const & item)
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(
		item.lastName(), item.firstName());

	if (!query.exec())
		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());
	else
	{
		std::vector<Contact> contacts;

		QString lastName;
		QString firstName;
		QString phoneNumber;

		while (query.next())
		{
			lastName = query.value("lastname").toString();
			firstName = query.value("firstname").toString();
			phoneNumber = query.value("phonenumber").toString();

			Contact contact(lastName, firstName, phoneNumber);

			contacts.push_back(contact);
		}

		return contacts;
	}

	return std::vector<Contact>();
}

std::vector<Contact> ContactsSQLiteRepository::listAll()
{
	QSqlQuery query = QueriesManager::createDefaultUpdateViewQuery();

	if (!query.exec())
		throw; //to be added
	else
	{
		std::vector<Contact> contacts;

		QString lastName;
		QString firstName;
		QString phoneNumber;

		while (query.next())
		{
			lastName = query.value("lastname").toString();
			firstName = query.value("firstname").toString();
			phoneNumber = query.value("phonenumber").toString();

			Contact contact(lastName, firstName, phoneNumber);

			contacts.push_back(contact);
		}

		return contacts;
	}

	return std::vector<Contact>();
}

