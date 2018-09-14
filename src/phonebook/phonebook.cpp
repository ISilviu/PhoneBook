#include "phonebook.h"

auto PhoneBook::addPlugin(IPlugin* plugin) noexcept -> void
{
	_plugins.push_back(plugin);
}