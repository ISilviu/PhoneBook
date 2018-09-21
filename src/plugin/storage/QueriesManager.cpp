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

	query.addBindValue(lastName.get());
	query.addBindValue(firstName.get());
	query.addBindValue(phoneNumber.get());

	return query;
}

//auto QueriesManager::createAddPersonQuery(QString const& lastName, QString const& firstName, QString const& phoneNumber) noexcept -> QSqlQuery
//{
//	static QString const addPersonTemplate{ "INSERT INTO contacts (lastname, firstname, phonenumber) VALUES (?,?,?);" };
//	QSqlQuery query;
//
//	query.prepare(addPersonTemplate);
//
//	query.addBindValue(lastName);
//	query.addBindValue(firstName);
//	query.addBindValue(phoneNumber);
//
//	return query;
//}

auto QueriesManager::createSearchPersonQuery(LastName const& lastName, FirstName const& firstName) noexcept -> QSqlQuery
{
	static QString const searchPersonTemplate{ "SELECT * FROM contacts WHERE lastname = ? AND firstname = ?" };
	QSqlQuery query;

	query.prepare(searchPersonTemplate);
	query.addBindValue(lastName.get());
	query.addBindValue(firstName.get());

	return query;
}

//auto QueriesManager::createSearchPersonQuery(QString const& lastName, QString const& firstName) noexcept->QSqlQuery
//{
//	static QString const searchPersonTemplate{ "SELECT * FROM contacts WHERE lastname = ? AND firstname = ?" };
//	QSqlQuery query;
//
//	query.prepare(searchPersonTemplate);
//	query.addBindValue(lastName);
//	query.addBindValue(firstName);
//
//	return query;
//}

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
	query.addBindValue(lastName.get());
	query.addBindValue(firstName.get());
	query.addBindValue(phoneNumber.get());
	query.addBindValue(id.get());

	return query;
}
//
//auto QueriesManager::createUpdatePersonQuery(QString const & lastName, QString const & firstName, QString const & phoneNumber, int const row) noexcept -> QSqlQuery
//{
//	static QString const updatePersonTemplate{ "UPDATE contacts SET lastname = ?, firstname = ?, phonenumber = ? WHERE id = ?" };
//
//	QSqlQuery query;
//	query.prepare(updatePersonTemplate);
//	query.addBindValue(lastName);
//	query.addBindValue(firstName);
//	query.addBindValue(phoneNumber);
//	query.addBindValue(row);
//
//	return query;
//}
