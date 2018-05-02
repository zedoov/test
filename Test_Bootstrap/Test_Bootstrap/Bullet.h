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
	~Bullet();






private:
	glm::vec2* m_pos;
	aie::Texture* m_texture;
};

