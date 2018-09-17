#include "UiPlugin.h"
#include "Exceptions.h"

UiPlugin::UiPlugin(int argc, char* argv[], QWidget* parent)
	: _application(argc, argv),
	_widget(parent)
{}

void UiPlugin::init(std::vector<IPlugin*> const& dependencies)
{
	_widget.init(dependencies);
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

void UiPlugin::shutDown()
{
	_widget.hide();
}

