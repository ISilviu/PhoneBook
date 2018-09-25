#pragma once

#include <QWidget>
#include <qapplication.h>

#include "IPlugin.h"
#include "UiMainWidget.h"

#include <array>

namespace
{
	inline constexpr auto dependencies = std::array
	{
		std::string_view{"class InMemorySQLiteStoragePlugin"}
	};
};

class UiPlugin : public IPlugin
{
public:
	UiPlugin(int argc, char* argv[], QWidget* parent = Q_NULLPTR);

	void init(std::vector<IPlugin*> const& dependencies) override;

	int run() override;

	std::vector<std::string> getDependencies() const override;

private:
	auto checkForNonMatchingDependencies(std::vector<IPlugin*> const& dependencies) const -> void;

	void init() override {};

	QApplication _application;

	UiMainWidget _widget;

	InMemorySQLiteDatabase _readModel;

	const std::vector<std::string> _dependencies{ dependencies.cbegin(), dependencies.cend() };
};
