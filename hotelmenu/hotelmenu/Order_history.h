#pragma once

#include <QWidget>
#include "ui_Order_history.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <iostream>
#include <string.h>
#include <QListWidget>
#include <qtableview.h>
#include <QComboBox>


class Order_history : public QWidget
{
	Q_OBJECT

public:
	Order_history(QWidget *parent = nullptr);
	~Order_history();

public slots:
	void input_dbname(QString x);
	void add_comment();         //��ʼ����
	void show_database();              //չʾ��ʷ���� 
	void qbox_init();          //��ʼ��qbox�����б�
	void show_grade();      //չʾ���֡�
	void menu_init();         //menu���ݿ��ʼ��

private:
	Ui::Order_historyClass ui;
	QSqlDatabase db5;
	QString dbname;
	double start_num1 = 0;
	double start_num2 = 0;
	double start_num3 = 0;
	double start_num4 = 0;
	double start_num5 = 0;
	double start_num6 = 0;
	double start_num7 = 0;
	double start_num8 = 0;
};
