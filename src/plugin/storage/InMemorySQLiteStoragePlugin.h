#pragma once

#include <qsqlquerymodel.h>

#include  "IPlugin.h"
#include "InMemorySQLiteDatabase.h"
#include "Dependency.h"

#include <array>

constexpr auto defaultStorageDependencies = std::array<Dependency, 1> {Dependency::UI_PLUGIN};

class InMemorySQLiteStoragePlugin : public IPlugin
{
public:

	std::vector<Dependency> getDependencies() const;

	void init(std::vector<Dependency> const& dependencies) override;

	void run() override;

	void shutDown() override;

	InMemorySQLiteDatabase _database;

private:
	QSqlQueryModel* _model;

	const std::vector<Dependency> _dependencies{ defaultStorageDependencies.cbegin(), defaultStorageDependencies.cend() };
};

