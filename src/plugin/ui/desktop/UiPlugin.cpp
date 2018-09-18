#include "UiPlugin.h"
#include "Exceptions.h"

UiPlugin::UiPlugin(int argc, char* argv[], QWidget* parent)
	: _application(argc, argv),
	_widget(parent)
{
	initializeDependencies();
}

int UiPlugin::run()
{
	constexpr int notRunningReturnValue{ 1 };
	try
	{
		_widget.show();

		return _application.exec();
	}
	catch (NonMatchingDependencyTypeException const& e)
	{
		return notRunningReturnValue;
	}
}

auto UiPlugin::checkForNonMatchingDependencies(std::vector<IPlugin*> const & dependencies) const -> void
{
	for (auto index = 0; index < _dependencies.size(); ++index)
	{
		if (typeid(dependencies[index]) != typeid(_dependencies[index]))
			throw NonMatchingDependencyTypeException("Needed plugin not found.");
	}
}

auto UiPlugin::initializeDependencies() noexcept -> void
{
	InMemorySQLiteStoragePlugin storagePlugin;

	_dependencies.push_back(&storagePlugin);
}

void UiPlugin::shutDown()
{
	_widget.hide();
}

void UiPlugin::init(std::vector<IPlugin*> const& dependencies)
{
	checkForNonMatchingDependencies(dependencies);

	auto storagePlugin = dynamic_cast<InMemorySQLiteStoragePlugin*>(dependencies.front());

	_readModel = storagePlugin->_database;

	_widget.init(_readModel);
}
