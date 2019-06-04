#include "Enemy.h"
#include <fstream>
#include <iostream>
#include <random>

Enemy::Enemy()
{
	
	// set up the enemies sprite
	if (count == 0)
	{
		TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/Circle.png", "ENEMY_IMAGE");
		TheTexture::Instance()->LoadTextureFromFile("Assets/Sprites/CircleCooP.png", "CooP_IMAGE");
	}
	
	enemy.SetTexture("ENEMY_IMAGE");

	enemy.SetSpriteDimension(64, 64);
	enemy.SetTextureDimension(1, 1, 800, 900);
	//set up the enemies hit box
	box.SetDimension(64, 64);
	
	//set the enemies position and that its alive as well as the hit boxes position
	
	
	box.SetPosition(position.x, position.y);

	//set the enemies damage
	count++;
	id = count;
	
}


Enemy::~Enemy()
{
	count--;
}


void Enemy::Draw()
{
	//draw the enemy
	if (isAlive)
	{
		enemy.Draw(worldPos.x,worldPos.y,0, Sprite::NO_FLIP);
	}
}

void Enemy::Update()
{
}

void Enemy::Update(std::vector<Enemy*> buds)
{
	bool last = CooPPath;
	CooPPath = false;
	enemy.SetTexture("ENEMY_IMAGE");
	for (auto& i : buds)
	{
		if (i != this)
		{
			if ((glm::distance(worldPos, i->worldPos) / 64) <=2)
			{
				CooPPath = true;
				enemy.SetTexture("CooP_IMAGE");
			}
		}
	}
	
	if (wait <= 0&&!getRoute)
	{
		if (last != CooPPath && last == true)
		{
			getRoute = true;

		}

		if (CooPPath)
		{
			getRoute = true;
			
		}
		else if (routeCounter != (route.length()-1))
		{
			routeCounter++;
		}
		else 
		{
			getRoute = true;
			
		}
		wait = 64;
		
	}
	if (getRoute)
	{
		
		route = brain.pathFind(worldPos.x / 64, worldPos.y / 64, 1, 1,CooPPath);
		
			getRoute = false;
			
		
		
		
		lastPosX = worldPos.x / 64;
		lastPosy = worldPos.y / 64;
		routeCounter = 0;
	}
	cout << to_string(id)+" : "+route << endl;
	if (!route.empty())
	{
		if (route.at(routeCounter) == '0')
		{
			worldPos.x++;
		}
		if (route.at(routeCounter) == '1')
		{
			worldPos.y++;
		}
		if (route.at(routeCounter) == '2')
		{
			worldPos.x--;
		}
		if (route.at(routeCounter) == '3')
		{
			worldPos.y--;
		}
		
	}
	
	
	
	cout << to_string(id) + " : " + to_string(worldPos.x) << worldPos.y<< endl;
	box.SetPosition(worldPos.x,worldPos.y);
	wait--;
}


