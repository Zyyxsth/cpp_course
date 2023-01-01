#include "Order_history.h"

Order_history::Order_history(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	QObject::connect(ui.btn_contact, SIGNAL(clicked()), this, SLOT(show_database()));
	QObject::connect(ui.btn_comment, SIGNAL(clicked()), this, SLOT(add_comment()));
//	show_database();
	menu_init();
	qbox_init();
	show_grade();
}

Order_history::~Order_history()
{}

void Order_history::input_dbname(QString x) {
	dbname = x;
}

void Order_history::show_database()
{
	this->db5 = QSqlDatabase::addDatabase("QSQLITE");
	this->db5.setHostName("localhost");
	QString dbPath = QCoreApplication::applicationDirPath() + +"/" + dbname + ".db";
	qDebug() << dbPath << endl;
	this->db5.setDatabaseName(dbPath);          //数据库的名字
	this->db5.open();
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("history");
	ui.tableView_history->setModel(model);
	model->select();   //显示model里的数据
	db5.close();
	
}


void Order_history::qbox_init() {
	QString dishname1 = "hongshaorou";
	QString dishname2 = "shaoya";
	QString dishname3 = "sixiwanzi";
	QString dishname4 = "shui zhu yu";
	QString dishname5 = "ma po toufu";
	QString dishname6 = "hongshaoqiezi";
	QString dishname7 = "tomato with eggs";
	QString dishname8 = "lajiao chao rou";
	QStringList strList;
	strList << dishname1 << dishname2 << dishname3 << dishname4 << dishname5 << dishname6 << dishname7 << dishname8;
	ui.cbox->addItems(strList);
	//QHBoxLayout* layout = new QHBoxLayout;
	//layout->addWidget(ui.cbox);

	//this->setLayout(layout);
}

void Order_history::show_grade() {
	QString menu_star = "menu_star";
	this->db5 = QSqlDatabase::addDatabase("QSQLITE");
	this->db5.setHostName("localhost");
	QString dbPath = QCoreApplication::applicationDirPath() + +"/" + menu_star + ".db";
	qDebug() << dbPath << endl;
	this->db5.setDatabaseName(dbPath);          //数据库的名字
	this->db5.open();
	QSqlTableModel* model = new QSqlTableModel(this);
	model->setTable("stars");
	ui.starView2->setModel(model);
	model->select();   //显示model里的数据
}

void Order_history::menu_init()
{
	QString menu_star = "menu_star";
	QString dishname1 = "hongshaorou";
	QString dishname2 = "shaoya";
	QString dishname3 = "sixiwanzi";
	QString dishname4 = "shui zhu yu";
	QString dishname5 = "ma po toufu";
	QString dishname6 = "hongshaoqiezi";
	QString dishname7 = "tomato with eggs";
	QString dishname8 = "lajiao chao rou";
	db5 = QSqlDatabase::addDatabase("QSQLITE");
	db5.setHostName("localhost");
	QString dbPath = QCoreApplication::applicationDirPath() + +"/" + menu_star + ".db";
	db5.setDatabaseName(dbPath);          //数据库的名字
	db5.open();
	QSqlQuery query;
	query.exec("create table stars(disname varchar(20) PRIMARY KEY,star double, person int(5))");//创建表，执行sql
	//QString sql = QString("INSERT INTO stars(disname, star)VALURS('%1','%2')").arg(dishname1).arg(start_num1);
	//query.exec(sql);
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname1);
	query.bindValue(":star", start_num1);
	query.bindValue(":person", start_num1);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname2);
	query.bindValue(":star", start_num2);
	query.bindValue(":person", start_num2);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname3);
	query.bindValue(":star", start_num3);
	query.bindValue(":person", start_num3);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname4);
	query.bindValue(":star", start_num4);
	query.bindValue(":person", start_num4);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname5);
	query.bindValue(":star", start_num5);
	query.bindValue(":person", start_num5);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname6);
	query.bindValue(":star", start_num6);
	query.bindValue(":person", start_num6);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname7);
	query.bindValue(":star", start_num7);
	query.bindValue(":person", start_num7);
	query.exec();
	query.prepare("INSERT INTO stars(disname, star, person) "
		"VALUES (:disname, :star, :person)");
	query.bindValue(":disname", dishname8);
	query.bindValue(":star", start_num8);
	query.bindValue(":person", start_num8);
	query.exec();   
	db5.close();
}

void Order_history::add_comment() {
	QString menu_star = "menu_star";
	this->db5 = QSqlDatabase::addDatabase("QSQLITE");
	this->db5.setHostName("localhost");
	QString dbPath = QCoreApplication::applicationDirPath() + +"/" + menu_star + ".db";
	qDebug() << dbPath << endl;
	this->db5.setDatabaseName(dbPath);          //数据库的名字
	this->db5.open();

	QString dishname1 = "hongshaorou";
	QString dishname2 = "shaoya";
	QString dishname3 = "sixiwanzi";
	QString dishname4 = "shui zhu yu";
	QString dishname5 = "ma po toufu";
	QString dishname6 = "hongshaoqiezi";
	QString dishname7 = "tomato with eggs";
	QString dishname8 = "lajiao chao rou";
	QString gde = ui.grade->text();
	double gde2 = gde.toDouble();
	if (gde == "") {
		QMessageBox::warning(this, tr("warning"), tr("Please input the grades!"));
	}
	QString name_dish = ui.cbox->currentText();
	if (name_dish == dishname1) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname1);
		query.exec(str);
		QString name;
		double score=0;
		double new_score;
		int people_num1;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num1 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score* people_num1 + gde2)/(people_num1 +1);
		people_num1 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num1).arg(dishname1);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname2) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname2);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num2;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num2 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num2 + gde2) / (people_num2 + 1);
		people_num2 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num2).arg(dishname2);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname3) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname3);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num3;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num3 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num3 + gde2) / (people_num3 + 1);
		people_num3 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num3).arg(dishname3);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname4) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname4);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num4;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num4 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num4 + gde2) / (people_num4 + 1);
		people_num4 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num4).arg(dishname4);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname5) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname5);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num5;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num5 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num5 + gde2) / (people_num5 + 1);
		people_num5 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num5).arg(dishname5);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname6) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname6);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num6;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num6 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num6 + gde2) / (people_num6 + 1);
		people_num6 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num6).arg(dishname6);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname7) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname7);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num7;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num7 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num7 + gde2) / (people_num7 + 1);
		people_num7 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num7).arg(dishname7);
		query.exec(sql);
		show_grade();
	}
	if (name_dish == dishname8) {
		QSqlQuery query;
		QString str = QString("select *from stars where disname = '%1'").arg(dishname8);
		query.exec(str);
		QString name;
		double score = 0;
		double new_score;
		int people_num8;
		while (query.next())
		{
			name = query.value(0).toString();
			score = query.value(1).toDouble();
			people_num8 = query.value(2).toInt();
		}
		qDebug() << score;
		new_score = (score * people_num8 + gde2) / (people_num8 + 1);
		people_num8 += 1;
		qDebug() << new_score;
		QString sql = QString("UPDATE stars SET star = '%1', person ='%2' WHERE disname= '%3'").arg(new_score).arg(people_num8).arg(dishname8);
		query.exec(sql);
		show_grade();
	}
	db5.close();
}
