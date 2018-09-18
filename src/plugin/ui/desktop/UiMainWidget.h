#pragma once

#include <QWidget>
#include <qsqlquerymodel.h>

#include "ui_phonebook.h"

#include "adddialog.h"

#include "IPlugin.h"

#include "InMemorySQLiteStoragePlugin.h"

class UiMainWidget : public QWidget
{
	Q_OBJECT

public:
	explicit UiMainWidget(QWidget* parent = Q_NULLPTR);

	void init(InMemorySQLiteDatabase& readModel);

private:

	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool;
	
	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept -> bool;
	
	auto hasAnyLineEditFieldChanged(AddDialog const& dialog) const noexcept -> bool;

	InMemorySQLiteDatabase _readModel;
	
	Ui::PhoneBookClass ui;

private slots:
	void on_addButton_clicked();
	
	void on_searchButton_clicked();
	
	void on_updateButton_clicked();
	
	void on_deleteButton_clicked();
};