#include "QtUiPlugin.h"

std::vector<Dependency> QtUiPlugin::getDependencies() const
{
	return _dependencies;
}

void QtUiPlugin::init(std::vector<Dependency> const& dependencies)
{
	ui.setupUi(this);
}

QtUiPlugin::QtUiPlugin(QWidget* parent)
	: QWidget(parent)
{}

void QtUiPlugin::run()
{
	show();
}

void QtUiPlugin::shutDown()
{
	hide();
}

auto QtUiPlugin::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName, QString const& phoneNumber) const noexcept -> bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty() && !phoneNumber.isEmpty());
}

auto QtUiPlugin::areAllLineEditFieldsFilled(QString const& lastName, QString const& firstName) const noexcept ->bool
{
	return (!lastName.isEmpty() && !firstName.isEmpty());
}

auto QtUiPlugin::hasAnyLineEditFieldChanged(AddDialog const & dialog) const noexcept -> bool
{
	return (dialog.lastNameEdit->isModified() || dialog.firstNameEdit->isModified() || dialog.phoneNumberEdit->isModified());
}