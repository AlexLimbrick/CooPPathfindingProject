#pragma once
#include <string>
#include <glm.hpp>
#include "TextureManager.h"
#include "Tools.h"
//using namespace std;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject() = 0 {}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	void setPosition(glm::vec2 _position) { position = _position; }
	void setWorldPosition(glm::vec2 _worldPos) { worldPos = _worldPos; }
	void setAngle(float _angle) {angle = _angle; }
	void setSize(glm::vec2 _size) { size = _size; }
	void setID(string _ID) { ID = _ID; }
	void setScreen(glm::vec2 _screen) { s_width = _screen.x; s_height = _screen.y; }


	void setAlive(bool _alive) { isAlive = _alive; }
	void setActive(bool _active) { isActive = _active; }
	void setvisible(bool _visible) { isVisible = _visible; }

	glm::vec2 getPosition() { return position; }
	glm::vec2 getWorldPos() { return worldPos; }
	float getAngle() { return angle; }
	glm::vec2 getSize() { return size; }

	bool Alive() { return isAlive; }
	bool Active() { return isActive; }
protected:
	Tools tool;
	glm::vec2 position;
	float angle;
	glm::vec2 size;
	string ID;
	glm::vec2 worldPos;
	
	bool isAlive = true;
	bool isActive = true;
	bool isVisible = true;

	int s_width; // screen width
	int s_height; // screen height

	int width;
	int height;

	int texW;
	int texH;

	string sprite;
};

