#ifndef LEVEL_H
#define LEVEL_H

#include <qobject.h>
#include <QGraphicsRectItem>
#include <qgraphicsitem.h>
#include "Map.h"
#include "Player.h"

class Level: public QObject, public QGraphicsRectItem {
	Q_OBJECT

public:
	Level(QGraphicsItem *parent = 0);
	//Level(QGraphicsItem *parent, int nrLevel); // ?? Teorzenie levelu poprzez wybow z "Wybierz poziom"
	void createLevel(int val);

protected:
	void keyPressEvent(QKeyEvent *event) override;

private:
	int levelNumber = 1;

	QGraphicsRectItem *levelMap;
	Map *map = nullptr;
	Player *player = nullptr;

};

#endif // !LEVEL_H