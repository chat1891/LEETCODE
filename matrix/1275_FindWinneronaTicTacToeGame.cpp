#include <vector>
#include <string>

/*
**Intuition**
- Update row, column, diagonal, anti diagonal for each move with player's score.
- player A is 1, palyer B is -1
- Check if any score sums to 3 or -3 for winning
- total have 9 moves, we have a Draw, otherwise it is Pending.

**Complexity**
- Time: O(m), m is number of moves
- Space: O(n)

*/
class Solution
{
public:
    std::string tictactoe(std::vector<std::vector<int>>& moves)
    {
        int n = 3;
        std::vector<int> cols(3); //save record of each row
        std::vector<int> rows(3); // save record of each col
        int diagonal = 0; //save record of diagonal
        int antiDiagonal = 0; //save record of anti diagonal
        int player = 1;

        //every move for each player count as 1 point
        //player A is 1, player B is -1
        for (auto& move : moves)
        {
            int row = move[0];
            int col = move[1];

            //add score of each player to that col and row
            rows[row] += player;
            cols[col] += player;

            //add score of each player to diagonal
            if (row == col)
            {
                diagonal += player;
            }

            //add score of each player to anti diagonal
            if (row + col == n - 1)
            {
                antiDiagonal += player;
            }

            //check if anyone wins
            //if a player wins, it means the score in a column, a row, diagonal or anti diagonal needs to be 3 for A or -3 for B
            //otherwise it is not 3 continuous move from one player
            if (abs(rows[row]) == n || abs(cols[col]) == n
                || abs(diagonal) == n || abs(antiDiagonal) == n)
            {
                if (player > 0) return "A";
                else return "B";
            }
            player *= -1;

        }

        return moves.size() == (n * n) ? "Draw" : "Pending";
    }
};