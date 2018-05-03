#include "Bullet.h"
#include "Player.h"



Bullet::Bullet()
{
}

Bullet::Bullet(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/ball.png");
	m_pos = pos;
}

Bullet::~Bullet()
{
	delete m_texture;
}

void Bullet::Update(float deltaTime, aie::Input * input)
{
	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
	{
		m_pos->x -= 300.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
	{
		m_pos->x += 300.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_UP))
	{
		m_pos->y += 300.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
	{
		m_pos->y -= 300.0f * deltaTime;
	}
}

void Bullet::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y, 15, 15);
}
