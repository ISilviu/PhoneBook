#pragma once

#include <QWidget>
#include <qapplication.h>

#include "IPlugin.h"
#include "UiMainWidget.h"

class UiPlugin : public IPlugin
{
public:
	UiPlugin(int argc, char* argv[], QWidget* parent = Q_NULLPTR);

	void init(std::vector<IPlugin*> const& dependencies) override;

	int run() override;

	void shutDown() override;

private:
	void init() override {};

	QApplication _application;

	UiMainWidget _widget;
};
