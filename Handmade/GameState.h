#pragma once
#include "Background.h"
#include "InputManager.h"
#include "Background.h"

#include "Enemy.h"

#include "TextureManager.h"
#include "ScreenManager.h"
#include "Tile.h"

#include <deque>
#include <string>
#include <list>
#include <SDL.h> 
#include <iostream>
#include <string>
#include <vector>

using namespace std;
class GameState
{
public:
	GameState(GameState* _PrevState) { PrevState = _PrevState; }
	virtual ~GameState() = 0 {}

	virtual bool Draw() = 0;
	virtual bool Update() = 0;

	bool& getActive() { return isActive; }
	bool& getAlive() { return isAlive; }
	void setAlive(bool _newValue) {	isActive = isAlive = _newValue;	}

protected:
	static int tileSize;
	bool isActive;
	bool isAlive;

	GameState* PrevState;

};

