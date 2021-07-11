#ifndef GAME_MODEL_H
#define GAME_MODEL_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <random>
#include <memory>

using GameBoard = std::vector<std::vector<int>>;

class GameModel
{
public:

	GameModel();

	GameBoard GetGameBoard();

	void OnHandleDown();
	void OnHandleUp();
	void OnHandleRight();
	void OnHandleLeft();

	void GenerateNewNumber();

private:

    /*
	 * Cells are numbered from 0 to 15 row wise for our understanding
	 * rather than sending a pair of ints denoting (i,j)
	 */
	std::vector<int> GetEmptyCells();

	void Compress(std::vector<int>& input);
	int  GenerateCellNumber();
	bool GetRandomEmptyCell(const std::vector<int>& cells, int& pos);

	bool mGameEnded;
	std::unique_ptr<GameBoard> mSpGameBoard;

};

#endif //GAME_MODEL_H
