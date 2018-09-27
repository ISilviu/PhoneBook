#include "InMemorySQLiteStoragePluginSpecification.h"

InMemorySQLiteStoragePlugin * InMemorySQLiteStoragePluginSpecification::create(std::vector<IPlugin*> const & dependencies)
{
	return new InMemorySQLiteStoragePlugin();
}

std::vector<std::string> InMemorySQLiteStoragePluginSpecification::getDependencies() const noexcept
{
	return _dependencies;
}
