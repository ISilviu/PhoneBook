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

	void init(std::vector<IPlugin*> const& dependencies);

private:

	auto initializeDependencies() noexcept -> void;

	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool;
	
	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept -> bool;
	
	auto hasAnyLineEditFieldChanged(AddDialog const& dialog) const noexcept -> bool;

	Ui::PhoneBookClass ui;

	std::vector<IPlugin*> _dependencies;

	InMemorySQLiteStoragePlugin* _storagePlugin;

private slots:
	void on_addButton_clicked();
	
	void on_searchButton_clicked();
	
	void on_updateButton_clicked();
	
	void on_deleteButton_clicked();
};