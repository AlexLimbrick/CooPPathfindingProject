/*A basic AI controller for tile / grid based games with behaviour tree functionality, this shouldnt ideally be used for all AI each AI should have its own AIController*/
#pragma once
#include <iostream>
#include <string>
#include "Node.h"
#include "BrainTree.h"
#include "Pathfind.h"


using namespace std;

class AIController
{
public:
	AIController();
	~AIController();
	string pathFind(const float & xStart, const float & yStart, const float & xFinish, const float & yFinish, bool coop);//Returns a path for AI to follow Experiment with it as up down left right may be different for you
	void Update();
	
	static int AICount;
	static int cycleCount;
	static int lastCycle;
private:
	int cycles = 1;

};

