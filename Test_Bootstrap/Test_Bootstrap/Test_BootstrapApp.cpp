#include "Test_BootstrapApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "Player.h"
#include "Bullet.h"
#include "Enemies.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <imgui.h>

bootstrapTestApp::bootstrapTestApp() {

}

bootstrapTestApp::~bootstrapTestApp() {

}

bool bootstrapTestApp::startup() {
	
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	srand(time(NULL));

	m_timer = 0;
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 18);
	
	m_player =	new Player(new glm::vec2(640, 340));
	m_bullet =	new Bullet(new glm::vec2(640, 390));
	playerDead = false;
	
	//spawning enemies
	for (int i = 0; i < 40; ++i)
	{
		m_enemies.push_back(new Enemies(new glm::vec2(rand() % 1280, rand() % 2000 + 720)));
	}
		
	
	return true;
}

void bootstrapTestApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	if (m_player != nullptr)
	{
		delete m_player;
	}
	delete m_bullet;
	
	

}

void bootstrapTestApp::update(float deltaTime) {
	
	m_timer += deltaTime;
	m_iFrames -= deltaTime;
	// input example
	aie::Input* input = aie::Input::getInstance();


	for (auto enemy : m_enemies)
	{
		enemy->Update(deltaTime);
	}

	//m_enemies->Update(deltaTime);

	if (!playerDead)
	{
		m_player->Update(deltaTime, input);
	}
	m_bullet->Update(deltaTime, input);
	
	//when an enemy is within a specified distance between the player set the bool true
	for (auto enemy : m_enemies)
	{
		float distX = enemy->GetPos()->x - m_player->GetPos()->x;
		float distY = enemy->GetPos()->y - m_player->GetPos()->y;
		if (distX < 30 && distY < 40 && distX > -30 && distY > -40)
		{
			if (m_iFrames < 0)
			{
				m_player->SetHealth(m_player->GetHealth() - 10);
				m_iFrames = 0.75f;
			}

		}
	}


	if (m_player->GetHealth() == 0)
	{
		playerDead = true;
	}

//	for (auto enemy : m_enemies)
//	{
//		float distX = enemy->GetPos()->x - m_bullet->GetPos()->x;
//		float distY = enemy->GetPos()->y - m_bullet->GetPos()->y;
//		if (distX < 15 && distY < 15 && distX > -15 && distY > -15)
//		{
//			  ;
//		}
//	}
	

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
	ImGui::Begin("test");
	ImGui::Text("Heath: %i", m_player->GetHealth());
	ImGui::End();

	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 5, 5);
	m_2dRenderer->drawText(m_font, "WASD to move, space to blink, arrow keys to move the bullet", 5, 705);
	
	//draws the player if he isnt dead
	m_bullet->Draw(m_2dRenderer);
	if (!playerDead)
	{
		m_player->Draw(m_2dRenderer);
	}
	if (playerDead)
	{
		m_2dRenderer->drawText(m_font, "Game Over", 600, 360, 10);
	}

	for (auto enemy : m_enemies)
	{
		enemy->Draw(m_2dRenderer);
	}

	//m_enemies->Draw(m_2dRenderer);
	// done drawing sprites
	m_2dRenderer->end();
}