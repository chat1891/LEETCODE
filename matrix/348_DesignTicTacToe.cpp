#include <vector>


/*
**Intuition**
- Update row, column, diagonal, anti diagonal for each move with player's score.
- player1 is 1, palyer2 is -1
- Check if any score sums to n or -n for winning
- return 0 for no winner

**Complexity**
- Time: O(1), every move we mark row, col, dia, anti dia
- Space: O(n), rows, cols are size of n
*/


class TicTacToe
{
public:
    int n;
    std::vector<int> rows; //sum score in each row
    std::vector<int> cols; ////sum score in each col
    int dia = 0;
    int antiDia = 0;
    int totalMove = 0;

    TicTacToe(int n)
    {
        this->n = n;
        rows = std::vector<int>(n);
        cols = std::vector<int>(n);
    }

    int move(int row, int col, int player)
    {
        totalMove++;
        int score = player == 1 ? 1 : -1;

        //update score in each row and col
        rows[row] += score;
        cols[col] += score;
        //update score in diagonal
        if (row + col == n - 1)
        {
            antiDia += score;
        }
        //update score in anti diagonal
        if (row == col)
        {
            dia += score;
        }

        //check if score sums to n, which means there is a winner
        if (abs(rows[row]) == n || abs(cols[col]) == n || abs(dia) == n || abs(antiDia) == n)
        {
            return player;
        }

        return 0;

    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */