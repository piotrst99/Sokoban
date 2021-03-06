#ifndef LEVEL_H
#define LEVEL_H

#include <qobject.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include "Map.h"
#include "Player.h"
#include "GameMenu.h"
#include "Box.h"
#include "Point.h"
#include "Wall.h"

#include <vector>

/*struct wyszukajSciany {
	bool operator()(const std::vector<Wall *> &sciany, Player *p) {
		if(p->pos().x)
		return true;
	}
};*/

class Level: /*public QObject,*/ public QGraphicsRectItem {
	//Q_OBJECT

public:
	Level(QGraphicsItem *parent = 0);
	Level(QGraphicsItem *parent, int nrLevel); // ?? Tworzenie levelu poprzez wybow z "Wybierz poziom"
	void createLevel(int val);
	void nextLevel(int val);
	void resetLevel(int val);

	void changeItemPosition();
	void checkCoinCount();
	int checkCoinCount(std::vector<Point *> &points, std::vector<Box *> &boxs);
	void checkBoxsAndPoints(std::vector<Point *> &points, std::vector<Box *> &boxs);

	int levelNumber = 1;
	int countOfLevel = 4;

	QGraphicsRectItem *levelMap = nullptr;
	Map *map = nullptr;
	Player *player = nullptr;

	//std::vector<std::vector<std::unique_ptr<Box>>> boxs; // do zastanowienia sie, czy zapisac w taki sposob
	std::vector<std::vector<Box *>> boxs;
	std::vector<Box *> pudelka;
	std::vector<std::pair<int, int>> coordsBoxs;
	std::vector<Wall *> sciany;
	std::vector<std::pair<int, int>> coordsWalls;
	std::vector<Point *> punkty;
	std::vector<std::pair<int, int>> coordsPoints;
	
	QGraphicsTextItem *coinCount, *levelText;

	GameMenu *gameMenu = nullptr;

	int ileScian = 0, ilePudelek = 0, ilePunktow = 0;
	void testTworzeniaObiektow();

	

protected:
	void keyPressEvent(QKeyEvent *event) override;

};


#endif // !LEVEL_H
