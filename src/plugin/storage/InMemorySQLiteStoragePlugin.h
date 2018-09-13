#pragma once

#include  "IPlugin.h"
#include "InMemorySQLiteDatabase.h"
#include "Dependency.h"

#include <array>

constexpr auto defaultStorageDependencies = std::array<Dependency, 1> {Dependency::UI_PLUGIN};
virtual std::vector<Dependency> getDependencies() = 0;

virtual void init() = 0;

virtual void run() = 0;

virtual void shutDown() = 0;


class InMemorySQLiteStoragePlugin : public IPlugin
{
public:

	std::vector<Dependency> getDependencies() const;

	void init();

	void run();

	void shutDown();

	InMemorySQLiteDatabase _database;

private:
	std::vector<Dependency> _dependencies;

};

