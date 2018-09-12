#include "idrequestdialog.h"

IdRequestDialog::IdRequestDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

IdRequestDialog::~IdRequestDialog()
{
}


void IdRequestDialog::on_okButton_clicked()
{
	accept();
}

void IdRequestDialog::on_cancelButton_clicked()
{
	close();
}
