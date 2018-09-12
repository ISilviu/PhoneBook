#pragma once

#include <QDialog>
#include <qsqlquerymodel.h>
#include "ui_foundcontactsdialog.h"

class FoundContactsDialog : public QDialog, public Ui::FoundContactsDialog
{
	Q_OBJECT

public:
	FoundContactsDialog(QWidget *parent = Q_NULLPTR);
	~FoundContactsDialog();

private:
	QSqlQueryModel* _model;
};
