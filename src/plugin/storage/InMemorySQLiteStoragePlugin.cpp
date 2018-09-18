#include "InMemorySQLiteStoragePlugin.h"
#include "Exceptions.h"

//std::vector<IPlugin*> InMemorySQLiteStoragePlugin::getDependencies() const
//{
//	return _dependencies;
//}

void InMemorySQLiteStoragePlugin::init()
{
	static std::string const name{ ":memory:" };

	_database.createModel();
	_database.createDatabaseFile(name);
	_database.open();
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

void InMemorySQLiteStoragePlugin::shutDown()
{
	_database.close();
}


