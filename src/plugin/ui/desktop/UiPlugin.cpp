#include "UiPlugin.h"

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
	_widget.show();

	return _application.exec();
}

void UiPlugin::shutDown()
{
	_widget.hide();
}

