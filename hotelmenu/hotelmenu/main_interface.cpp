#include "main_interface.h"
#include "Order_history.h"

main_interface::main_interface(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	
	QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(add_dishone()));
	QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(add_dishtwo()));
	QObject::connect(ui.pushButton_3, SIGNAL(clicked()), this, SLOT(add_dishthree()));
	QObject::connect(ui.pushButton_4, SIGNAL(clicked()), this, SLOT(add_dishfour()));
	QObject::connect(ui.pushButton_5, SIGNAL(clicked()), this, SLOT(add_dishfive()));
	QObject::connect(ui.pushButton_6, SIGNAL(clicked()), this, SLOT(add_dishsix()));
	QObject::connect(ui.pushButton_7, SIGNAL(clicked()), this, SLOT(add_dishseven()));
	QObject::connect(ui.pushButton_8, SIGNAL(clicked()), this, SLOT(add_disheight()));
	QObject::connect(ui.add, SIGNAL(clicked()), this, SLOT(add_dish()));
	QObject::connect(ui.delete_2, SIGNAL(clicked()), this, SLOT(delete_dish()));
	QObject::connect(ui.confirm, SIGNAL(clicked()), this, SLOT(confirm_order()));
	QObject::connect(ui.history, SIGNAL(clicked()), this, SLOT(open_history()));
}

main_interface::~main_interface()
{}

void main_interface::open_history() {
	Order_history* oh = new Order_history();
	oh->input_dbname(username);
	oh->show();
}


void main_interface::input_username(QString x) {
	username = x;
}

void main_interface::add_dishone() {
	addone = 1;
}

void main_interface::add_dishtwo() {
	addtwo = 1;
}

void main_interface::add_dishthree() {
	addthree = 1;
}

void main_interface::add_dishfour() {
	addfour = 1;
}

void main_interface::add_dishfive() {
	addfive = 1;
}

void main_interface::add_dishsix() {
	addsix = 1;
}

void main_interface::add_dishseven() {
	addseven = 1;
}

void main_interface::add_disheight() {
	addeight = 1;
}

void main_interface::add_dish() {
	this->db = QSqlDatabase::addDatabase("QSQLITE");
	this->db.setHostName("localhost");
	QString dbPath = QCoreApplication::applicationDirPath() + +"/" + username + ".db";
	//qDebug() << dbPath << endl;
	this->db.setDatabaseName(dbPath);          //数据库的名字
	this->db.open();
	QString dataTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");//获取当前时间
	if (addone == 1) {
		addone = 0;
		num1 += 1;
		total += 50;
		QString dishname1 = "hongshaorou";
		QString dish1 = "hong shao rou-----50yuan";
		if (addone == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname1);
			query.bindValue(":Money", 50.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num1);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish1);
		}
		
	}
	if (addtwo == 1) {
		addtwo = 0;
		num2 += 1;
		total += 30;
		QString dishname2 = "shaoya";
		QString dish2 = "shaoya-----30yuan";
		if (addtwo == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname2);
			query.bindValue(":Money", 30.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num2);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish2);
		}
	}
	if (addthree == 1) {
		addthree = 0;
		num3 += 1;
		total += 35;
		QString dishname3 = "sixiwanzi";
		QString dish3 = "si xi wan zi-----35yuan";
		if (addthree == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname3);
			query.bindValue(":Money", 35.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num3);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish3);
		}
	}
	if (addfour == 1) {
		addfour = 0;
		num4 += 1;
		total += 75;
		QString dishname4 = "shui zhu yu";
		QString dish4 = "shui zhu yu-----75yuan";
		if (addfour == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname4);
			query.bindValue(":Money", 75.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num4);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish4);
		}
	}
	if (addfive == 1) {
		addfive = 0;
		num5 += 1;
		total += 20;
		QString dishname5 = "ma po toufu";
		QString dish5 = "ma po toufu-----20yuan";
		if (addfive == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname5);
			query.bindValue(":Money", 20.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num5);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish5);
		}
	}
	if (addsix == 1) {
		addsix = 0;
		num6 += 1;
		total += 20;
		QString dishname6 = "hongshaoqiezi";
		QString dish6 = "hong shao qie zi-----20yuan";
		if (addsix == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname6);
			query.bindValue(":Money", 20.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num6);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish6);
		}
	}
	if (addseven == 1) {
		addseven = 0;
		num7 += 1;
		total += 15;
		QString dishname7 = "tomato with eggs";
		QString dish7 = "tomato with eggs-----15yuan";
		if (addseven == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname7);
			query.bindValue(":Money", 15.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num7);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish7);
		}
	}
	if (addeight == 1) {
		addeight = 0;
		num8 += 1;
		total += 25;
		QString dishname8 = "lajiao chao rou";
		QString dish8 = "lajiao chao rou-----25yuan";
		if (addeight == 0) {
			QSqlQuery query;
			query.prepare("Insert into history(OrderId, Dishname, Money, Time, cixu)VALUES(:OrderId, :Dishname, :Money, :Time, :cixu)");
			query.bindValue(":OrderId", id);
			query.bindValue(":Dishname", dishname8);
			query.bindValue(":Money", 25.0);
			query.bindValue(":Time", dataTime);
			query.bindValue(":cixu", num8);
			query.exec();
			//query.exec("Insert into history(loc, OrderId, Dishname, Money, Time)VALUES(loc, id, :dishname1, 50.0, dataTime)");
			ui.listorder->addItem(dish8);
		}
	}
	QString total_str = QString("%1").arg(total);
	ui.label_2->setText(total_str);
	db.close();
}

