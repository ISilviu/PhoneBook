#pragma once

#include "IPlugin.h"
#include "ContactsSQLiteRepository.h"

#include <memory>

class StoragePlugin : public IPlugin
{
public:
	StoragePlugin() = default;

	StoragePlugin(StoragePlugin const& other) = delete;

	StoragePlugin(StoragePlugin&& other) = delete;

	StoragePlugin& operator = (StoragePlugin const& other) = delete;

	StoragePlugin& operator = (StoragePlugin&& other) = delete;

	IRepository<Contact, PhoneBook>* getReadModel() noexcept;

private:
	int run() override { return 0; };

	ContactsSQLiteRepository _repository;
};