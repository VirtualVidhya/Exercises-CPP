#include <iostream>

void display_board(char board[][3])
{
    std::cout << "\nCurrent Game State:\n";
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << board[i][j] << " ";
        }

        std::cout << '\n';
    }
}

void update_board(char board[][3], int i, int j, char value)
{
    board[i][j] = value;
}

int main()
{
    char game_board[3][3] = {
        {'X', 'O', 'X'},
        {'.', '.', 'O'},
        {'X', '.', '.'},
    };

    display_board(game_board);

    update_board(game_board, 2, 1, 'O');

    display_board(game_board);

    return 0;
}