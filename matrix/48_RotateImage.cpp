#include <vector>

class Solution
{
public:
    //https://www.youtube.com/watch?v=fMSJSS7eO1w
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int n = matrix.size();
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        while (left < right && top < bottom)
        {
            //from left to right-1
            for (int i = 0; i < (right - left); i++)
            {
                //use reverse order to rotate
                //save top left
                int temp = matrix[top][left + i];

                //move bottom left to top left
                matrix[top][left + i] = matrix[bottom - i][left];
                //move bottom right to bottom left
                matrix[bottom - i][left] = matrix[bottom][right - i];
                //move top right to bottom right
                matrix[bottom][right - i] = matrix[top + i][right];
                //move top left to top right
                matrix[top + i][right] = temp;
            }

            left++;
            right--;
            top++;
            bottom--;
        }
    }
};

class Solution_CCW
{
public:
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        int n = matrix.size();
        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        while (left < right && top < bottom)
        {
            for (int i = 0; i < (right - left); i++)
            {
                //Rotate clockwise from top left
                int temp = matrix[top + i][right];
                matrix[top + i][right] = matrix[top][left + i];

                int temp2 = matrix[bottom][right - i];
                matrix[bottom][right - i] = temp;

                int temp3 = matrix[bottom - i][left];
                matrix[bottom - i][left] = temp2;

                matrix[top][left + i] = temp3;
            }

            left++;
            right--;
            top++;
            bottom--;
        }
    }
};

