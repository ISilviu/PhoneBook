#include "UiPluginSpecification.h"

#include "UiPlugin.h"

IPlugin * UiPluginSpecification::create(std::vector<IPlugin*> const & dependencies)
{
	static char *argv[] = { "program name", "arg1", "arg2", nullptr };
	static int argc = sizeof(argv) / sizeof(char*) - 1;

	return new UiPlugin(argc, argv, dependencies);
}

std::vector<std::string> UiPluginSpecification::getDependencies() const noexcept
{
	return _dependencies;
}
