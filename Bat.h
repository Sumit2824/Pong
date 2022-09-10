#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Bat
{
public:
	Bat(float startX, float startY);
	FloatRect getPosition();
	RectangleShape getShape();
	void moveLeft();
	void moveRight();
	void stopLeft();
	void stopRight();
	void update(Time dt);

private:
	Vector2f m_Position;

	//A rctangleShape Object
	RectangleShape m_Shape;

	float m_Speed = 1000.0f;
	bool m_MoveRight = false;
	bool m_MoveLeft = false;

};
/*
Bat::Bat()
{
}

Bat::~Bat()
{
}
*/