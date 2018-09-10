#pragma once

#include <qsqldatabase.h>

using ContactData = std::tuple<QString, QString, QString>;

class SQLiteDatabase
{
public:
	SQLiteDatabase() = default;
	virtual ~SQLiteDatabase() = default;

	virtual void createDatabaseFile(QString const& name) = 0;

	auto open() -> void;

	auto createMainTable() -> void;
	
	auto addContact(QString const& lastName, QString const& firstName, QString const& phoneNumber) -> void;
	
	auto searchContact(QString const& lastName, QString const& firstName) -> int;

	auto updateContact(QString const& lastName, QString const& firstName, QString const& phoneNumber, int const id) -> void;

	auto retrieveContactData(int const id)->ContactData;

protected:
	QSqlDatabase _database;
};