void main_interface::delete_dish()
{
	this->db = QSqlDatabase::addDatabase("QSQLITE");
	this->db.setHostName("localhost");
	QString dbPath = QCoreApplication::applicationDirPath() + +"/" + username + ".db";
	//qDebug() << dbPath << endl;
	this->db.setDatabaseName(dbPath);          //数据库的名字
	this->db.open();
//	total -= 25;
	QString dish1 = "hong shao rou-----50yuan";
	QString dish2 = "shaoya-----30yuan";
	QString dish3 = "si xi wan zi-----35yuan";
	QString dish4 = "shui zhu yu-----75yuan";
	QString dish5 = "ma po toufu-----20yuan";
	QString dish6 = "hong shao qie zi-----20yuan";
	QString dish7 = "tomato with eggs-----15yuan";
	QString dish8 = "lajiao chao rou-----25yuan";
	QString dishname1 = "hongshaorou";
	QString dishname2 = "shaoya";
	QString dishname3 = "sixiwanzi";
	QString dishname4 = "shui zhu yu";
	QString dishname5 = "ma po toufu";
	QString dishname6 = "hongshaoqiezi";
	QString dishname7 = "tomato with eggs";
	QString dishname8 = "lajiao chao rou";
	int n = ui.listorder->count();
	int row = ui.listorder->currentRow();
	QString txts = ui.listorder->currentItem()->text();
	if (txts == dish1) {
		total -= 50;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2'and OrderId= '%3'").arg(num1).arg(dishname1).arg(id);
		query.exec(sql);
		num1 = num1 - 1;
		txts = " ";
	}
	if (txts == dish2) {
		total -= 30;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId = '%3'").arg(num2).arg(dishname2).arg(id);
		query.exec(sql);
		num2 = num2 - 1;
		txts = " ";
	}
	if (txts == dish3) {
		total -= 35;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId= '%3'").arg(num3).arg(dishname3).arg(id);
		query.exec(sql);
		num3 = num3 - 1;
		txts = " ";
	}
	if (txts == dish4) {
		total -= 75;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId= '%3'").arg(num4).arg(dishname4).arg(id);
		query.exec(sql);
		num4 = num4 - 1;
		txts = " ";
	}
	if (txts == dish5) {
		total -= 20;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId= '%3'").arg(num5).arg(dishname5).arg(id);
		query.exec(sql);
		num5 = num5 - 1;
		txts = " ";
	}
	if (txts == dish6) {
		total -= 20;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId= '%3'").arg(num6).arg(dishname6).arg(id);
		query.exec(sql);
		num6 = num6 - 1;
		txts = " ";
	}
	if (txts == dish7) {
		total -= 15;
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId= '%3'").arg(num7).arg(dishname7).arg(id);
		query.exec(sql);
		num7 = num7 - 1;
		txts = " ";
	}
	if (txts == dish8) {
		total -= 25;
		txts = " ";
		QSqlQuery query;
		QString sql = QString("DELETE FROM history WHERE cixu = '%1' and Dishname= '%2' and OrderId= '%3'").arg(num8).arg(dishname8).arg(id);
		query.exec(sql);
		num8 = num8 - 1;
		txts = " ";
	}

	QListWidgetItem* lst = ui.listorder->takeItem(row);
	delete lst;	
	
	QString total_str = QString("%1").arg(total);
	ui.label_2->setText(total_str);
	db.close();
}



void main_interface::confirm_order() {
	//this->db = QSqlDatabase::addDatabase("QSQLITE");
	//this->db.setHostName("localhost");
	//QString dbPath = QCoreApplication::applicationDirPath() + +"/" + username + ".db";
	//qDebug() << dbPath << endl;
	//this->db.setDatabaseName(dbPath);          //数据库的名字
	//this->db.open();
	//id = id +1;
	id = id + 1;
	ui.listorder->clear();
	total = 0;
	QString total_str = QString("%1").arg(total);
	ui.label_2->setText(total_str);
	num1 = num2 = num3 = num4 = num5 = num6 = num7 = num8 = 0;
}


