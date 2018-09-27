#include "Application.h"

#include <typeinfo>

#include "Graph.h"

auto Application::addPluginSpecification(IPluginSpecification * specification) noexcept -> void
{
	_specifications.push_back(specification);
}

auto Application::run() -> int
{
	scanForNeededSpecifications();

	Graph graph(_plugins.size(), _dependencies.begin(), _dependencies.end());
	auto const topologicallySorted = graph.topologicalSort();

	instantiatePlugins(topologicallySorted);
	
	runPlugins(topologicallySorted);

	return 1;
}

Application::~Application()
{
	std::for_each(_plugins.begin(), _plugins.end(),
		[this](auto& pair) {delete pair.second; });
}

auto Application::scanForNeededSpecifications() noexcept -> void
{
	for (auto index = 0; index < _specifications.size(); ++index)
	{
		auto currentDependencies = _specifications[index]->getDependencies();
		if (!currentDependencies.empty())
		{
			for (auto index1 = 0; index1 < _specifications.size(); ++index1)
			{
				for (auto const& dependency : currentDependencies)
				{
					if (dependency == typeid(*_specifications[index1]).name())
						_dependencies.push_back(std::make_pair(index, index1));
				}
			}
		}
	}
}

auto Application::instantiatePlugins(std::vector<int> const& topologicallySorted) -> void
{
	for (auto const& pluginSpecificationIndex : topologicallySorted)
	{
		std::vector<IPlugin*> dependenciesSupplier;
		for (auto const&[index1, index2] : _dependencies)
		{
			if (pluginSpecificationIndex == index1)
				dependenciesSupplier.push_back(_plugins[index2]);
		}

		if (dependenciesSupplier.empty())
			_plugins[pluginSpecificationIndex] = _specifications[pluginSpecificationIndex]->create();
		else
			_plugins[pluginSpecificationIndex] = _specifications[pluginSpecificationIndex]->create(dependenciesSupplier);
	}
}

auto Application::runPlugins(std::vector<int> const & topologicallySorted) -> void
{
	std::for_each(topologicallySorted.cbegin(), topologicallySorted.cend(),
		[this](auto const& index) {_plugins[index]->run(); });
}

