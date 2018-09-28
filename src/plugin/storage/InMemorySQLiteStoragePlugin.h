#pragma once

#include  "IPlugin.h"
#include "InMemorySQLiteDatabase.h"

class InMemorySQLiteStoragePlugin : public IPlugin
{
public:
	InMemorySQLiteStoragePlugin();

	int run() override;

	InMemorySQLiteDatabase const& getReadModel() const noexcept;

private:
	void init();

	InMemorySQLiteDatabase _database;
};

