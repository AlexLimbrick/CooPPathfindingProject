#ifndef PATHFIND_H
#define PATHFIND_H


#include "Singleton.h"
#include "Node.h"
#include <iostream>
#include <string>
class Pathfind
{
public:
	friend class Singleton<Pathfind>;

	string pathFind(const float & xStart, const float & yStart, const float & xFinish, const float & yFinish);//Returns a path for AI to follow Experiment with it as up down left right may be different for you
	string pathFindCooP(const float & xStart, const float & yStart, const float & xFinish, const float & yFinish);//Returns a path for AI to follow Experiment with it as up down left right may be different for you
	void UpdateMap(int _Grid[15][15]);//updates the array "Grid" with the map for the level game must be grid/tile based for this pathfinding to work
	void resetPaths();
	

private:
	Pathfind();
	Pathfind(const Pathfind&);
	Pathfind& operator=(const Pathfind&);
	
	int Grid[15][15][40];
	int paths[15][15][40];
	
	Node * n0;
	Node* m0;
	string route;
	
	int Closed[15][15][40];
	int Open[15][15][40];
	int dir = 4; //Number of possible directions to go at any position//
	int dx[4] = { 1, 0, -1, 0 };
	int dy[4] = { 0, 1,  0,-1 };
};
typedef Singleton<Pathfind> Pathfinding;
#endif