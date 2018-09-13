#include "QtUiPlugin.h"

std::vector<Dependency> QtUiPlugin::getDependencies() const
{
	return _dependencies;
}

void QtUiPlugin::init()
{
	QtUiPlugin();
}

QtUiPlugin::QtUiPlugin(QWidget* parent)
	: QWidget(parent)
{
	_dependencies.assign(defaultUiDependencies.cbegin(), defaultUiDependencies.cend());

	ui.setupUi(this);

	_model = new QSqlQueryModel(this);
}

auto QtUiPlugin::updateView() noexcept -> void
{
	static QString const query{ "SELECT * FROM contacts" };
	_model->setQuery(query);
}

void QtUiPlugin::run()
{
	show();
}

void QtUiPlugin::shutDown()
{
	hide();
}

auto PhoneBook::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty() && !phoneNumber.isEmpty());
}

auto PhoneBook::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept ->bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty());
}

auto PhoneBook::hasAnyLineEditFieldChanged(AddDialog const & dialog) const noexcept -> bool
{
	return (dialog.lastNameEdit->isModified() || dialog.firstNameEdit->isModified() || dialog.phoneNumberEdit->isModified());
}