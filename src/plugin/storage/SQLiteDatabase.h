#pragma once

#include <qsqldatabase.h>

#include "Contact.h"

#include "LastName.h"
#include "FirstName.h"
#include "PhoneNumber.h"
#include "ContactId.h"

class SQLiteDatabase
{
public:
	SQLiteDatabase() = default;
	virtual ~SQLiteDatabase() = default;

	virtual void createDatabaseFile(QString const& name) = 0;

	virtual void createDatabaseFile(std::string const& name) = 0;

	auto open() -> void;

	auto close() -> void;

	auto createMainTable() -> void;

	auto addContact(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) -> void;
	
	auto searchContact(LastName const& lastName, FirstName const& firstName)->QSqlQuery;

	auto updateContact(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber, ContactId const& id) -> void;

	auto deleteContact(ContactId const& id) -> void;

	auto retrieveContactData(ContactId const& id)->Contact;

protected:
	QSqlDatabase _database;
};

