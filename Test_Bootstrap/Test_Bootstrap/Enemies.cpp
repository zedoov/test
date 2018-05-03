#include "Enemies.h"


Enemies::Enemies()
{
}

Enemies::Enemies(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/rock_medium.png");
	m_pos = pos;
}

Enemies::~Enemies()
{
	delete m_texture;
}

void Enemies::Update(float deltaTime)
{
	m_pos->y -= 150.0f * deltaTime;
}

void Enemies::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y, 35, 45);
}
