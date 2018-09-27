#include "UiPlugin.h"

#include "UiPluginSpecificExceptions.h"

UiPlugin::UiPlugin(int argc, char * argv[], std::vector<IPlugin*> const & dependencies, QWidget * parent)
	: _application(argc, argv),
	_widget(parent)
{
	init(dependencies);
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

void UiPlugin::init(std::vector<IPlugin*> const& dependencies)
{
	//checkForNonMatchingDependencies(dependencies);

	auto storagePlugin = dynamic_cast<InMemorySQLiteStoragePlugin*>(dependencies.front());

	_readModel = storagePlugin->getReadModel();

	_widget.init(_readModel);
}
