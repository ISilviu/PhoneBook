#include "adddialog.h"


AddDialog::AddDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

AddDialog::~AddDialog()
{
}

auto AddDialog::setEditFieldsText(QString const & lastName, QString const & firstName, QString const & phoneNumber) noexcept -> void
{
	lastNameEdit->setText(lastName);
	firstNameEdit->setText(firstName);
	phoneNumberEdit->setText(phoneNumber);
}

void AddDialog::on_okButton_clicked()
{
	accept();
}

void AddDialog::on_cancelButton_clicked()
{
	close();
}
