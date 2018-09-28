#pragma once

#include "IPluginSpecification.h"

#include "InMemorySQLiteStoragePlugin.h"

class InMemorySQLiteStoragePluginSpecification : public IPluginSpecification
{
public:
	IPlugin* create(std::vector<IPlugin*> const& dependencies = std::vector<IPlugin*>()) override;

	std::vector<std::string> getDependencies() const noexcept override;

private:
	std::vector<std::string> _dependencies;
};

