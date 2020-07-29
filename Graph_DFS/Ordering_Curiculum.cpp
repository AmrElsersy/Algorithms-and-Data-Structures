#include <bits/stdc++.h>
using namespace std;

bool sortBySource(vector<int> a, vector<int> b)
{
    return a.size() > b.size();
}


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
            graph_adjest_list[v1].push_back(v2);
        }

//        sort(this->graph_adjest_list.begin(), this->graph_adjest_list.end(), sortBySource);

        for (int i =1 ; i < this->graph_adjest_list.size(); i++)
        {
            if (!this->visited[i])
            {
                Explore(i);
//                this->ordering.clear();
            }

        }

                        for (int j = 0; j < this->ordering.size(); j++)
                    cout << this->ordering[j] << " " ;


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
        this->ordering.push_front(v);
    }


private:
    vector< vector<int> > graph_adjest_list;
    vector<bool> visited;
    deque<int> ordering;
};


int main()
{
    Graph graph;

    return 0;
}
