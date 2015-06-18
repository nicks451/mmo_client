#include "MainGame.h"
#include <iostream>


MainGame::MainGame()
{
	_window = nullptr;
	_screenWidth = 1024;
	_screenHeight = 768;
	_gameState = GameState::PLAY;
}


MainGame::~MainGame()
{
}

void MainGame::run()
{
	int initSuccess = initSystems();
	if (initSuccess < 0) {
		return;
	}
	gameLoop();
	
}

int MainGame::initSystems()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	_window = SDL_CreateWindow("Hello World!", 100, 100, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
	if (_window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return -1;
	}
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT) {
		processInput();
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event)) {

		switch (event.type) {
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		}
	}
}
