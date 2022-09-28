#include <unordered_map>
#include <unordered_set>
using namespace std;

//https://www.youtube.com/watch?v=UwpvInpgFmo
class Solution
{
public:
    double calculateDivision(unordered_map<string, unordered_map<string, double>>& g, const string& a, const string& b, unordered_set<string>& visited)
    {
        if (a == b) return 1;
        visited.insert(a);
        for (const auto& edge : g[a])
        {
            //a/b = a/c * c/b
            const string& c = edge.first;
            if (visited.count(c)) continue;

            // a/c
            double curVal = edge.second;
            // c/b
            double nextVal = calculateDivision(g, c, b, visited);

            if (nextVal > 0) return curVal * nextVal;
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries)
    {
        //graph [A][B] -> value
        unordered_map<string, unordered_map<string, double>> g;
        //add edges to the graph
        for (int i = 0; i < equations.size(); i++)
        {
            const string& a = equations[i][0];
            const string& b = equations[i][1];

            g[a][b] = values[i];
            g[b][a] = 1 / values[i];
        }

        vector<double> res;
        for (const auto& query : queries)
        {
            const string& A = query[0];
            const string& B = query[1];
            //didn't find all values return -1
            if (!g.count(A) || !g.count(B))
            {
                res.push_back(-1);
            }
            else
            {
                unordered_set<string> visited;
                res.push_back(calculateDivision(g, A, B, visited));
            }
        }
        return res;
    }
};