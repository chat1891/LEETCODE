#include<vector>
#include<queue>
/*
Logic: Kahn's Algorithm
-create graph of prerequisites:
prerequisite -> [list of courses need that prerequisite]
-create indegree list, prereq->course
-start queue with indegree is 0
-decrease indegree of the course every time finish one prereq

We will take a count variable to check if there is a deadlock(cycle) in the graph. Because if there is a cycle in the graph then it means we cant apply
topological sort in it and there will be no way to complete all the courses.

So, for DAG(Directed acyclic graph) our count variable should be equal to the total no of nodes in the graph.


Time: 
O(V+E)
We pop each node exactly once from the zero in-degree queue and that gives us V. 
Also, for each vertex, we iterate over its adjacency list and in totality, 
we iterate over all the edges in the graph which gives us E. Hence, O(V + E)


Space: 
O(V+E)
*/

class Solution
{
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites)
    {
        std::vector<std::vector<int>> graph(numCourses);//prerequisite -> courses need that prereq
        std::vector<int> indegree(numCourses);
        std::queue<int> que;
        std::vector<int> res;

        //create the graph
        for (int i = 0; i < prerequisites.size(); i++)
        {
            int& prereq = prerequisites[i][1];
            int& cour = prerequisites[i][0];
            graph[prereq].push_back(cour);
            indegree[cour]++; //b->a
        }

        //put all the course without prereq to the queue, indegree=0
        for (int i = 0; i < indegree.size(); i++)
        {
            if (indegree[i] == 0)
            {
                que.push(i);
            }
        }

        while (!que.empty())
        {
            int prereq = que.front();
            que.pop();
            res.push_back(prereq);

            for (auto& nextCourse : graph[prereq])
            {
                indegree[nextCourse]--;
                if (indegree[nextCourse] == 0)
                {
                    //finished all the prerequisites
                    que.push(nextCourse);
                }
            }
        }

        if (numCourses == res.size()) return res;
        return {};

    }
};