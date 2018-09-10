#include "InMemorySQLiteDatabase.h"

InMemorySQLiteDatabase::InMemorySQLiteDatabase()
	: SQLiteDatabase()
{}

void InMemorySQLiteDatabase::prepareForUsage()
{
	static QString const name{ ":memory:" };

	createDatabaseFile(name);
	open();
	createMainTable();
}

void InMemorySQLiteDatabase::createDatabaseFile(QString const& name)
{
	static QString const driver{ "QSQLITE" };

	_database = QSqlDatabase::addDatabase(driver);

	_database.setDatabaseName(name);
}
