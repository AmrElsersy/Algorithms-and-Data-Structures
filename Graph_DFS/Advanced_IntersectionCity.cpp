#include <bits/stdc++.h>
using namespace std;

bool sortByTimerPost(pair<int,int> a, pair<int,int> b)
{
    return a.second > b.second;
}


class Graph
{
public:
    Graph()
    {
        timer = 0;
        int V, E; cin >> V >> E;

        // will be Reversted
        this->adj.resize(V);
        // not reversted
        this->adjMain.resize(V);
        this->visited.resize(V,false);

        // read the graph
        for (int i =0 ; i < E; i++)
        {
            int v1, v2;
            cin >> v1 >> v2;
            // do both
            adj[v2-1].push_back(v1-1);
            adjMain[v1-1].push_back(v2-1);
        }

        // explore the
        for (int i = 0 ; i < this->adj.size(); i++)
        {
            if (!visited[i])
                ExploreReverse(i);
        }
        sort(this->post.begin(), this->post.end(), sortByTimerPost);

        this->visited.clear();
        this->visited.resize(V, false);

        int strongly_connected_components = 0;
        for (int i =0; i < post.size(); i++)
        {
            if (!visited[ post[i].first ])
            {
                Explore(post[i].first);
                strongly_connected_components++;
            }
        }

        cout << strongly_connected_components << endl;

    }

    void ExploreReverse(int v)
    {
        timer++;

        this->visited[v] = true;
        for (int i = 0; i < this->adj[v].size(); i++)
        {
            int node_graph = this->adj[v][i];
            if (!this->visited[node_graph])
                ExploreReverse(node_graph);
        }

        timer++;
        this->post.push_back(pair<int,int>(v,timer) );
    }
    void Explore(int v)
    {
        this->visited[v] = true;
        for (int i = 0; i < this->adjMain[v].size(); i++)
        {
            int node_graph = this->adjMain[v][i];
            if (!this->visited[node_graph])
                Explore(node_graph);
        }
    }


private:
    vector< vector<int> > adj;
    vector< vector<int> > adjMain;

    vector<bool> visited;
    vector< pair<int,int> > post;
    int timer;
};


int main()
{
    Graph graph;

    return 0;
}
