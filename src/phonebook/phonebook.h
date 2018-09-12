#pragma once

#include <QtWidgets/QWidget>
#include <qsqlquerymodel.h>
#include "InMemorySQLiteDatabase.h"

#include "ui_phonebook.h"

class AddDialog;

using ContactData = std::tuple<QString, QString, QString>;

class PhoneBook : public QWidget
{
	Q_OBJECT

public:
	PhoneBook(QWidget *parent = Q_NULLPTR);

	auto prepareDatabaseForUsage() -> void;

private:
	auto connectViewAndModel() noexcept -> void;
	auto updateView() noexcept -> void;

	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool;
	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept -> bool;
	auto hasAnyLineEditFieldChanged(AddDialog const& dialog) const noexcept -> bool;

	Ui::PhoneBookClass ui;

	InMemorySQLiteDatabase _database;

	QSqlQueryModel* _model;

private slots:
	void on_addButton_clicked();
	void on_searchButton_clicked();
	void on_updateButton_clicked();
	void on_deleteButton_clicked();
};





