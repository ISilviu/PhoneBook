#pragma once

#include <QWidget>
#include <qapplication.h>

#include "IPlugin.h"
#include "UiMainWidget.h"

class UiPlugin : public IPlugin
{
public:
	UiPlugin(int argc, char* argv[],std::vector<IPlugin*> const& dependencies, QWidget* parent = Q_NULLPTR);

	int run() override;

private:
	//auto checkForNonMatchingDependencies(std::vector<IPlugin*> const& dependencies) const -> void;

	void init(std::vector<IPlugin*> const& dependencies);

	QApplication _application;

	UiMainWidget _widget;

	InMemorySQLiteDatabase _readModel;
};
