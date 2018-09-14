#include "InMemorySQLiteStoragePlugin.h"

std::vector<IPlugin*> InMemorySQLiteStoragePlugin::getDependencies() const
{
	return _dependencies;
}

void InMemorySQLiteStoragePlugin::init()
{
	static std::string const name{ ":memory:" };

	_database.createDatabaseFile(name);
	_database.open();

	_model = new QSqlQueryModel();
}

void InMemorySQLiteStoragePlugin::run()
{
	_database.createMainTable();
}

void InMemorySQLiteStoragePlugin::shutDown()
{
	_database.close();
}

auto InMemorySQLiteStoragePlugin::getModel() const noexcept -> QSqlQueryModel *
{
	return _model;
}

auto InMemorySQLiteStoragePlugin::updateView() noexcept -> void
{
	static QString const query{ "SELECT * FROM contacts" };
	_model->setQuery(query);

}
