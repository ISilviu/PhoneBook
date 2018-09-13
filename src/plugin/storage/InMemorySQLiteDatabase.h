#pragma once

#include "SQLiteDatabase.h"

class InMemorySQLiteDatabase : public SQLiteDatabase
{
public:
	InMemorySQLiteDatabase();
	void prepareForUsage();

	void createDatabaseFile(QString const& name) override;

	void createDatabaseFile(std::string const& name) override;
};

