#pragma once

#include <qsqlquery.h>
#include <qstring.h>
#include <qvariant.h>

class QueriesManager
{
public:
	static auto createAddPersonQuery(QString const& lastName, QString const& firstName, QString const& phoneNumber) noexcept -> QSqlQuery;

	static auto createSearchPersonQuery(QString const& lastName, QString const& firstName) noexcept -> QSqlQuery;
	static auto createSearchPersonQuery(int const row) noexcept->QSqlQuery;

	static auto createDeletePersonQuery(int const row) noexcept -> QSqlQuery;

	static auto createUpdatePersonQuery(QString const& lastName, QString const& firstName, QString const& phoneNumber, int const row) noexcept -> QSqlQuery;
};

