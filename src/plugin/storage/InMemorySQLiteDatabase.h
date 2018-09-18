#pragma once

#include "SQLiteDatabase.h"
#include  <qsqlquerymodel.h>

class InMemorySQLiteDatabase : public SQLiteDatabase
{
public:
	InMemorySQLiteDatabase();

	void prepareForUsage();

	void createDatabaseFile(QString const& name) override;

	void createDatabaseFile(std::string const& name) override;

	auto createModel() noexcept->void;

	auto getModel() const noexcept->QSqlQueryModel*;

	auto updateView() noexcept -> void;

private:
	QSqlQueryModel* _model;
};

