#include "Game.h"



int Enemy::count = 0;
int AIController::AICount = 0;
int AIController::lastCycle = 0;
int AIController::cycleCount=0;
Game::Game()
{
}


Game::~Game()
{
}

bool Game::Initialize(string _Name,int _ScreenWidth, int _ScreenHeight, bool _Fullscreen)
{
	
	// initialize random
	srand(time(NULL));

	//initialise game screen and background rendering color
	TheScreen::Instance()->Initialize(_Name.c_str(), _ScreenWidth, _ScreenHeight, _Fullscreen);
	TheScreen::Instance()->SetClearColor(100, 149, 237);

	//initialize audio
	TheAudio::Instance()->Initialize();
	TheTexture::Instance()->Initialize();
	screenHeight = _ScreenHeight;
	screenWidth = _ScreenWidth;
	
	// load textures
	TheTexture::Instance()->LoadFontFromFile("Assets/Fonts/Impact.ttf", 100, "FONT");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/1.png", "1");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/2.png", "2");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/3.png", "3");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/4.png", "4");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/5.png", "5");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/6.png", "6");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/7.png", "7");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/8.png", "8");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/9.png", "9");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/10.png", "10");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/11.png", "11");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/12.png", "12");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/13.png", "13");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/14.png", "14");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/15.png", "15");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/16.png", "16");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/17.png", "17");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/18.png", "18");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/19.png", "19");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/20.png", "20");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/21.png", "21");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/22.png", "22");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/23.png", "23");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/24.png", "24");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/25.png", "25");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/26.png", "26");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/27.png", "27");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/28.png", "28");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/29.png", "29");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/30.png", "30");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/31.png", "31");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/32.png", "32");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/33.png", "33");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/34.png", "34");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/35.png", "35");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/36.png", "36");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/37.png", "37");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/38.png", "38");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/39.png", "39");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/40.png", "40");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/41.png", "41");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/42.png", "42");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/43.png", "43");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/44.png", "44");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/45.png", "45");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/46.png", "46");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/47.png", "47");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/48.png", "48");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/49.png", "49");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/50.png", "50");
	TheTexture::Instance()->LoadTextureFromFile("Assets/Tiles/51.png", "51");
	
	// set up my state machine
	AddState(new Level_1(nullptr));
	
	Frames.SetFont("FONT");
	Frames.SetText("Frames");
	Frames.SetColor(255, 255, 255);
	Frames.SetSize(100, 50);
	
	
	return false;
}

bool Game::Run()
{
	
	int frame = 0;

	int startTime = GetTotalTime();


	//main game loop!
	while (!endGame)
	{

		CurState = State.front();

		while (CurState->getActive())
		{
			
			
			// update
			string ET = to_string(elapsedTime);
			Frames.SetText(ET);
			CurState->Update();
		

		
			// check if escape is pressed
			keys = TheInput::Instance()->GetKeyStates();
			if (keys[SDL_SCANCODE_ESCAPE]||TheInput::Instance()->IsXClicked())
			{
				endGame = true;
				CurState->setAlive(false);
			}

			//draw things and stuff
			
			CurState->Draw();
			Frames.Draw(100, 100);
			TheScreen::Instance()->Draw();
			frame ++;
			elapsedTime = (frame / (float)(GetTotalTime() - startTime)) * 1000;
		}

		if (!CurState->getAlive())
		{
			RemoveState();
		}
		endGame = State.empty();

		
		
	}
	
	

	
	//end application
	return false;
}

void Game::ShutDown()
{	
	
	//remove data from my deque of states
	
	State.clear();
	// unload textures
	TheTexture::Instance()->UnloadFromMemory(TextureManager::TEXTURE_DATA, TextureManager::ALL_DATA);
	TheTexture::Instance()->UnloadFromMemory(TextureManager::FONT_DATA, TextureManager::ALL_DATA);
	TheAudio::Instance()->UnloadFromMemory(AudioManager::MUSIC_AUDIO, AudioManager::ALL_AUDIO);
	TheAudio::Instance()->ShutDown();

	//close down game screen 
	TheScreen::Instance()->ShutDown();
	TheTexture::Instance()->ShutDown();
	
	
}

void Game::AddState(GameState * _state)
{
	State.push_front(_state);
}

void Game::ChangeState(GameState * _state)
{

	State.push_back(_state);
}

void Game::RemoveState()
{
	
	delete State.front();
	
	State.pop_front();
}
