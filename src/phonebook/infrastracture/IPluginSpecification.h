#pragma once

#include <vector>

#include "IPlugin.h"

class IPluginSpecification
{
public:
	virtual ~IPluginSpecification() = default;

	virtual IPlugin* create(std::vector<IPlugin*> const& dependencies = std::vector<IPlugin*>()) = 0;

	virtual std::vector<std::string> getDependencies() const noexcept = 0;
};

