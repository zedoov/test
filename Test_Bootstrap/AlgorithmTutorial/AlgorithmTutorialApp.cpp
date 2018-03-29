#include "AlgorithmTutorialApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

AlgorithmTutorialApp::AlgorithmTutorialApp() : m_isGameOver(false), m_currentPlayer(1) {

}

AlgorithmTutorialApp::~AlgorithmTutorialApp() {

}

bool AlgorithmTutorialApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	m_croissant = new aie::Texture("../bin/textures/croissant.png");
	m_cupcake = new aie::Texture("../bin/textures/cake.png");

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			m_board[i][j] = 0;
		}
	}

	return true;
}

void AlgorithmTutorialApp::shutdown() {

	delete m_font;
	delete m_2dRenderer;
	delete m_croissant;
	delete m_cupcake;
}

bool AlgorithmTutorialApp::checkForWin()
{
	//TO DO : complete this function
	for (int col = 0; col < COLUMNS; col++)
	{
		for (int row = 0; row < ROWS; row++)
		{
			if (m_board [row + 1][col] == row && m_board[row + 2][col] == row && m_board[row + 3][col] == row)
			{
				return true;
			}
			else if (m_board[row - 1][col] == row && m_board[row - 2][col] == row && m_board[row - 3][col] == row)
			{
				return true;
			}
			else if (m_board[row][col + 1] == col && m_board[row][col + 2] == col && m_board[row][col + 3] == col)
			{
				return true;
			}
			else if (m_board[row][col - 1] == col && m_board[row][col - 2] == col && m_board[row][col - 3] == col)
			{
				return true;
			}
			else if (m_board[row + 1][col + 1] == m_board[row][col] && m_board[row + 2][col + 2] == m_board[row][col] && m_board[row + 3][col + 3] == m_board[row][col])
			{
				return true;
			}
			else if (m_board[row - 1][col - 1] == m_board[row][col] && m_board[row - 2][col - 2] == m_board[row][col] && m_board[row - 3][col - 3] == m_board[row][col])
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
}

void AlgorithmTutorialApp::update(float deltaTime) {
	static int height = this->getWindowHeight();
	static int width = this->getWindowWidth();
	static bool wasMouseDown = false;

	// input example
	aie::Input* input = aie::Input::getInstance();

	if (!m_isGameOver) {
		if (input->isMouseButtonDown(0) && wasMouseDown == false)
		{
			int x = 0, y = 0;
			input->getMouseXY(&x, &y);

			float xInc = (width - (BORDER << 1)) / COLUMNS;
			int col = (x - BORDER) / xInc;

			if (col >= 0 && col < COLUMNS) {
				// find the lowest row and place a tile there
				for (int row = 0; row < ROWS; row++)
				{
					if (m_board[col][row] == 0) {
						m_board[col][row] = m_currentPlayer;

						m_currentPlayer = (m_currentPlayer == 1) ? 2 : 1;

						break;
					}
				}
			}
		}
		wasMouseDown = input->isMouseButtonDown(0);

		m_isGameOver = checkForWin();
	}

	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void AlgorithmTutorialApp::draw() {
	static int height = this->getWindowHeight();
	static int width = this->getWindowWidth();

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();

	// draw game board
	float xInc = (width - (BORDER << 1)) / COLUMNS;
	float yInc = (height - (BORDER << 1)) / ROWS;
	for (int x = 0; x <= COLUMNS; x++) {
		m_2dRenderer->drawLine(BORDER + x * xInc, BORDER + yInc * ROWS, BORDER + x * xInc, BORDER);
	}
	for (int y = 0; y <= ROWS; y++) {
		m_2dRenderer->drawLine(BORDER, BORDER + y * yInc, BORDER + xInc * COLUMNS, BORDER + y * yInc);
	}

	for (int i = 0; i < COLUMNS; i++) {
		for (int j = 0; j < ROWS; j++) {
			if (m_board[i][j] == 1) {
				m_2dRenderer->drawSprite(m_croissant, 50 + i * xInc, 50 + j * yInc, xInc, yInc, 0, 0, 0, 0);
			}
			else if (m_board[i][j] == 2) {
				m_2dRenderer->drawSprite(m_cupcake, 50 + i * xInc, 50 + j * yInc, xInc, yInc, 0, 0, 0, 0);
			}
		}
	}

	if (m_isGameOver) {
		m_2dRenderer->setRenderColour(1, 0, 0);
		m_2dRenderer->drawText(m_font, "GAME OVER", (width >> 1) - 50, height - 30);
	}
	else {
		if (m_currentPlayer == 1) {
			m_2dRenderer->setRenderColour(0, 1, 0);
			m_2dRenderer->drawText(m_font, "Player 1 go", 10, height - 30);
		}
		else {
			m_2dRenderer->setRenderColour(1, 0, 0);
			m_2dRenderer->drawText(m_font, "Player 2 go", 10, height - 30);
		}
	}

	// draw your stuff here!
	
	// output some text, uses the last used colour
	m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

	// done drawing sprites
	m_2dRenderer->end();
}


