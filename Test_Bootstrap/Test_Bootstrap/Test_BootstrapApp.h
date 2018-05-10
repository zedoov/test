#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include <vector>
class Player;
class Bullet;
class Enemies;


class bootstrapTestApp : public aie::Application {
public:

	bootstrapTestApp();
	virtual ~bootstrapTestApp();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:


	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	float				m_timer;
	float				m_iFrames;
	Player*				m_player;
	Bullet*				m_bullet;
	std::vector<Enemies*> m_enemies;
	bool playerDead;
};