#include "QueriesManager.h"

auto QueriesManager::createDefaultUpdateViewQuery() noexcept -> QSqlQuery
{
	static QString const defaultUpdateViewTemplate{ "SELECT * FROM contacts" };
	QSqlQuery query;

	query.prepare(defaultUpdateViewTemplate);
	return query;
}


auto QueriesManager::createAddPersonQuery(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) noexcept -> QSqlQuery
{
	static QString const addPersonTemplate{ "INSERT INTO contacts (lastname, firstname, phonenumber) VALUES (?,?,?);" };
	QSqlQuery query;

	query.prepare(addPersonTemplate);

	const std::string string{ "Das" };

	query.addBindValue(QString::fromUtf8(lastName.get().c_str()));
	query.addBindValue(QString::fromUtf8(firstName.get().c_str()));
	query.addBindValue(QString::fromUtf8(phoneNumber.get().c_str()));

	return query;
}

auto QueriesManager::createSearchPersonQuery(LastName const& lastName, FirstName const& firstName) noexcept -> QSqlQuery
{
	static QString const searchPersonTemplate{ "SELECT * FROM contacts WHERE lastname = ? AND firstname = ?" };
	QSqlQuery query;

	query.prepare(searchPersonTemplate);
	query.addBindValue(QString::fromUtf8(lastName.get().c_str()));
	query.addBindValue(QString::fromUtf8(firstName.get().c_str()));

	return query;
}

auto QueriesManager::createSearchPersonQuery(ContactId const& id) noexcept -> QSqlQuery
{
	static QString const searchPersonTemplate{ "SELECT lastname, firstname, phonenumber FROM contacts WHERE id = ?" };

	QSqlQuery query;
	query.prepare(searchPersonTemplate);
	query.addBindValue(id.get());

	return query;
}

auto QueriesManager::createDeletePersonQuery(ContactId const& id) noexcept -> QSqlQuery
{
	static QString const deletePersonTemplate{ "DELETE FROM contacts WHERE id = ?" };

	QSqlQuery query;
	query.prepare(deletePersonTemplate);
	query.addBindValue(id.get());

	return query;
}

auto QueriesManager::createUpdatePersonQuery(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber, ContactId const& id) noexcept -> QSqlQuery
{
	static QString const updatePersonTemplate{ "UPDATE contacts SET lastname = ?, firstname = ?, phonenumber = ? WHERE id = ?" };
	QSqlQuery query;
	
	query.prepare(updatePersonTemplate);
	query.addBindValue(QString::fromUtf8(lastName.get().c_str()));
	query.addBindValue(QString::fromUtf8(firstName.get().c_str()));
	query.addBindValue(QString::fromUtf8(phoneNumber.get().c_str()));
	query.addBindValue(id.get());

	return query;
}
