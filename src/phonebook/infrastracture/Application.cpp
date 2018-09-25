#include "Application.h"

#include <typeinfo>

#include "Graph.h"

auto Application::addPlugin(IPlugin* plugin) noexcept -> void
{
	_plugins.push_back(plugin); 
}

auto Application::run() -> int
{
	scanForNeededDependencies();

	Graph graph(_plugins.size(), _dependencies.begin(), _dependencies.end());
	auto topologicallySorted = graph.topologicalSort();

	initiatePlugins(topologicallySorted);
	
	runPlugins(topologicallySorted);

	return 1;
}

auto Application::scanForNeededDependencies() noexcept -> void
{
	for (auto index = 0; index < _plugins.size(); ++index)
	{
		std::vector<std::string> currentPluginDependencies = _plugins[index]->getDependencies();
		if (!currentPluginDependencies.empty())
		{
			for (auto index1 = 0; index < _plugins.size(); ++index)
			{
				for (auto const& dependency : currentPluginDependencies)
				{
					if (dependency == typeid(*_plugins[index1]).name())
						_dependencies.push_back(std::make_pair(index, index1));
				}
			}
		}
	}
}

auto Application::initiatePlugins(std::vector<int> const & topologicallySorted) -> void
{
	for (auto currentPluginIndex = 0; currentPluginIndex < topologicallySorted.size(); ++currentPluginIndex)
	{
		std::vector<IPlugin*> dependenciesSupplier;

		for (auto const&[pluginIndex, dependencyIndex] : _dependencies)
		{
			if (currentPluginIndex == pluginIndex)
				dependenciesSupplier.push_back(_plugins[dependencyIndex]);
		}

		if (dependenciesSupplier.empty())
			_plugins[currentPluginIndex]->init();
		else
			_plugins[currentPluginIndex]->init(dependenciesSupplier);
	}
}

auto Application::runPlugins(std::vector<int> const & topologicallySorted) -> void
{
	std::for_each(topologicallySorted.cbegin(), topologicallySorted.cend(),
		[this](auto const& index) {_plugins[index]->run(); });
}

