#include <bits/stdc++.h>
using namespace std;
#include <limits>

class edge {
public:
    int from;
    int to;
    int cost;

    edge(int f, int t, int c)
    {
        from = f;
        to = t;
        cost = c;
    }

};

class Graph
{
public:
    Graph()
    {
        cin >> V >> E;

        costs.resize(V, INT_MAX);
        parents.resize(V);

        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2, cost;
            cin >> v1 >> v2 >> cost;
            // edges representation
            edges.push_back( edge(v1-1, v2-1, cost) );
        }

//        int u,v ; cin >> u >> v;
//        u--; v--;


        int contain_neg_cycle = this->Bellman_Ford(0) ;
        cout << contain_neg_cycle << endl;
//        auto path = Path(u, v);
//        for (int i =0 ; i < path.size(); i++)
//                cout << path[i] + 1<< " ";
//                cout << endl;

    }

    int Bellman_Ford(int start)
    {
        costs[start] = 0;

        for (int i =0 ; i < V - 1; i++)
            for (int j = 0 ; j < E; j++)
            {
                int u = edges[j].from;
                int v = edges[j].to;
                int edge_cost = edges[j].cost;

                if (costs[u] + edge_cost< costs[v] && costs[u] != INT_MAX)
                {
                    costs[v] = costs[u] + edge_cost;
                    parents[v] = u;
                }
            }

        for (int j = 0 ; j < E ;  j++)
        {
                int u = edges[j].from;
                int v = edges[j].to;
                int edge_cost = edges[j].cost;

                if (costs[u] + edge_cost< costs[v] && costs[u] != INT_MAX)
                    return 1;
        }


        return 0;
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
    // vector< vector<pair<int,int> > > adj;
    vector< edge > edges;
    vector<int> costs;
    vector<int> parents;
    int V, E;
};

int main()
{
    Graph graph;

    return 0;
}
