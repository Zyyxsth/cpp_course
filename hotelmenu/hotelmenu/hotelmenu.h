#pragma once

#include <QtWidgets/QWidget>
#include "ui_hotelmenu.h"
#include <qpushbutton.h>
#include <QSqlDatabase>	// �������ݿ�
#include <QSqlError>		// ���ݿ�����ʧ�ܴ�ӡ�������
#include <QSqlQuery>		// ���ݿ��������ɾ�Ĳ飩
#include <QMessageBox>
#include <QVariantList>			// �����������Դ洢�κ����͵�����
#include <QDebug>
#include <QUrl>
#include <QtSql>
#include <QSqlRecord>
#include <QString>
#include "Registration.h"
#include "main_interface.h"



using namespace std;

class hotelmenu : public QWidget
{
    Q_OBJECT

public:
    hotelmenu(QWidget *parent = nullptr);
    ~hotelmenu();
    
   

public slots:               
    void Registration_clicked();           //���ע�����
    void login();          //��¼
    bool check_login(); 
    QString Get_username();

private:
    Ui::hotelmenuClass ui;
    QSqlDatabase db;
    QString user_name;

};
