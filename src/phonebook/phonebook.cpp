#include "phonebook.h"

auto PhoneBook::addUiPlugin(IPlugin * plugin) noexcept -> void
{
	_uiPlugin = plugin;
}

auto PhoneBook::addStoragePlugin(IPlugin* plugin) noexcept -> void
{
	_storagePlugin = plugin;
}

auto PhoneBook::initiatePlugins() -> void
{
	_uiPlugin->init();
	_storagePlugin->init();
}
