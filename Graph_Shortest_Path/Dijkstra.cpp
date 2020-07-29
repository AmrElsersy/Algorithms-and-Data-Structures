#include <bits/stdc++.h>
using namespace std;
#include <limits>

class Graph
{
public:
    Graph()
    {
        int V, E; cin >> V >> E;

        adj.resize(V);
        costs.resize(V, INT_MAX);
        parents.resize(V);
        processed.resize(V, false);

        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2, cost;
            cin >> v1 >> v2 >> cost;
            // bidirectional
            adj[v1-1].push_back( pair<int, int> (v2-1, cost) );
        }

        int u,v ; cin >> u >> v;
        u--; v--;


        int cost = this->Dijkstra(u, v) ;
        if (cost == INT_MAX)
            cout << -1 << endl;
        else
            cout << cost << endl;
/*
        auto path = Path(u, v);
        for (int i =0 ; i < path.size(); i++)
                cout << path[i] + 1<< " ";
                cout << endl;
*/
    }

    int Dijkstra(int start, int finish)
    {
        int u = start;
        costs[u] = 0;

        while (u != -1)
        {
            for (int i =0 ; i < adj[u].size(); i++)
            {
                int v = adj[u][i].first;

                if (processed[v])
                    continue;

                if (costs[u] + adj[u][i].second < costs[v])
                {
                    costs[v] = costs[u] + adj[u][i].second;
                    parents[v] = u;
                }
            }
            processed[u] = true;
            u = get_cheapest_node(start);
        }

/*
        for (int i = 0 ; i < costs.size(); i ++)
            cout << costs[i] << " ";
            cout << endl;
*/
        return costs[finish];
    }

    int get_cheapest_node(int start)
    {
        int smallest = INT_MAX;
        int node = -1;

        for (int i = 0 ; i < costs.size(); i ++)
        {
            if (processed[i] || i == start)
                continue;

            if (costs[i] < smallest)
            {
                node = i;
                smallest = costs[i];
            }
        }

        return node;
    }

    deque<int> Path(int u, int v)
    {
        deque<int> path;
        int i = v;
        // push the start
        path.push_front(v);

        // recursivly add the prev node to the path
        while (parents[i] != u)
        {
            path.push_front(parents[i]);
            i = parents[i];
        }

        // push the end
        path.push_front(u);
        return path;
    }


private:
    // node - edge cost
    vector< vector<pair<int,int> > > adj;
    vector<int> costs;
    vector<int> parents;
    vector<int> processed;
};

int main()
{
    Graph graph;

    return 0;
}
