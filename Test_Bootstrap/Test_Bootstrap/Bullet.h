#pragma once
#include <glm\vec2.hpp>




namespace aie {
	class Texture;
	class Renderer2D;
	class Input;
}

class Bullet
{
public:
	Bullet();
	Bullet(glm::vec2* pos);
	~Bullet();

	void Update(float deltaTime, aie::Input* input);
	void Draw(aie::Renderer2D* spriteBatch);


private:
	glm::vec2* m_pos;
	aie::Texture* m_texture;
};

