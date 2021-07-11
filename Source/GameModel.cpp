
#include "GameModel.h"

GameModel::GameModel() : mGameEnded(false)
{
    mSpGameBoard.reset(new GameBoard(4, std::vector<int>(4)));

    //Put 2 numbers on the board
    GenerateNewNumber();
    GenerateNewNumber();
}

GameBoard GameModel::GetGameBoard()
{
    if (!mSpGameBoard.get())
        return GameBoard{};

    return *mSpGameBoard;
}

std::vector<int> GameModel::GetEmptyCells()
{
    std::vector<int> cells;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if ((*mSpGameBoard)[i][j] == 0)
                cells.push_back(i * 4 + j);
        }
    }

    return cells;
}

bool GameModel::GetRandomEmptyCell(const std::vector<int>& cells, int& pos)
{
    if (cells.empty())
    {
        pos = -1;
        return false;
    }

    static std::random_device dev;
    static std::mt19937       Engine(dev());
    std::uniform_int_distribution<int> SampleSpace(0, static_cast<int>(cells.size()) - 1);

    int index = SampleSpace(Engine);

    pos = cells[index];
    return true;
}

int GameModel::GenerateCellNumber()
{
    static std::random_device dev;
    static std::mt19937       Engine(dev());
    static std::uniform_int_distribution<int> SampleSpace(0, 1);

    int res = SampleSpace(Engine);
    if (res == 0)
        return 2;
    else
        return 4;
}

void GameModel::GenerateNewNumber()
{
    auto emptyCells = GetEmptyCells();

    int pos = 0;
    if (!GetRandomEmptyCell(emptyCells, pos))
    {
        //callout that the game may need to end;
        mGameEnded = true;
        return;
    }

    int x = pos / 4;
    int y = pos % 4;

    (*mSpGameBoard)[x][y] = GenerateCellNumber();
}

void GameModel::OnHandleDown()
{
    for (int j = 0; j < 4; j++)
    {
        std::vector<int> temp;
        for (int i = 3; i >= 0; i--)
            temp.push_back((*mSpGameBoard)[i][j]);

        //Compress
        Compress(temp);

        //Put the values back in

        for (int i = 3; i >= 0; i--)
            (*mSpGameBoard)[i][j] = temp[3 - i];
    }
}

void GameModel::OnHandleUp()
{
    for (int j = 0; j < 4; j++)
    {
        std::vector<int> temp;
        for (int i = 0; i < 4; i++)
            temp.push_back((*mSpGameBoard)[i][j]);

        //Compress
        Compress(temp);

        //Put the values back in
        for (int i = 0; i < 4; i++)
            (*mSpGameBoard)[i][j] = temp[i];
    }
}

void GameModel::OnHandleLeft()
{
    for (int i = 0; i < 4; i++)
    {
        std::vector<int> temp;
        for (int j = 0; j < 4; j++)
            temp.push_back((*mSpGameBoard)[i][j]);

        //Compress
        Compress(temp);

        //Put the values back in
        for (int j = 0; j < 4; j++)
            (*mSpGameBoard)[i][j] = temp[j];
    }
}

void GameModel::OnHandleRight()
{
    for (int i = 0; i < 4; i++)
    {
        std::vector<int> temp;
        for (int j = 3; j >= 0; j--)
            temp.push_back((*mSpGameBoard)[i][j]);

        //Compress
        Compress(temp);

        //Put the values back in
        for (int j = 3; j >= 0; j--)
            (*mSpGameBoard)[i][j] = temp[3 - j];
    }
}

void GameModel::Compress(std::vector<int>& input)
{
    /*std::cout << "\nBefore Compression:\n";
    for (int k = 0; k < 4; k++)
    {
        std::cout << input[k] << " ";
    }*/

    int i, j;
    i = 0;
    j = 0;

    while (i < 4)
    {
        while (i < 4 && input[i] == 0)
            i++;

        if (i >= 4)
            break;

        input[j] = input[i];
        i++;
        j++;
    }

    while (j < i)
        input[j++] = 0;

    i = 0;
    while (i + 1 < 4)
    {
        if (input[i] != 0 && input[i] == input[i + 1])
        {
            //std::cout << "\n\ti:" << i << " " << input[i];
            input[i] = 2 * input[i];
            input[i + 1] = 0;
        }

        i++;
    }

    /* std::cout << "\n\tBefore Shifting 0s:\n";
     std::cout << "\n\t";
     for (int k = 0; k < 4; k++)
     {
         std::cout << input[k] << " ";
     }*/
     //lets move the 0s to the end
    i = 0;
    j = 0;

    while (i < 4)
    {
        while (i < 4 && input[i] == 0)
            i++;

        if (i >= 4)
            break;

        input[j] = input[i];
        i++;
        j++;
    }

    while (j < i)
        input[j++] = 0;

    /* std::cout << "\nAfter Compression:\n";
     for (int k = 0; k < 4; k++)
     {
         std::cout << input[k] << " ";
     }*/
}