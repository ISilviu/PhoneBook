#include "InMemorySQLiteStoragePlugin.h"

#include "StoragePluginSpecificExceptions.h"

void InMemorySQLiteStoragePlugin::init()
{
	static std::string const name{ ":memory:" };

	_database.createModel();
	_database.createDatabaseFile(name);
	_database.open();
}

InMemorySQLiteStoragePlugin::InMemorySQLiteStoragePlugin()
{
	init();
}

int InMemorySQLiteStoragePlugin::run()
{
	constexpr int isRunningSpecifier{ 1 };
	constexpr int isNotRunningSpecifier{ 0 };
	try
	{
		_database.createMainTable();
		return isRunningSpecifier;
	}
	catch (CouldNotOpenDatabaseException const& e)
	{
		return isNotRunningSpecifier;
	}
	catch (CouldNotCreateDatabaseTableException const& e)
	{
		return isNotRunningSpecifier;
	}
}

InMemorySQLiteDatabase const & InMemorySQLiteStoragePlugin::getReadModel() const noexcept
{
	return _database;
}

