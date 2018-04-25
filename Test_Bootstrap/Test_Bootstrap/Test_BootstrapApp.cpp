#include "Test_BootstrapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"


bootstrapTestApp::bootstrapTestApp() {

}

bootstrapTestApp::~bootstrapTestApp() {

}

bool bootstrapTestApp::startup() {

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_player = new Player(new glm::vec2(100, 200));

	return true;
}

void bootstrapTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player;
}

void bootstrapTestApp::update(float deltaTime) {

	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime, input);


	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
	{
		quit();
	}
}

void bootstrapTestApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw your stuff here!


	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	m_player->Draw(m_2dRenderer);
	// done drawing sprites
	m_2dRenderer->end();
}