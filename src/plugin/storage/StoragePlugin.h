#pragma once

#include "IPlugin.h"
#include "ContactsSQLiteRepository.h"

#include <memory>

class StoragePlugin : public IPlugin
{
public:

	void init() override;

	int run() override;

	void shutDown() override;

	IRepository<Contact>* getReadModel() noexcept;

private:

	void init(std::vector<IPlugin*> const& dependencies) override {};

	ContactsSQLiteRepository _repository;
};