#pragma once

#include <QtWidgets/QWidget>
#include <qsqldatabase.h>

#include "ui_phonebook.h"

class AddDialog;

using PersonData = std::tuple<QString, QString, QString>;

class PhoneBook : public QWidget
{
	Q_OBJECT

public:
	PhoneBook(QWidget *parent = Q_NULLPTR);

private:
	auto createDatabaseMainTable() -> void;
	auto createDatabaseFile() -> void;
	auto prepareDatabaseForUsage() -> void;

	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool;
	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept -> bool;
	auto hasAnyLineEditFieldChanged(AddDialog const& dialog) const noexcept -> bool;

	auto retrievePersonData(int const row) noexcept -> PersonData;

	Ui::PhoneBookClass ui;

	QSqlDatabase _database;

private slots:
	void on_addButton_clicked();
	void on_searchButton_clicked();
	void on_updateButton_clicked();
	//void on_deleteButton_clicked();
};





