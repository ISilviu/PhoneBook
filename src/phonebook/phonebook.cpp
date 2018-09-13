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
	_storagePlugin->init(_uiPlugin->getDependencies());
	_uiPlugin->init(_storagePlugin->getDependencies());
}

auto PhoneBook::run() -> void
{
	_storagePlugin->run();
	_uiPlugin->run();
}