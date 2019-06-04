#pragma once
#pragma once
#include <iostream>
#include <iomanip>
#include <queue>
#include <string>
#include <math.h>
#include <ctime>

using namespace std;

class Node
{
public:
	Node(int xp, int yp, int d, int p);
	~Node();

	int getxPos() const { return xPos; }
	int getyPos() const { return yPos; }
	int getLevel() const { return level; }
	int getPriority() const { return priority; }

	void updatePriority(const int & xDest, const int & yDest);

	void nextLevel(const int & i);

	const int & estimate(const int & xDest, const int & yDest) const;
private:
	// current position
	int xPos;
	int yPos;
	// total distance already travelled to reach the node
	int level;
	// priority=level+remaining distance estimate
	int priority;  // smaller: higher priority

	int dir = 4; // number of possible directions to go at any position
			 // if dir==4

	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1, 0, -1 };
	//bool operator<(Node & a) const;
	//bool Node::operator<(const Node & a) const;

	inline friend
		bool operator<(const Node& lhs, const Node& rhs)
	{
		return (lhs.getPriority() > rhs.getPriority());
	}
};

