#include "Registration.h"
#include <QString>

Registration::Registration(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(after_Registration_clicked()));
    QObject::connect(ui.lineEdit_confirmpassword, SIGNAL(editingFinished()), this, SLOT(check_password()));
    QObject::connect(ui.lineEdit_password, SIGNAL(editingFinished()), this, SLOT(input_password()));
    QObject::connect(ui.lineEdit_account, SIGNAL(editingFinished()), this, SLOT(check_account()));
    QObject::connect(ui.lineEdit_name, SIGNAL(editingFinished()), this, SLOT(check_name()));
    db.setHostName("localhost");          // 数据库地址，一般都是本地，填localhost就可以(或者填写127.0.0.1) 
    QString dbPath = QCoreApplication::applicationDirPath() + "/shu_ju_ku.db";
    db.setDatabaseName(dbPath);          //数据库的名字
    
}

Registration::~Registration()
{}

void Registration::create_person_database(QString databasename) {             //用于创建个人的表
    QSqlDatabase db2 = QSqlDatabase::addDatabase("QSQLITE");
    db2.setHostName("localhost");
    QString db2Path = QCoreApplication::applicationDirPath() +"/"+ databasename + ".db";
    db2.setDatabaseName(db2Path);

    bool ok = db2.open();//如果不存在就创建，存在就打开
    if (ok)
    {
        qDebug() << "person is successfully opened";
        cout << "person created" << endl;
    }
    else
    {
        qDebug() << db2.lastError().text();//调用上一次出错的原因
        exit(-1);
    }

    QSqlQuery query2;	// *对数据进行操作所需要使用到的对象*
// 定义sql语句
    query2.exec("create table history (OrderId int(5) , Dishname varchar(32), Money double, Time datetime  PRIMARY KEY, cixu int(5));");
    //orderid:订单编号, Dish name菜名, total总消费金额，time时间, comment评论
    // 执行sql语句
    query2.exec();
    db2.close();

    
    
}

bool Registration::check_password() {
    QString psd = ui.lineEdit_password->text();
    QString cpsd = ui.lineEdit_confirmpassword->text();
    if (psd != cpsd) {
        QString wrong_psd = "sorry, The passwords entered twice are inconsistent!";
        ui.tip_confirmpassword->setText(wrong_psd);
        return 1;
    }
    else {
        QString wrong_psd = "correct!";
        ui.tip_confirmpassword->setText(wrong_psd);
        return 0;
    }
}

bool Registration::input_password() {
    QString psd  = ui.lineEdit_password->text();
    if (psd.size() < 5) {
        QString wrong_psd = "sorry, The passwords is too short!";
        ui.tip_password->setText(wrong_psd);
        return 1;
    }
    else {
        QString wrong_psd = "able to use!";
        ui.tip_password->setText(wrong_psd);
        return 0;
    }
}

bool Registration::check_account() {
    QString account = ui.lineEdit_account->text();
    QSqlQuery query3;
    query3.exec("select * from shu_ju_ku.db");
    while (query3.next()) {
        if (query3.value("account") == account) {
            QString wrong_account = "sorry, The account has existed!";
            ui.tip_account->setText(wrong_account);
            return 1;
        }
    }
    QString wrong_account = "Able to use!";
    ui.tip_account->setText(wrong_account);
    return 0;

}


bool Registration::check_name(){
    QString name = ui.lineEdit_name->text();
    if (name.size() < 5) {
        QString wrong_name = "sorry, The name is too short!";
        ui.tip_name->setText(wrong_name);
        return 1;
    }
    else {
        QString True_name = "able to use!";
        ui.tip_name->setText(True_name);
        return 0;
    }
}


void Registration::after_Registration_clicked() {

    QString account = ui.lineEdit_account->text();
    QString name = ui.lineEdit_name->text();
    QString password = ui.lineEdit_password->text();

    bool ok = db.open();//如果不存在就创建，存在就打开
    if (ok)
    {
        qDebug() << "user is successfully opened";
        cout << "user created" << endl;
    }
    else
    {
        qDebug() << db.lastError().text();//调用上一次出错的原因
        exit(-1);
    }

    QSqlQuery query;
    query.exec("create table users(account varchar(20) PRIMARY KEY,name varchar(20),password varchar(20))");//创建表，执行sql

 //   query.exec("select * from qt_test_table;");		// 查询全部
    if (check_password() == 1) {
        QMessageBox::warning(this, tr("warning"), tr("two passwords are different!"));
    }
    else if (input_password() == 1) {
        QMessageBox::warning(this, tr("warning"), tr("the passwords are too short!"));
    }
    else if (check_account() == 1) {
        QMessageBox::warning(this, tr("warning"), tr("please change the account !"));
    }
    else if (check_name() == 1) {
        QMessageBox::warning(this, tr("warning"), tr("please change the name !"));
    }
    else if (check_password() == 0 && input_password()==0 && check_account() == 0 && check_name()==0) {
        query.prepare("INSERT INTO users(account, name, password) "
            "VALUES (:account, :name, :password)");
        query.bindValue(":account", ui.lineEdit_account->text());
        query.bindValue(":name", ui.lineEdit_name->text());
        query.bindValue(":password", ui.lineEdit_password->text());
        query.exec();

        QString dbname = account;
        create_person_database(dbname);
    }
    ui.lineEdit_account->clear();
    ui.lineEdit_name->clear();
    ui.lineEdit_password->clear();
    ui.lineEdit_confirmpassword->clear();
    db.close();
	
}
