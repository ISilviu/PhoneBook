#include "InMemorySQLiteStoragePlugin.h"

std::vector<Dependency> InMemorySQLiteStoragePlugin::getDependencies() const
{
	return _dependencies;
}

void InMemorySQLiteStoragePlugin::init()
{
	_database.prepareForUsage();
}

void InMemorySQLiteStoragePlugin::run()
{

}

void InMemorySQLiteStoragePlugin::shutDown()
{
	_database.close();
}
