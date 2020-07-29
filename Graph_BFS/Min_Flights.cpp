#include <bits/stdc++.h>
using namespace std;
#include <limits>

class Graph
{
public:
    Graph()
    {
        int V, E; cin >> V >> E;

        this->adj.resize(V);
        this->dist.resize(V,-1);
        this->prevPathTree.resize(V);

        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            // bidirectional
            adj[v1-1].push_back(v2-1);
            adj[v2-1].push_back(v1-1);
        }
        int u,v ; cin >> u >> v;
        u--; v--;

        if (this->ShortestPath(u, v) != -1 )
        {
            auto path = Path(u, v);
            for (int i =0 ; i < path.size(); i++)
                cout << path[i] + 1<< " ";
                cout << endl;
        }
    }

    int ShortestPath(int u, int v)
    {
        int pathCount = 0;
        queue<int> level;

        level.push(u);
        dist[u] = 0;
        prevPathTree[u] = -1;
        while (!level.empty())
        {
            int node = level.front();
            level.pop();

            for (int i =0 ; i < this->adj[node].size() ;i ++)
            {
                // if not visited (not reached)
                if (dist[adj[node][i]] == -1)
                {
                    // keep track of the distance between the start node and any node
                    dist[ adj[node][i] ] = dist[node] + 1 ;
                    // push it to thee queue so next iteration will load its childs
                    level.push(adj[node][i]);
                    // keep track of what is the prev node that calls that node to keep track of the path itself
                    prevPathTree[ adj[node][i] ] = node;
                }
            }
        }
        for (int i =0 ; i < prevPathTree.size(); i++)
            cout << prevPathTree[i] + 1 << " ";
            cout << endl;
        return dist[v];
    }

    deque<int> Path(int u, int v)
    {
        deque<int> path;
        int i = v;
        // push the start
        path.push_front(v);

        // recursivly add the prev node to the path
        while (prevPathTree[i] != u)
        {
            path.push_front(prevPathTree[i]);
            i = prevPathTree[i];
        }

        // push the end
        path.push_front(u);
        return path;
    }


private:
    vector< vector<int> > adj;
    vector<int> dist;
    vector<int> prevPathTree;
};

int main()
{
    Graph graph;

    return 0;
}
