#pragma once

#include <QWidget>
#include <qsqlquerymodel.h>

#include <array>

#include "ui_phonebook.h"

#include "adddialog.h"

#include "IPlugin.h"
#include "Dependency.h"
#include "InMemorySQLiteStoragePlugin.h"

constexpr auto defaultUiDependencies = std::array<Dependency, 1>{ Dependency::STORAGE_PLUGIN };

class QtUiPlugin : public QWidget, public IPlugin
{
	Q_OBJECT

public:
	explicit QtUiPlugin(QWidget* parent = Q_NULLPTR);

	std::vector<Dependency> getDependencies() const override;

	void init(std::vector<Dependency> const& dependencies) override;

	void run() override;

	void shutDown() override;


private:

	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool;
	
	auto areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept -> bool;
	
	auto hasAnyLineEditFieldChanged(AddDialog const& dialog) const noexcept -> bool;
	
	Ui::PhoneBookClass ui;

	const std::vector<Dependency> _dependencies{ Dependency::STORAGE_PLUGIN };

private slots:
	/*void on_addButton_clicked();
	
	void on_searchButton_clicked();
	
	void on_updateButton_clicked();
	
	void on_deleteButton_clicked();*/
};