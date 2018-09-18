#pragma once

#include <qsqlquerymodel.h>

#include  "IPlugin.h"
#include "InMemorySQLiteDatabase.h"

#include <array>

class InMemorySQLiteStoragePlugin : public IPlugin
{
public:

	//std::vector<IPlugin*> getDependencies() const;

	void init() override;

	int run() override;

	void shutDown() override;

	InMemorySQLiteDatabase _database;

private:
	void init(std::vector<IPlugin*> const& dependencies) override {};
};

