#include "hotelmenu.h"

using namespace std;

hotelmenu::hotelmenu(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    ui.lineEdit_pwd->setEchoMode(QLineEdit::Password);        //在输入密码时，将其转化为小黑点
 //   connect(ui.btn_4, SIGNAL(clicked(bool),this,SLOT(set_style())
    QObject::connect(ui.btn_1, SIGNAL(clicked(bool)), this, SLOT(Registration_clicked()));
    QObject::connect(ui.btn_login, SIGNAL(clicked(bool)), this, SLOT(login()));
    //db.setHostName("localhost");          // 数据库地址，一般都是本地，填localhost就可以(或者填写127.0.0.1) 
    //QString dbPath = QCoreApplication::applicationDirPath() + "/shu_ju_ku.db";
    //db.setDatabaseName(dbPath);          //数据库的名字

}

hotelmenu::~hotelmenu()
{}


void hotelmenu::Registration_clicked() {                    //显示注册界面
    Registration* reg = new Registration;
    reg->show();
}

void hotelmenu::login() {
    main_interface* mif = new main_interface;

    if (!check_login()) {
        mif->input_username(user_name);
        mif->show();
    }
    
    
}


QString hotelmenu::Get_username(){
    return user_name;
}

bool hotelmenu::check_login()
{
    this->db = QSqlDatabase::addDatabase("QSQLITE");
    this->db.setHostName("localhost");
    QString dbPath = QCoreApplication::applicationDirPath() + "/shu_ju_ku.db";
    this->db.setDatabaseName(dbPath);          //数据库的名字
    this->db.open();
    QString input_account = ui.lineEdit_username->text();           //输入的账号
    QString input_pwd = ui.lineEdit_pwd->text();                    //输入的密码
    
    QSqlQuery query1 = QSqlQuery(db);
    query1.exec("select * from users");
    while (query1.next()) {
        if (query1.value("account") == input_account) {
            //qDebug() << query1.value("account").toString();
            if (query1.value("password") == input_pwd) {
                user_name = input_account;
                QMessageBox::information(this, tr("information"), tr("Welcome!"));
                db.close();
                return 0;
            }
            else {
                QMessageBox::warning(this, tr("warning"), tr("Wrong password!"));
                ui.lineEdit_pwd->clear();
                db.close();
                return 1;
            }
        }
    }
    QMessageBox::warning(this, tr("warning"), tr("404 Not Found!"));
    db.close();
    return 1;
}
