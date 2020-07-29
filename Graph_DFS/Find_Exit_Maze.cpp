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

        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            // bidirectional
            graph_adjest_list[v1].push_back(v2);
            graph_adjest_list[v2].push_back(v1);
        }

/*        int u, v; cin >> u >> v;
        this->Explore(u);
        if (this->visited[v])
            cout << 1 << endl;
        else
            cout << 0 << endl;
*/

        cout << CountComponent() << endl;
    }

    void Explore(int v)
    {
        this->visited[v] = true;
        for (int i = 0; i < this->graph_adjest_list[v].size(); i++)
        {
            int node_graph = this->graph_adjest_list[v][i];
            if (!this->visited[node_graph])
                Explore(node_graph);
        }
    }

    int CountComponent()
    {
        int component = 0;
        for (int i =1 ; i < this->graph_adjest_list.size(); i++)
        {
            if ( ! this->visited[i] )
            {
                Explore(i);
                component ++;
            }
        }
        return component;
    }

private:
    vector< vector<int> > graph_adjest_list;
    vector<bool> visited;
};

int main()
{
    Graph graph;

    return 0;
}
