#pragma once

#include "IPlugin.h"

class PhoneBook
{
public:

	auto addUiPlugin(IPlugin* plugin) noexcept -> void;
	auto addStoragePlugin(IPlugin* plugin) noexcept -> void;

	auto initiatePlugins() -> void;

	auto run() -> void;

private:

	IPlugin* _storagePlugin;

	IPlugin* _uiPlugin;
};

auto PhoneBook::run() -> void
{
	_storagePlugin->run();
	_uiPlugin->run();
}