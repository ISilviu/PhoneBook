#include "QueriesManager.h"

auto QueriesManager::createAddPersonQuery(QString const& lastName, QString const& firstName, QString const& phoneNumber) noexcept -> QSqlQuery
{
	static QString const addPersonTemplate{ "INSERT INTO contacts (lastname, firstname, phonenumber) VALUES (?,?,?);" };
	QSqlQuery query;

	query.prepare(addPersonTemplate);

	query.addBindValue(lastName);
	query.addBindValue(firstName);
	query.addBindValue(phoneNumber);

	return query;
}

auto QueriesManager::createSearchPersonQuery(QString const& lastName, QString const& firstName) noexcept->QSqlQuery
{
	static QString const searchPersonTemplate{ "SELECT id, lastname, firstname, phonenumber FROM contacts WHERE lastname = ? AND firstname = ?" };
	QSqlQuery query;

	query.prepare(searchPersonTemplate);
	query.addBindValue(lastName);
	query.addBindValue(firstName);

	return query;
}

auto QueriesManager::createSearchPersonQuery(int const row) noexcept -> QSqlQuery
{
	static QString const searchPersonTemplate{ "SELECT lastname, firstname, phonenumber FROM contacts WHERE id = ?" };

	QSqlQuery query;
	query.prepare(searchPersonTemplate);
	query.addBindValue(row);

	return query;
}

auto QueriesManager::createDeletePersonQuery(int const row) noexcept -> QSqlQuery
{
	static QString const deletePersonTemplate{ "DELETE FROM contacts WHERE id = ?" };

	QSqlQuery query;
	query.prepare(deletePersonTemplate);
	query.addBindValue(row);

	return query;
}

auto QueriesManager::createUpdatePersonQuery(QString const & lastName, QString const & firstName, QString const & phoneNumber, int const row) noexcept -> QSqlQuery
{
	static QString const updatePersonTemplate{ "UPDATE contacts SET lastname = ?, firstname = ?, phonenumber = ? WHERE id = ?" };

	QSqlQuery query;
	query.prepare(updatePersonTemplate);
	query.addBindValue(lastName);
	query.addBindValue(firstName);
	query.addBindValue(phoneNumber);
	query.addBindValue(row);

	return query;
}
