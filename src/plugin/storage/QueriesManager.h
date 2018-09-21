#pragma once

#include <qsqlquery.h>
#include <qstring.h>
#include <qvariant.h>

#include "LastName.h"
#include "FirstName.h"
#include "PhoneNumber.h"
#include "ContactId.h"

class QueriesManager
{
public:
	static auto createDefaultUpdateViewQuery() noexcept->QSqlQuery;

	static auto createAddPersonQuery(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) noexcept->QSqlQuery;
	
	//static auto createAddPersonQuery(LastName const& lastName, QString const& firstName, QString const& phoneNumber) noexcept -> QSqlQuery;

	static auto createSearchPersonQuery(LastName const& lastName, FirstName const& firstName) noexcept->QSqlQuery;
	
//	static auto createSearchPersonQuery(LastName const& lastName, QString const& firstName) noexcept -> QSqlQuery;
	
	static auto createSearchPersonQuery(ContactId const& id) noexcept->QSqlQuery;

	static auto createDeletePersonQuery(ContactId const& id) noexcept -> QSqlQuery;

	static auto createUpdatePersonQuery(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber, ContactId const& id) noexcept->QSqlQuery;
	
	//static auto createUpdatePersonQuery(LastName const& lastName, QString const& firstName, QString const& phoneNumber, ) noexcept -> QSqlQuery;

	static constexpr int NotFoundContactFlag{ -1 };
};


