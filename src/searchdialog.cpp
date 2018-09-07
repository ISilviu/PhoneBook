#include "searchdialog.h"

SearchDialog::SearchDialog(QWidget *parent)
	: QDialog(parent)
{
	setupUi(this);
}

void SearchDialog::on_searchButton_clicked()
{
	accept();
}

void SearchDialog::on_cancelButton_clicked()
{
	close();
}

