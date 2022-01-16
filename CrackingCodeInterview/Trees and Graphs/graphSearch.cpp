#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    int BFS(int start, int dest)
    {
        queue<int> q;
        q.push(start);

        while(!q.empty())
        {
            auto node = q.front();
            q.pop();
            this->visited[node] = true;

            if (node == dest)
                return dest;

            for (auto n : this->adj[node])
            {
                if (!this->visited[n])
                {
                    q.push(n);
                }
            }
        }
        return -1;
    }

    int DFS(int start, int dest)
    {
        for (auto node : this->adj[start])
        {
            if (dest == node)
            {
                return dest;
            }
            if (!this->visited[node])
            {
                int n = DFS(node, dest);
                if (n == dest)
                    return dest;
            }
        }
        return -1;
    }

    Graph()
    {
        adj.resize(7, vector<int>());
        adj[0].push_back(6);
        adj[1].push_back(0);
        adj[1].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(3);
        adj[3].push_back(4);
        adj[4].push_back(5);
        adj[5].push_back(3);
        adj[5].push_back(4);
        adj[6].push_back(5);

        visited.resize(7, false);
    }

};



