#include "GameManager.h"

GameManager::GameManager()
{
	mSpGameModel = std::make_unique<GameModel>();
}

void GameManager::OnHandleDown()
{
	mSpGameModel->OnHandleDown();
	mSpGameModel->GenerateNewNumber();
}

void GameManager::OnHandleUp()
{
	mSpGameModel->OnHandleUp();
	mSpGameModel->GenerateNewNumber();
}

void GameManager::OnHandleRight()
{
	mSpGameModel->OnHandleRight();
	mSpGameModel->GenerateNewNumber();
}

void GameManager::OnHandleLeft()
{
	mSpGameModel->OnHandleLeft();
	mSpGameModel->GenerateNewNumber();
}

GameBoard GameManager::GetGameBoard()
{
	return mSpGameModel->GetGameBoard();
}