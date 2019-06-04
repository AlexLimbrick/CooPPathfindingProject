/*

  All code has been written by Karsten Vermeulen and may be used freely by anyone. It is by no
  means perfect and there is certainly room for improvement in some parts. As a whole, the code
  has been created as part of an engine for the purposes of educating other fellow programmers,
  and anyone else wishing to learn C++ and OOP. Feel free to use, copy, break, update and do as
  you wish with this code - it is there for all!

  UPDATED : February 2017

  -----------------------------------------------------------------------------------------------

- This is the main starting point for the game demo. The main game state is created here and added
  to the main game manager, from where it is run. Change the screen width and height accordingly, 
  and feel free to add more game states.

*/

//include SDL main header file to prevent 
//main lib conflicts in Release mode
#include <SDL.h> 

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "Game.h"
#include "Tools.h"



Tools tool;
string Name;
int Width;
int Height;
bool Fullscreen;
//------------------------------------------------------------------------------------------------------
//main function that processes everything  
//------------------------------------------------------------------------------------------------------
int main(int argc, char* args[])
{
	fstream File;
	
	File.open("Assets/Data_Files/Game.ini", ios_base::in);
	if (!File)
	{
		cout << "FILE NOT FOUND" << endl;
	}
	string data;
	int i = 0;
	while (!File.eof())
	{
		i++;
		getline(File, data);
		switch (i)
		{
		case 1:
			Name = tool.GetText("Name", data);
			break;
		case 2:
			Width = tool.GetData("Width", data);
			break;
		case 3:
			Height = tool.GetData("Height", data);
			break;
		case 4:
			Fullscreen = tool.GetData("Fullscreen", data);
			break;
		}
	}
	File.close();
	TheGame::Instance()->Initialize(Name, 960,960,false);
	TheGame::Instance()->Run();
	TheGame::Instance()->ShutDown();
	
	return 0;

}