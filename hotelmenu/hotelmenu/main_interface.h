#pragma once

#include <QWidget>
#include "ui_main_interface.h"
#include <QMessageBox>
#include <QtSql>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QSqlError>
#include <QDebug>
#include <iostream>
#include <string.h>
#include <QListWidget>

class main_interface : public QWidget
{
	Q_OBJECT

public:
	main_interface(QWidget *parent = nullptr);
	~main_interface();

public slots:                  //�����Ĺ���
	void input_username(QString x);
	void add_dishone();      //���һ����                 
	void add_dishtwo();
	void add_dishthree();
	void add_dishfour();
	void add_dishfive();
	void add_dishsix();
	void add_dishseven();
	void add_disheight();
	//�����ɾ��8�ֲ�
	void confirm_order();   //ȷ�϶���
	void add_dish();  //��Ӳ�Ʒ
	void delete_dish();   //ɾ����Ʒ
	void open_history();  //����ʷ������¼
	

private:
	Ui::main_interfaceClass ui;
	QSqlDatabase db;
	QString username;
	int addone = 0;
	int addtwo = 0;
	int addthree = 0;
	int addfour = 0;
	int addfive = 0;
	int addsix = 0;
	int addseven = 0;
	int addeight = 0;
	double total = 0;  //�ܶ�
	int id = 1;
	int num1 = 0;
	int num2 = 0;
	int num3 = 0;
	int num4 = 0;
	int num5 = 0;
	int num6 = 0;
	int num7 = 0;
	int num8 = 0;
};
