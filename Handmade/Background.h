#pragma once
#include "GameObject.h"
#include "Audio.h"
#include "Sprite.h" 

class Background :
	public GameObject
{
public:
	Background(string _file);
	virtual ~Background();

	

	// Inherited via GameObject
	virtual void Draw() override;

	virtual void Update() override;

private:

	Audio music;
	Sprite image;

	string texID;
};

