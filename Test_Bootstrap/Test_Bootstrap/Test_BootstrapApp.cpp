#include "Test_BootstrapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemies.h"
#include <ctime>
#include <stdlib.h>

bootstrapTestApp::bootstrapTestApp() {

}

bootstrapTestApp::~bootstrapTestApp() {

}

bool bootstrapTestApp::startup() {
	
	srand(time(NULL));

	m_timer = 0;

	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 18);

	m_player = new Player(new glm::vec2(640, 340));
	m_bullet = new Bullet(new glm::vec2(640, 390));
	m_enemies = new Enemies(new glm::vec2(rand() % 1280, 720));
	return true;
}

void bootstrapTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_player;
	delete m_bullet;
	delete m_enemies;
}

void bootstrapTestApp::update(float deltaTime) {

	m_timer += deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();

	m_player->Update(deltaTime, input);
	m_bullet->Update(deltaTime, input);
	m_enemies->Update(deltaTime);


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
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 5);
	m_2dRenderer->drawText(m_font, "Use WASD to move, space to blink, arrow keys to move the bullet", 5, 705);
	m_bullet->Draw(m_2dRenderer);
	m_player->Draw(m_2dRenderer);
	m_enemies->Draw(m_2dRenderer);
	// done drawing sprites
	m_2dRenderer->end();
}