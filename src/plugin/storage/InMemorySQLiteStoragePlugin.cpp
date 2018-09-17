#include "InMemorySQLiteStoragePlugin.h"
#include "Exceptions.h"

//std::vector<IPlugin*> InMemorySQLiteStoragePlugin::getDependencies() const
//{
//	return _dependencies;
//}

void InMemorySQLiteStoragePlugin::init()
{
	static std::string const name{ ":memory:" };

	_database.createDatabaseFile(name);
	_database.open();

	_model = new QSqlQueryModel();
}

int InMemorySQLiteStoragePlugin::run()
{
	constexpr int isRunningSpecifier{ 1 };
	constexpr int isNotRunningSpecifier{ 0 };
	try
	{
		_database.createMainTable();
		return 1;
	}
	catch (CouldNotOpenDatabaseException const& e)
	{
		return 0;
	}
	catch (CouldNotCreateDatabaseTableException const& e)
	{
		return 0;
	}
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
