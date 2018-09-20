#pragma once

#include "IRepository.h"

#include "Contact.h"

#include <qsqlquerymodel.h>
#include <qsqldatabase.h>

class ContactsSQLiteRepository : public IRepository<Contact>
{
public:
	ContactsSQLiteRepository();

	void add(Contact const& item) override;

	void remove(int const id) override;

	void update(Contact const& newProperties, int const id) override;

	std::vector<Contact> search(Contact const& item) override;

	std::vector<Contact> listAll() override;

private:

	void addDriver(QString const& driver);

	void addName(QString const& name);

	void open();

	void createMainTable();

	QSqlDatabase _database;

	QSqlQueryModel* _model; 
};

