#pragma once

#include "Application.h"
#include "Renderer2D.h"

class Player;

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
	Player*				m_player;
};