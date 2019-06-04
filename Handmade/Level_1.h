#pragma once
#include "Text.h"
#include "GameState.h"
class Level_1 :
	public GameState
{
public:
	Level_1(GameState* _PrevState);
	virtual ~Level_1();

	// Inherited via GameState
	virtual bool Update() override;
	virtual bool Draw() override;

private:
	glm::vec2 worldPos;

	vector<GameObject*>Tiles;
	vector<Enemy*>AI;
	/*Enemy test;
	Enemy test2;
	Enemy test3;
	Enemy test4;
	Enemy test5;*/
	
	int map[15][15]
	{
		{23,23,23,23,23,23,23,23,23,23,23,23,23,23,23,},
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,23,23,23,5 ,23,23,23,23,23,23,23,5,23,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,23,23,23,5 ,23,23,23,23,23,23,23,5,23,23 },
		{ 23,23,23,23,5 ,23,23,23,23,23,23,23,5,23,23 },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23  },
		{ 23,5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 ,23,23,5 ,5 ,5 ,23  },
		{ 23,23,23,23,23 ,23,23,23,23,23,23,23,23,23,23  },
		 
	};
	
	const Uint8* keys = nullptr;
	int AIatGoal;
	int wait;
};

