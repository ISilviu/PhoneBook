#pragma once

#include <qsqlquerymodel.h>

#include  "IPlugin.h"
#include "InMemorySQLiteDatabase.h"

class InMemorySQLiteStoragePlugin : public IPlugin
{
public:

	void init() override;

	int run() override;

	InMemorySQLiteDatabase const& getReadModel() const noexcept;

	std::vector<std::string> getDependencies() const override;

private:
	void init(std::vector<IPlugin*> const& dependencies) override {};

	InMemorySQLiteDatabase _database;
};

