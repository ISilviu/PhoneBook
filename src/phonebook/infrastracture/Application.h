#pragma once

#include "IPluginSpecification.h"
#include "IPlugin.h"

#include <unordered_map>

class Application
{
public:
	Application() = default;

	Application(Application const& other) = delete;
	Application& operator = (Application const& other) = delete;
	Application(Application&& other) = delete;
	Application& operator = (Application&& other) = delete;

	auto addPluginSpecification(IPluginSpecification* specification) noexcept -> void;

	auto run()->int;

	~Application();

private:
	auto scanForNeededSpecifications() noexcept -> void;

	auto instantiatePlugins(std::vector<int> const& topologicallySorted)-> void;

	auto runPlugins(std::vector<int> const& topologicallySorted) -> void;

	std::vector<std::pair<int, int>> _dependencies;

	std::unordered_map<int, IPlugin*> _plugins;

	std::vector<IPluginSpecification*> _specifications;
};

