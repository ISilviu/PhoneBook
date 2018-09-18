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

auto InMemorySQLiteDatabase::getModel() const noexcept -> QSqlQueryModel *
{
	return _model;
}

void InMemorySQLiteDatabase::createDatabaseFile(std::string const & name)
{
	static QString const driver{ "QSQLITE" };

	_database = QSqlDatabase::addDatabase(driver);

	_database.setDatabaseName(QString::fromUtf8(name.c_str()));
}

auto InMemorySQLiteDatabase::createModel() noexcept -> void
{
	_model = new QSqlQueryModel();
}

auto InMemorySQLiteDatabase::updateView() noexcept -> void
{
	static QString const query{ "SELECT * FROM contacts" };
	_model->setQuery(query);
}
