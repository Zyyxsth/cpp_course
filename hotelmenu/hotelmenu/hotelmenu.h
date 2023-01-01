#pragma once

#include <QtWidgets/QWidget>
#include "ui_hotelmenu.h"
#include <qpushbutton.h>
#include <QSqlDatabase>	// 连接数据库
#include <QSqlError>		// 数据库连接失败打印报错语句
#include <QSqlQuery>		// 数据库操作（增删改查）
#include <QMessageBox>
#include <QVariantList>			// 泛型链表，可以存储任何类型的数据
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
    void Registration_clicked();           //点击注册界面
    void login();          //登录
    bool check_login(); 
    QString Get_username();

private:
    Ui::hotelmenuClass ui;
    QSqlDatabase db;
    QString user_name;

};
