#include "Background.h"
#include "TextureManager.h"
#include "AudioManager.h"


Background::Background(string _file)
{
	//load the background picture
	
	
	//Set Properties
	string file = _file;
	image.SetTexture("Space");
	image.SetSpriteDimension(7680, 4320);
	image.SetTextureDimension(1,1, 7680, 4320);
	//TheAudio::Instance()->LoadFromFile("Assets/Audio/"+file, AudioManager::MUSIC_AUDIO, _file);
	music.SetAudio(_file, Audio::MUSIC_AUDIO);
	music.SetVolume(100);
	music.Play(Audio::PLAY_ENDLESS);

	

}

void Background::Draw()
{
	// draw the background
	image.Draw(worldPos.x,worldPos.y);

}

void Background::Update()
{
}


Background::~Background()
{
	
	//delete its texture
	
}
