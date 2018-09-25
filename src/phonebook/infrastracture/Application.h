#pragma once

#include "IPlugin.h"

class Application
{
public:
	auto addPlugin(IPlugin* plugin) noexcept -> void;

	auto run()->int;

private:
	auto scanForNeededDependencies() noexcept->void;

	auto initiatePlugins(std::vector<int> const& topologicallySorted)-> void;

	auto runPlugins(std::vector<int> const& topologicallySorted) -> void;

	std::vector<std::pair<int, int>> _dependencies;

	std::vector<IPlugin*> _plugins;
};

