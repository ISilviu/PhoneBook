#include "InMemorySQLiteStoragePlugin.h"

std::vector<Dependency> InMemorySQLiteStoragePlugin::getDependencies() const
{
	return _dependencies;
}

void InMemorySQLiteStoragePlugin::init(std::vector<Dependency> const& dependencies)
{
	static std::string const name{ ":memory:" };

	_database.createDatabaseFile(name);
	_database.open();
}

void InMemorySQLiteStoragePlugin::run()
{
	_database.createMainTable();
}

void InMemorySQLiteStoragePlugin::shutDown()
{
	_database.close();
}
