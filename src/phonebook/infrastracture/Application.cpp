#include "Application.h"

auto Application::addPlugin(IPlugin* plugin) noexcept -> void
{
	_plugins.push_back(plugin);
}