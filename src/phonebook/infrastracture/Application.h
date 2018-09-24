#pragma once

#include "IPlugin.h"

class Application
{
public:
	auto addPlugin(IPlugin* plugin) noexcept -> void;

private:
	std::vector<IPlugin*> _plugins;
};

