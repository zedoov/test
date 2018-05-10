#include "Player.h"


Player::Player()
{
}

Player::Player(glm::vec2 * pos)
{
	m_texture = new aie::Texture("../bin/textures/ship.png");
	m_pos = pos;
	m_health = 100;
}

Player::~Player()
{
	delete m_texture;
}

void Player::Update(float deltaTime, aie::Input* input)
{
	if (input->isKeyDown(aie::INPUT_KEY_A))
	{
		m_pos->x -= 225.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D))
	{
		m_pos->x += 225.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_W))
	{
		m_pos->y += 225.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S))
	{
		m_pos->y -= 225.0f * deltaTime;
	}


	if (input->isKeyDown(aie::INPUT_KEY_A) && input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_pos->x -= 6000.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_D) && input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_pos->x += 6000.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_W) && input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_pos->y += 6000.0f * deltaTime;
	}
	if (input->isKeyDown(aie::INPUT_KEY_S) && input->wasKeyPressed(aie::INPUT_KEY_SPACE))
	{
		m_pos->y -= 6000.0f * deltaTime;
	}
}

void Player::Draw(aie::Renderer2D * spriteBatch)
{
	spriteBatch->drawSprite(m_texture, m_pos->x, m_pos->y, 60, 80);
}

void Player::SetHealth(int health)
{
	m_health = health;
}

int Player::GetHealth()
{
	return m_health;
}

glm::vec2 * Player::GetPos()
{
	return m_pos;
}