#include <bits/stdc++.h>
using namespace std;
#include <limits>

#define WHITE 1
#define BLACK 0
#define UNCOLORED -1

class Graph
{
public:
    Graph()
    {
        int V, E; cin >> V >> E;

        this->adj.resize(V);
        this->colors.resize(V, UNCOLORED);

        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            // bidirectional
            adj[v1-1].push_back(v2-1);
            adj[v2-1].push_back(v1-1);
        }
        cout << bipartite() << endl;
    }

    int bipartite()
    {
        queue<int> level;
        level.push(0);
        colors[0] = WHITE;

        while (!level.empty())
        {
            int u = level.front();
            level.pop();

            for (int i =0 ; i < this->adj[u].size() ;i ++)
            {
                int v = adj[u][i];


                if (colors[v] == UNCOLORED)
                {
                    colors[v] = 1 - colors[u];
                    level.push(v);
                }
                else if (colors[v] == colors[u])
                    return 0;
            }
        }
        return 1;
    }


private:
    vector< vector<int> > adj;
    vector<int> colors;
};

int main()
{
    Graph graph;

    return 0;
}
