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

ContactsSQLiteRepository::~ContactsSQLiteRepository()
{
	_database.close();
}

void ContactsSQLiteRepository::add(Contact const & item)
{
	QSqlQuery query = QueriesManager::createAddPersonQuery(LastName(item.lastName())
		, FirstName(item.firstName()), PhoneNumber(item.phoneNumber()));

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
	QSqlQuery query = QueriesManager::createUpdatePersonQuery(LastName(newProperties.lastName())
		, FirstName(newProperties.firstName()), PhoneNumber(newProperties.phoneNumber()), id);

	if (!query.exec())
		throw CouldNotAddContactException(query.lastError().text().toStdString());
}

PhoneBook const ContactsSQLiteRepository::search(Contact const & item)
{
	QSqlQuery query = QueriesManager::createSearchPersonQuery(LastName(item.lastName()), FirstName(item.firstName()));

	if (!query.exec())
		throw CouldNotSearchForTheContactException(query.lastError().text().toStdString());
	else
	{
		PhoneBook phoneBook;

		while (query.next())
		{
			ContactId id = query.value("id").toInt();
			LastName lastName = query.value("lastname").toString().toStdString();
			FirstName firstName = query.value("firstname").toString().toStdString();
			PhoneNumber phoneNumber = query.value("phonenumber").toString().toStdString();

			Contact contact(lastName, firstName, phoneNumber);

			phoneBook.add(id, contact);
		}

		return phoneBook;
	}

	return PhoneBook();
}

PhoneBook const ContactsSQLiteRepository::listAll()
{
	QSqlQuery query = QueriesManager::createDefaultUpdateViewQuery();

	if (!query.exec())
		throw; //to be added
	else
	{
		PhoneBook phoneBook;

		while (query.next())
		{
			ContactId id = query.value("id").toInt();
			LastName lastName = query.value("lastname").toString().toStdString();
			FirstName firstName = query.value("firstname").toString().toStdString();
			PhoneNumber phoneNumber = query.value("phonenumber").toString().toStdString();

			Contact contact(lastName, firstName, phoneNumber);

			phoneBook.add(id, contact);
		}

		return phoneBook;
	}

	return PhoneBook();
}

