#pragma once

#include <QDialog>
#include "ui_adddialog.h"

class AddDialog : public QDialog, public Ui::AddDialog
{
	Q_OBJECT

public:
	AddDialog(QWidget *parent = Q_NULLPTR);
	~AddDialog();

	auto setEditFieldsText(QString const& lastName, QString const& firstName, QString const& phoneNumber) noexcept -> void;

private slots:
	void on_okButton_clicked();
	void on_cancelButton_clicked();
};


