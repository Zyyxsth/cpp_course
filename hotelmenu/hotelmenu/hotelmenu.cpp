#include "hotelmenu.h"

using namespace std;

hotelmenu::hotelmenu(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    ui.lineEdit_pwd->setEchoMode(QLineEdit::Password);        //����������ʱ������ת��ΪС�ڵ�
 //   connect(ui.btn_4, SIGNAL(clicked(bool),this,SLOT(set_style())
    QObject::connect(ui.btn_1, SIGNAL(clicked(bool)), this, SLOT(Registration_clicked()));
    QObject::connect(ui.btn_login, SIGNAL(clicked(bool)), this, SLOT(login()));
    //db.setHostName("localhost");          // ���ݿ��ַ��һ�㶼�Ǳ��أ���localhost�Ϳ���(������д127.0.0.1) 
    //QString dbPath = QCoreApplication::applicationDirPath() + "/shu_ju_ku.db";
    //db.setDatabaseName(dbPath);          //���ݿ������

}

hotelmenu::~hotelmenu()
{}


void hotelmenu::Registration_clicked() {                    //��ʾע�����
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
    this->db.setDatabaseName(dbPath);          //���ݿ������
    this->db.open();
    QString input_account = ui.lineEdit_username->text();           //������˺�
    QString input_pwd = ui.lineEdit_pwd->text();                    //���������
    
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
