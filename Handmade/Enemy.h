#pragma once
#include "GameObject.h"
#include "Sprite.h" 
#include "AABB.h"
#include "AIController.h"
#include <vector>

class Enemy :
	public GameObject
{
public:
	Enemy();
	~Enemy();
	static int count;
	
	virtual void Draw() override;
	virtual void Update() override;
	virtual void Update(vector<Enemy*> buds);
	void setAlive(bool _alive) { isAlive = _alive; }
	AABB getBound() { return box; }
	int getDamage() { return damage; }
	void setTarget(glm::vec2 _target) { target = _target; }
	
	
private:
	AIController brain;
	Sprite enemy;
	static int tileSize;

	bool dir;
	int damage;
	int id;
	AABB box;

	glm::vec2 target;
	glm::vec2 vector;
	int grid[10][10];
	int i;
	int wait = 64;
	string route;
	bool getRoute = true;
	bool CooPPath = false;
	int routeCounter;

	int lastPosX;
	int lastPosy;
};

