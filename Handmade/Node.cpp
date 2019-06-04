#include "Node.h"



Node::Node(int xp, int yp, int d, int p)
{
	xPos = xp;
	yPos = yp;
	level = d;
	priority = p;
}


Node::~Node()
{
}

void Node::updatePriority(const int & xDest, const int & yDest)
{
	priority = level + estimate(xDest, yDest) * 10; //A*
}

void Node::nextLevel(const int & i)
{
	level += (dir == 8 ? (i % 2 == 0 ? 10 : 14) : 10);
}

const int & Node::estimate(const int & xDest, const int & yDest) const
{
	static int xd, yd, d;
	xd = xDest - xPos;
	yd = yDest - yPos;

	// Manhattan distance
	d = abs(xd) + abs(yd);



	return(d);
}
