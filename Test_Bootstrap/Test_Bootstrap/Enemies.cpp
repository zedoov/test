#include "Enemies.h"
#include <ctime>
#include <stdlib.h>

Enemies::Enemies()
{
}

Enemies::Enemies(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/rock_medium.png");
	m_EnPos = pos;
}

Enemies::~Enemies()
{
	delete m_texture;
}

void Enemies::Update(float deltaTime)
{

	m_EnPos->y -= 100.0f * deltaTime;
}

void Enemies::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_EnPos->x, m_EnPos->y, 35, 45);
}

glm::vec2 * Enemies::GetPos()
{
	return m_EnPos;
}
