#include "Game.h"
#include <QKeyEvent>
#include <qpushbutton.h>
#include <qmessagebox.h>

Game::Game(QWidget *parent) :QGraphicsView(parent) {
	QEvent::ApplicationDeactivate; //to jest stare,jak cos

	/*get->setGeometry(0, 0, 600, 500);

	scene = new QGraphicsScene();
	scene->setSceneRect(0, 0, 600, 500);
	scene->setBackgroundBrush(Qt::gray);
	widget->setLayout(scene);*/
	
	/*scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 600, 500);
	scene->setBackgroundBrush(Qt::gray);
	setScene(scene);*/
	
	/*mainMenu = new QGraphicsView(this);
	mainMenu->setGeometry(0, 0, 620, 520);
	mainMenu->setStyleSheet("background-color:green");*/
	//scene->addWidget(mainMenu);

	scene = new QGraphicsScene(this);
	scene->setSceneRect(0, 0, 620, 520);
	setScene(scene);
	
	setFixedSize(620, 520);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	
	/*l = new QLabel(this);
	l->setGeometry(530, 10, 80, 25);*/
	
	mainMenu = new MainMenu();
	scene->addItem(mainMenu);

	

	/*l = new QLabel(this);
	l->setGeometry(530, 10, 80, 25);
	
	l2 = new QLabel(this);
	l2->setGeometry(530, 40, 80, 25);
	
	l4 = new QLabel(this);
	l4->setGeometry(530, 70, 80, 30);*/

	/*map = new Map();
	scene->addItem(map);

	player = new Player();
	scene->addItem(player);*/

	/*if (!map) {
		QMessageBox::information(this, "", "Nie ma mapy");
	}
	else {
		QMessageBox::information(this, "", "Jest mapa");
	}*/

}


void Game::resetGame2(QKeyEvent *event) {
	//QKeyEvent *event = new QKeyEvent(QEvent::KeyPress, Qt::Key_R, Qt::NoModifier);
	
	if (event->key() == Qt::Key_R) {
		QMessageBox::information(this, "", "Zresetowano poziom");
	}
}

void Game::keyPressEvent(QKeyEvent *event){
	if (mainMenu) {
		if (event->key() == Qt::Key_Space) {
			//if (mainMenu) {
				if (mainMenu->getCursorPosition() == 1) {
					if (!(map && player)) {
						//tworzy obiekty gracz i mapa oraz usuwa meny glowne
						delete mainMenu;

						//scene = new QGraphicsScene(this);
						//scene->setSceneRect(0, 0, 600, 500);
						scene->setBackgroundBrush(Qt::gray);
						//setScene(scene);

						l = new QLabel(this);
						l->setGeometry(530, 10, 80, 25);

						// do poprawy
						txt = new QGraphicsTextItem();
						txt->setPos(530, 10);

						l2 = new QLabel(this);
						l2->setGeometry(530, 40, 80, 25);

						l4 = new QLabel(this);
						l4->setGeometry(530, 70, 80, 30);

						map = new Map();
						scene->addItem(map);

						player = new Player();
						scene->addItem(player);
					}
				}
				else if (mainMenu->getCursorPosition() == 2) {
					delete mainMenu;
					
					selectLevel = new SelectLevel();
					scene->addItem(selectLevel);

				}
				else if (mainMenu->getCursorPosition() == 3) {
					quick_exit(0);
				}
			//}
		}
	}
	if (event->key() == Qt::Key_1) {
		/*if (!(map && player)){
			//tworzy obiekty gracz i mapa oraz usuwa meny glowne
			delete mainMenu;

			//scene = new QGraphicsScene(this);
			//scene->setSceneRect(0, 0, 600, 500);
			scene->setBackgroundBrush(Qt::gray);
			//setScene(scene);

			l = new QLabel(this);
			l->setGeometry(530, 10, 80, 25);

			l2 = new QLabel(this);
			l2->setGeometry(530, 40, 80, 25);

			l4 = new QLabel(this);
			l4->setGeometry(530, 70, 80, 30);

			map = new Map();
			scene->addItem(map);

			player = new Player();
			scene->addItem(player);
		}*/
	}
	if (event->key() == Qt::Key_Escape) {
		if (map && player) {
			scene->removeItem(map);
			delete map;
			map = nullptr;

			scene->removeItem(player);
			delete player;
			player = nullptr;
			delete l, l2, l4;
		}
		else if (selectLevel) {
			scene->removeItem(selectLevel);
			delete selectLevel;
			selectLevel = nullptr;
		}

		mainMenu = new MainMenu();
		scene->addItem(mainMenu);
		
		/*mainMenu = new QGraphicsView(this);
		mainMenu->setGeometry(0, 0, 620, 520);
		mainMenu->setStyleSheet("background-color:green");*/

		/*if (mainMenu) {
			QMessageBox::information(this, "", "Jest menu glowne");
		}*/
		//mainMenu->show();

	}
	if (event->key() == Qt::Key_R) {
		if (map && player) {
			scene->removeItem(map);
			delete map;
			map = new Map();
			scene->addItem(map);

			scene->removeItem(player);
			delete player;
			player = new Player();
			scene->addItem(player);
			
			//scene->removeItem(player);
			//player->setPos(50, 50);
			//player->set();
			//scene->addItem(player);
			QMessageBox::information(this, "", "Zresetowano poziom");
		}

	}
	QGraphicsView::keyPressEvent(event);
}