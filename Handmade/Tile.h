#pragma once
#include "GameObject.h"
#include "Sprite.h" 
class Tile :
	public GameObject
{
public:
	Tile(string tex_ID = "11",int x = 0,int y = 0);

	// Inherited via GameObject
	virtual void Draw() override;

	virtual void Update() override;

	virtual ~Tile();
private:
	Sprite tile;

};

