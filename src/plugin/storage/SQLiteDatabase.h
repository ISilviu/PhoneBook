#pragma once

#include <qsqldatabase.h>

using ContactData = std::tuple<QString, QString, QString>;

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

	auto addContact(std::string const& lastName, std::string const& firstName, std::string const& phoneNumber) -> void;
	
	auto addContact(QString const& lastName, QString const& firstName, QString const& phoneNumber) -> void;
	
	auto searchContact(std::string const& lastName, std::string const& firstName)->QSqlQuery;
	
	auto searchContact(QString const& lastName, QString const& firstName) -> QSqlQuery;

	auto updateContact(std::string const& lastName, std::string const& firstName, std::string const& phoneNumber, int const id) -> void;

	auto updateContact(QString const& lastName, QString const& firstName, QString const& phoneNumber, int const id) -> void;

	auto deleteContact(int const id) -> void;

	auto retrieveContactData(int const id)->ContactData;

protected:
	QSqlDatabase _database;
};

