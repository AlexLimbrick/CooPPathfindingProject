#include "Level_1.h"
#include "Game.h"

#include <fstream>

Level_1::Level_1(GameState* _PrevState) :GameState(_PrevState)
{
	
	

	string tex;
	for (int y = 0; y < 15; y++)
	{
		for (int x = 0; x < 15; x++)
		{
			tex = to_string(map[y][x]);
			Tiles.push_back(new Tile(tex,x*64,y*64));
		}
	}
	
	for (int i = 0; i < 6; i++)
	{
		
		bool notSet = true;
		AI.push_back(new Enemy);
		while (notSet)
		{
			
			int y = rand() % 15;
			int x = rand() % 15;
			if (map[y][x] == 5)
			{
				AI[i]->setWorldPosition(glm::vec2(x*64, y*64));
				notSet = false;
			}
		}
		
		
		
	}
	
	isAlive = true;
	isActive = true;
	Pathfinding::Instance()->UpdateMap(map);
}


Level_1::~Level_1()
{
	 //delete my game objects
	for (auto t : Tiles)
	{
		delete t;

	}
	for (auto a : AI)
	{
		delete a;
	}
	AI.clear();
	Tiles.clear();
	
}

bool Level_1::Update()
{
	//check for input
	TheScreen::Instance()->Update();

	//update input handling by listening for input events
	
	for (auto& it : AI)
	{
		it->Update(AI);
		Pathfinding::Instance()->UpdateMap(map);
	}
	AIatGoal = 0;
	for (auto& it : AI)
	{
		if (it->getWorldPos() == glm::vec2(64,64))
		{
			AIatGoal++;
		}
	}
	if (AIatGoal == AI[0]->count)
	{
		for (auto& it : AI)
		{
			bool notSet = true;
			while (notSet)
			{

				int y = rand() % 15;
				int x = rand() % 15;
				if (map[y][x] == 5)
				{
					it->setWorldPosition(glm::vec2(x * 64, y * 64));
					notSet = false;
				}
			}
		}
		Pathfinding::Instance()->UpdateMap(map);
	}
	TheInput::Instance()->Update();
	Pathfinding::Instance()->resetPaths();
	
	return false;
}

bool Level_1::Draw()
{
	//draw my game objects
	for (auto _it = Tiles.begin(); _it != Tiles.end(); _it++)
	{
		(*_it)->Draw();
	}
	
	for (auto& it : AI)
	{
		it->Draw();
	}
	
	
	return false;
}
