
#ifndef GAME_MGR_H
#define GAME_MGR_H

#include <memory>
#include "GameModel.h"


class GameManager
{
public:

	static GameManager* GetInstance()
	{
		static GameManager sInstance;
		return &sInstance;
	}

	void OnHandleDown();
	void OnHandleUp();
	void OnHandleRight();
	void OnHandleLeft();

	GameBoard GetGameBoard();

private:

	GameManager();
	GameManager(const GameManager&) = delete;
	GameManager& operator= (const GameManager&) = delete;

	std::unique_ptr<GameModel> mSpGameModel;
};

#endif //GAME_MGR_H
