#pragma once

#include "IRepository.h"

#include "Contact.h"

#include "PhoneBook.h"

#include <qsqldatabase.h>

#include <qsqlquerymodel.h>

class ContactsSQLiteRepository : public IRepository<Contact, PhoneBook>
{
public:
	ContactsSQLiteRepository();

	~ContactsSQLiteRepository();

	void add(Contact const& item) override;

	void remove(int const id) override;

	void update(Contact const& newProperties, int const id) override;

	PhoneBook const search(Contact const& item) override;

	PhoneBook const listAll() override;

private:

	void addDriver(QString const& driver);

	void addName(QString const& name);

	void open();

	void createMainTable();

	QSqlDatabase _database;

	QSqlQueryModel* _model; 
};

