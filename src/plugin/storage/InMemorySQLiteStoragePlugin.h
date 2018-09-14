#pragma once

#include <qsqlquerymodel.h>

#include  "IPlugin.h"
#include "InMemorySQLiteDatabase.h"

#include <array>

class InMemorySQLiteStoragePlugin : public IPlugin
{
public:

	std::vector<IPlugin*> getDependencies() const;

	void init() override;

	void run() override;

	void shutDown() override;

	InMemorySQLiteDatabase _database;

	auto getModel() const noexcept->QSqlQueryModel*;

	auto updateView() noexcept -> void;

private:
	void init(std::vector<IPlugin*> const& dependencies) override {};

	QSqlQueryModel* _model;

	std::vector<IPlugin*> _dependencies;
};

