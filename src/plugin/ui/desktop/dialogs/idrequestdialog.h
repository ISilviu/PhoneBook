#pragma once

#include <QDialog>
#include "ui_idrequestdialog.h"

class IdRequestDialog : public QDialog, public Ui::IdRequestDialog
{
	Q_OBJECT

public:
	IdRequestDialog(QWidget *parent = Q_NULLPTR);
	~IdRequestDialog();

private slots:
	void on_okButton_clicked();
	void on_cancelButton_clicked();
};
