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
	auto checkForNonMatchingDependencies(std::vector<IPlugin*> const& dependencies) const -> void;

	auto initializeDependencies() noexcept -> void;

	void init() override {};

	std::vector<IPlugin*> _dependencies;

	InMemorySQLiteDatabase _readModel;

	QApplication _application;

	UiMainWidget _widget;
};
