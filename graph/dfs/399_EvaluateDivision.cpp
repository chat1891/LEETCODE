#include <unordered_map>
#include <unordered_set>

//https://www.youtube.com/watch?v=UwpvInpgFmo
class Solution
{
public:
    double calculateDivision(std::unordered_map<std::string, std::unordered_map<std::string, double>>& g, const std::string& a, const std::string& b, std::unordered_set<std::string>& visited)
    {
        if (a == b) return 1;
        visited.insert(a);
        for (const auto& edge : g[a])
        {
            //a/b = a/c * c/b
            const std::string& c = edge.first;
            if (visited.count(c)) continue;

            // a/c
            double curVal = edge.second;
            // c/b
            double nextVal = calculateDivision(g, c, b, visited);

            if (nextVal > 0) return curVal * nextVal;
        }
        return -1;
    }

    std::vector<double> calcEquation(std::vector<std::vector<std::string>>& equations, std::vector<double>& values, std::vector<std::vector<std::string>>& queries)
    {
        //graph [A][B] -> value
        std::unordered_map<std::string, std::unordered_map<std::string, double>> g;
        //add edges to the graph
        for (int i = 0; i < equations.size(); i++)
        {
            const std::string& a = equations[i][0];
            const std::string& b = equations[i][1];

            g[a][b] = values[i];
            g[b][a] = 1 / values[i];
        }

        std::vector<double> res;
        for (const auto& query : queries)
        {
            const std::string& A = query[0];
            const std::string& B = query[1];
            //didn't find all values return -1
            if (!g.count(A) || !g.count(B))
            {
                res.push_back(-1);
            }
            else
            {
                std::unordered_set<std::string> visited;
                res.push_back(calculateDivision(g, A, B, visited));
            }
        }
        return res;
    }
};