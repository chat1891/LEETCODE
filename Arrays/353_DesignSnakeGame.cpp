#include<deque>
#include<vector>
#include <set>
#include <string>

//use deque and hashset
class SnakeGame
{
public:
    struct Position
    {
        int x;
        int y;
        Position(int x, int y)
        {
            this->x = x;
            this->y = y;
        }
        bool operator=(const Position& other)
        {
            return x == other.x && y == other.y;
        }
    };

    struct PositionCompare
    {
        //**need to define the comparator for hash set
        bool operator() (const Position& a, const Position& b) const
        {
            return a.x == b.x ? a.y > b.y : a.x > b.x;
        }
    };

    std::deque<Position> snake;
    int width;
    int height;
    std::vector<std::vector<int>> food;
    int foodCount = 0;
    std::set<Position, PositionCompare> snakeSet;
    //copy of snake body for faster checking if snake bites itself

    SnakeGame(int width, int height, std::vector<std::vector<int>>& food)
    {
        Position head = Position(0, 0);
        snake.push_back(head);
        this->width = width;
        this->height = height;
        this->food = food;
        snakeSet.insert(head);
    }

    bool hitWall(const Position& head)
    {
        return head.x < 0 || head.y < 0 || head.y >= width || head.x >= height;
    }

    bool biteSelf(const Position headHash)
    {
        //snake's tail is removed
        if (snakeSet.find(headHash) != snakeSet.end())
        {
            return true;
        }
        return false;
    }
    int oneDimentionalIdx(const Position& p)
    {
        //put 2D as as 1-D array
        return p.x * width + p.y;
    }
    int move(std::string direction)
    {
        Position newHead = snake.front();
        Position tail = snake.back();

        snake.pop_back(); //remove tail
        snakeSet.erase(tail);

        if (direction == "U")
            newHead.x--;
        else if (direction == "D")
            newHead.x++;
        else if (direction == "L")
            newHead.y--;
        else if (direction == "R")
            newHead.y++;

        if (hitWall(newHead) || biteSelf(newHead))
        {
            return -1;
        }

        snakeSet.insert(newHead);
        snake.push_front(newHead);
        //check still have food and if eats food
        if (foodCount < food.size() && newHead.x == food[foodCount][0] && newHead.y == food[foodCount][1])
        {
            //eats food, add tail
            snake.push_back(tail);
            snakeSet.insert(tail);
            foodCount++;
        }

        return foodCount;
    }
};

//Use deque and serialize x, y coordinates :
class SnakeGame
{
public:
    std::deque<int> snake; //save index of one dimensional array
    int width;
    int height;
    std::vector<std::vector<int>> food;
    int foodCount = 0;
    std::vector<int> head; //head position
    //copy of snake body for faster checking if snake bites itself

    SnakeGame(int width, int height, std::vector<std::vector<int>>& food)
    {
        head = { 0,0 };
        snake.push_back(oneDimentionalIdx(head));

        this->width = width;
        this->height = height;
        this->food = food;
    }

    bool hitWall(const std::vector<int>& head)
    {
        return head[0] < 0 || head[1] < 0 || head[1] >= width || head[0] >= height;
    }

    bool biteSelf(const int headHash)
    {
        //tail is removed
        if (find(snake.begin(), snake.end(), headHash) != snake.end())
        {
            return true;
        }
        return false;
    }

    int oneDimentionalIdx(const std::vector<int>& p)
    {
        //calculate 2D array as as 1-D array
        return p[0] * width + p[1];
    }

    int move(std::string direction)
    {
        //vector<int> newHead = head;
        int tail = snake.back();
        snake.pop_back(); //remove tail

        if (direction == "U")
            head[0]--;
        else if (direction == "D")
            head[0]++;
        else if (direction == "L")
            head[1]--;
        else if (direction == "R")
            head[1]++;

        int newHash = oneDimentionalIdx(head);
        if (hitWall(head) || biteSelf(newHash))
        {
            return -1;
        }
        snake.push_front(newHash);
        //check still have food and if eats food
        if (foodCount < food.size() && head[0] == food[foodCount][0] && head[1] == food[foodCount][1])
        {
            //eats food, add tail
            snake.push_back(tail);
            foodCount++;
        }

        return foodCount;
    }
};

int main_testSnake()
{
    std::vector<std::vector<int>> food{ {1, 2}, {0, 1} };
    SnakeGame* snakeGame = new SnakeGame(3, 2, food);
    snakeGame->move("R"); // return 0
    snakeGame->move("D"); // return 0
    snakeGame->move("R"); // return 1, snake eats the first piece of food. The second piece of food appears at (0, 1).
    snakeGame->move("U"); // return 1
    snakeGame->move("L"); // return 2, snake eats the second food. No more food appears.
    snakeGame->move("U"); // return -1, game over because snake collides with border


    delete(snakeGame);
    return 0;
}

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */