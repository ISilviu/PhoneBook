#include "UiPlugin.h"
#include "Exceptions.h"

UiPlugin::UiPlugin(int argc, char* argv[], QWidget* parent)
	: _application(argc, argv),
	_widget(parent)
{
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

std::vector<std::string> UiPlugin::getDependencies() const
{
	return _dependencies;
}

auto UiPlugin::checkForNonMatchingDependencies(std::vector<IPlugin*> const & dependencies) const -> void
{
	for (auto index = 0; index < _dependencies.size(); ++index)
	{
		if (typeid(dependencies[index]).name() != typeid(_dependencies[index]).name());
			//throw NonMatchingDependencyTypeException("Needed plugin not found.");
	}
}

void UiPlugin::init(std::vector<IPlugin*> const& dependencies)
{
	checkForNonMatchingDependencies(dependencies);

	auto storagePlugin = dynamic_cast<InMemorySQLiteStoragePlugin*>(dependencies.front());

	_readModel = storagePlugin->getReadModel();

	_widget.init(_readModel);
}
