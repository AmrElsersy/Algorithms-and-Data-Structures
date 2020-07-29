#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    Graph()
    {
        int V, E; cin >> V >> E;

        this->graph_adjest_list.resize(V+1);
        this->visited.resize(V+1,false);
        this->loop.resize(V+1,false);
        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            graph_adjest_list[v1].push_back(v2);
        }

        CheckCycle();
    }

    bool Explore(int v)
    {
        this->visited[v] = true;
        this->loop[v] = true;
        for (int i = 0; i < this->graph_adjest_list[v].size(); i++)
        {
            int node_graph = this->graph_adjest_list[v][i];
            if (!this->visited[node_graph] && Explore(node_graph))
            {
                    return true;
            }
            else if (this->loop[node_graph])
                return true;
        }
        this->loop[v] = false;
        return false;
    }

    void CheckCycle()
    {
        for (int i = 1; i < this->graph_adjest_list.size(); i++)
        {
            if (Explore(i))
            {
                cout << 1 << endl;
                return;
            }
        }
        cout << 0 << endl;
    }

private:
    vector< vector<int> > graph_adjest_list;
    vector<bool> visited;
    vector<bool> loop;
};

int main()
{
    Graph graph;

    return 0;
}
