#include "AIController.h"



AIController::AIController()
{
	AICount ++;
}


AIController::~AIController()
{
}

string AIController::pathFind(/*int Grid[10][10], */const float & xStart, const float & yStart,
	const float & xFinish, const float & yFinish,bool coop)
{
		if (coop)
		{
			cycleCount++;
			return Pathfinding::Instance()->pathFindCooP(xStart, yStart, xFinish, yFinish);
		}
		else
		{
			cycleCount++;
			return Pathfinding::Instance()->pathFind(xStart, yStart, xFinish, yFinish);
		}
		
	
	
	
}


void AIController::Update()
{
}
