#pragma once
#include <glm\vec2.hpp>
#include <Renderer2D.h>
#include <Texture.h>



namespace aie {
	class Texture;
	class Renderer2D;

}

class Enemies
{
public:
	Enemies();
	Enemies(glm::vec2* pos);
	~Enemies();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* spriteBatch);
	
	glm::vec2* GetPos();

private:
	glm::vec2* m_EnPos;
	aie::Texture* m_texture;
};

