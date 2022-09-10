#include "Bat.h"

//This is constructor it is called when we create an object
Bat::Bat(float startX, float startY)
{
	m_Position.x = startX;
	m_Position.y = startY;

	m_Shape.setSize(sf::Vector2f(50, 5));
	m_Shape.setPosition(m_Position);

}

FloatRect Bat::getPosition()
{
	return m_Shape.getGlobalBounds();
}

RectangleShape Bat::getShape()
{
	return m_Shape;
}

void Bat::moveLeft()
{
	m_MoveLeft = true;
}

void Bat::moveRight()
{
	m_MoveRight = true;
}

void Bat::stopLeft()
{
	m_MoveLeft = false;
}

void Bat::stopRight()
{
	m_MoveRight = false;
}

void Bat::update(Time dt)
{
	if (m_MoveLeft)
	{
		m_Position.x -= m_Speed * dt.asSeconds();
	}
	if (m_MoveRight)
	{
		m_Position.x += m_Speed * dt.asSeconds();
	}
	m_Shape.setPosition(m_Position);
}