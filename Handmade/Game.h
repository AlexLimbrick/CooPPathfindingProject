#pragma once

#include <deque>
#include <string>
#include <list>
#include <SDL.h> 
#include <iostream>
#include <string>
#include <vector>
#include <ctime>

#include "Singleton.h"
#include "AudioManager.h"
#include "InputManager.h"
#include "ScreenManager.h"
#include "Background.h"

#include "Enemy.h"

#include "TextureManager.h"
#include "Text.h"


#include "GameState.h"
#include "Level_1.h"



class Game
{
public:
	Game();
	~Game();
	
	bool Initialize(string _Name,int _ScreenWidth, int _ScreenHeight,bool _Fullscreen);
	bool Run();
	void ShutDown();

	void AddState(GameState * _state);
	void ChangeState(GameState * _state);
	glm::vec2 GetScreen() { return glm::vec2(screenWidth, screenHeight); }
	
	bool endGame = false;

	int GetTotalTime() { return SDL_GetTicks(); }
	int GetElapsedTime() { return elapsedTime; }

private:
	deque<GameState*>State;
	GameState * CurState;
	const Uint8* keys = nullptr;

	void RemoveState();
	
	int elapsedTime;

	Text Frames;
	int screenWidth;
	int screenHeight;
	int tileSize = 64;
	
};

typedef Singleton<Game>TheGame;
