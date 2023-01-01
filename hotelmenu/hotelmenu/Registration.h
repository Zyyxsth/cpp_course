#pragma once

#include <QWidget>
#include "ui_Registration.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <iostream>
#include <string.h>
using namespace std;

class Registration : public QWidget
{
	Q_OBJECT

public:
	Registration(QWidget *parent = nullptr);
	~Registration();

public slots:                            //槽函数
	void after_Registration_clicked();
	void create_person_database(QString databasename);
	bool check_password();
	bool input_password();
	bool check_account(); //查看是否已经存在重复的账号
	bool check_name(); //检测名字

private:
	Ui::RegistrationClass ui;
	QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");

};
