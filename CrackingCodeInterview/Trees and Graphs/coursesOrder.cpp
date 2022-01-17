
#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // store the reverse of the adj (reverse edges)
    vector<vector<int>> adj;
    // number of nodes that depends on each node
    vector<int> n_edges;
    vector<bool> built;
    int n_builtNodes = 0;
    int n_courses;

    Graph(int numCourses, vector<vector<int>>& prerequisites)
    {
        this->n_edges.resize(numCourses, 0);
        this->adj.resize(numCourses, vector<int>());
        this->built.resize(numCourses, false);
        this->n_courses = numCourses;

        // arrow from node "a" to node "b" mean that a depends on b (b first then a)
        for (auto preq : prerequisites)
        {
            int course = preq[0];
            int depends_on = preq[1];

            this->adj[depends_on].push_back(course);
            this->n_edges[course]++;
        }
    }

    vector<int> findNoDependNodes()
    {
        vector<int> nodes;

        // find nodes with no dependencies (no edges outside it)
        for (int i = 0; i < n_courses; i++)
        {
            if (this->n_edges[i] == 0 && !this->built[i])
            {
                nodes.push_back(i);
                this->built[i] = true;
                this->n_builtNodes++;
            }
        }

        return nodes;
    }

    void removeNode(int node)
    {
        // for every node that depends on removed "node"
        for (auto n : this->adj[node])
        {
            this->n_edges[n]--;
        }
    }

    vector<int> buildOrder()
    {
        vector<int> order;
        while (this->n_builtNodes < this->n_courses)
        {
            vector<int> independentNodes = this->findNoDependNodes();
            for (auto node : independentNodes)
            {
                this->removeNode(node);
                order.push_back(node);
            }
        }
        return order;
    }

};

vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    Graph graph(numCourses, prerequisites);
    return graph.buildOrder();
}

int main()
{
    vector<vector<int>> preq(4);
    preq[0] = vector<int>(2);
    preq[1] = vector<int>(2);
    preq[2] = vector<int>(2);
    preq[3] = vector<int>(2);
    preq[0][0] = 1;
    preq[0][1] = 0;
    preq[1][0] = 2;
    preq[1][1] = 0;
    preq[2][0] = 3;
    preq[2][1] = 1;
    preq[3][0] = 3;
    preq[3][1] = 2;

    auto order = findOrder(4, preq);
    for (auto c : order)
        cout << c << " ";
    cout << endl;

    return 0;
}

