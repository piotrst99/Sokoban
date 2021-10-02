#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <qobject.h>
#include <qgraphicsitem.h>
#include <qlabel.h>

class Player: /*public QObject,*/ public QGraphicsRectItem{
	//Q_OBJECT
public:
	Player(QGraphicsItem *parent = 0);
	Player(QGraphicsItem *parent, int val);

	QGraphicsRectItem *rectangle;

	void moveLeft();
	void moveRight();
	void moveUp();
	void moveDown();

private:

};

#endif // !PLAYER_H
