#pragma once

#include <qsqlquery.h>
#include <qstring.h>
#include <qvariant.h>

class QueriesManager
{
public:
	static auto createDefaultUpdateViewQuery()->QSqlQuery;


	static auto createAddPersonQuery(std::string const& lastName, std::string const& firstName, std::string const& phoneNumber) noexcept->QSqlQuery;
	static auto createAddPersonQuery(QString const& lastName, QString const& firstName, QString const& phoneNumber) noexcept -> QSqlQuery;

	static auto createSearchPersonQuery(std::string const& lastName, std::string const& firstName) noexcept->QSqlQuery;
	static auto createSearchPersonQuery(QString const& lastName, QString const& firstName) noexcept -> QSqlQuery;
	static auto createSearchPersonQuery(int const id) noexcept->QSqlQuery;

	static auto createDeletePersonQuery(int const id) noexcept -> QSqlQuery;

	static auto createUpdatePersonQuery(std::string const& lastName, std::string const& firstName, std::string const& phoneNumber, int const row) noexcept->QSqlQuery;
	static auto createUpdatePersonQuery(QString const& lastName, QString const& firstName, QString const& phoneNumber, int const row) noexcept -> QSqlQuery;

	static constexpr int NotFoundContactFlag{ -1 };
};


