#pragma once
#include <glm\vec2.hpp>
#include <Renderer2D.h>
#include <Texture.h>
#include <Input.h>

namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Player
{
public:
	Player();
	Player(glm::vec2* pos);
	~Player();

	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);

	void SetHealth(int health);
	int GetHealth();

	glm::vec2* GetPos();

private:
	glm::vec2* m_pos;
	aie::Texture* m_texture;
	int m_health;
};

