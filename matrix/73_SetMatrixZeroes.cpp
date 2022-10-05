#include<unordered_set>
#include<vector>

//logic:
//- flag first cell of col and row to 0 if found a zero cell
//-for matrix[0][0] which can be col or row, use isCol and isRow to identify
//visit again to update matrix which has first row/col = 0

//Time: O(M*N)
//Space: O(1)
class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool isCol = false;
        bool isRow = false;

        //falg first cell of col and row to 0 if found a zero cell
        for (int i = 0; i < rows; i++)
        {

            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;

                    // Since first cell for both first row and first column is the same i.e. matrix[0][0]
      // We can use an additional variable for either the first row/column.
      // and using matrix[0][0] for the first row. 
                    if (i == 0)
                    {
                        isRow = true;
                    }
                    if (j == 0)
                    {
                        isCol = true;
                    }
                }
            }
        }

        //visit again to update matrix
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < cols; j++)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }

            }
        }

        //check if first row is 0
        if (isRow)
        {
            for (int j = 0; j < cols; j++)
            {
                matrix[0][j] = 0;
            }
        }

        //check if first col is 0
        if (isCol)
        {
            for (int i = 0; i < rows; i++)
            {
                matrix[i][0] = 0;
            }
        }

    }
};


//logic:
//-We make a pass over our original array and look for zero entries. 
//record i and j
//pass matrix again, if contains i and j in the set, mark it to 0

//time: O(M * N) where M and N are the number of rows and columns respectively.
//Space: O(m+n)
class Solution_2
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        int rows = matrix.size();
        int cols = matrix[0].size();
        std::unordered_set<int> zeroRow;
        std::unordered_set<int> zeroCol;

        //mark rows and cols that is 0
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRow.insert(i);
                    zeroCol.insert(j);
                }

            }
        }

        //visit again to update matrix
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (zeroRow.find(i) != zeroRow.end() || zeroCol.find(j) != zeroCol.end())
                {
                    matrix[i][j] = 0;
                }

            }
        }

    }
};