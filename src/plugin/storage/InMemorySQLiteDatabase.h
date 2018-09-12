#pragma once

#include "SQLiteDatabase.h"

class InMemorySQLiteDatabase : public SQLiteDatabase
{
public:
	InMemorySQLiteDatabase();
	void prepareForUsage();
private:
	void createDatabaseFile(QString const& name) override;
};

