#pragma once

#include <QDialog>
#include "ui_searchdialog.h"

class SearchDialog : public QDialog, public Ui::SearchDialog
{
	Q_OBJECT

public:
	SearchDialog(QWidget *parent = Q_NULLPTR);

private slots:
	void on_searchButton_clicked();
	void on_cancelButton_clicked();
};
