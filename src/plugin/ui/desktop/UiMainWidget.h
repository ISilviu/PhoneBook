#pragma once

#include <QWidget>

#include "ui_phonebook.h"

#include "adddialog.h"

#include "InMemorySQLiteStoragePlugin.h"

#include "LastName.h"
#include "FirstName.h"
#include "PhoneNumber.h"

class UiMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit UiMainWidget(QWidget* parent = Q_NULLPTR);

	void init(InMemorySQLiteDatabase const& readModel);

private:

	auto areAllLineEditFieldsFilled(LastName const& lastName, FirstName const& firstName, PhoneNumber const& phoneNumber) const noexcept -> bool;
	
	auto areAllLineEditFieldsFilled(LastName const& lastName, FirstName const& firstName) const noexcept -> bool;
	
	auto hasAnyLineEditFieldChanged(AddDialog const& dialog) const noexcept -> bool;

	InMemorySQLiteDatabase _readModel;
	
	Ui::PhoneBookClass ui;

private slots:
	void on_addButton_clicked();
	
	void on_searchButton_clicked();
	
	void on_updateButton_clicked();
	
	void on_deleteButton_clicked();
};