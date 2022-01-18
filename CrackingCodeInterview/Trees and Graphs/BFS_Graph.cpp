#include <bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    // =============================================
    // stores the parent which calls the node for each node
    // used to track the path by starting from the target node and getting its calling parent then the parent of calling parent .. etc till the start node
    vector<int> parentPath;

    Graph()
    {
        adj.resize(7, vector<int>());
        adj[0].push_back(6);
        adj[1].push_back(0);
        adj[1].push_back(2);
        adj[1].push_back(3);
        adj[2].push_back(3);
        adj[3].push_back(4);
//        adj[4].push_back(5);
        adj[5].push_back(3);
        adj[5].push_back(4);
        adj[6].push_back(5);

        visited.resize(7, false);
        parentPath.resize(7, -1);

        auto path = Search(1, 5);
        for (auto p : path)
            cout << p << " ";
            cout << endl;
    }

    vector<int> Search(int u, int v)
    {
        queue<int> q;
        q.push(u);
        visited[u] = true;

        while (!q.empty())
        {
            // pop
            int node = q.front();
            q.pop();

            this->visited[node] = true;

            if (node == v)
                break;

            auto childs = this->adj[node];
            for (auto child : childs)
            {
                if (!this->visited[child])
                {
                    q.push(child);
                    this->parentPath[child] = node;
                }
            }

        }
        return this->constructPath(u, v);
    }

    vector<int> constructPath(int u, int v)
    {
        // construct the path from the parent paths by traversing through the calling parents
        int node = v;
        vector<int> path;
        path.push_back(node);

        while (node != u)
        {
            node = this->parentPath[node];
            path.push_back(node);
        }
        reverse(path.begin(), path.end());
        return path;
    }
};



int main()
{
    Graph graph;
    return 0;
}

