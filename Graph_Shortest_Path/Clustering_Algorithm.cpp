#include <bits/stdc++.h>
using namespace std;

struct DisjointSetsElement {
	int size, parent, rank;

	DisjointSetsElement(int size = 0, int parent = -1, int rank = 0):
	    size(size), parent(parent), rank(rank) {}
};

class DisjointSets {
public:
	int size;
	int max_table_size;
	vector <DisjointSetsElement> sets;

	DisjointSets(int Size) {
        this->size = Size;
        max_table_size = 0;
        sets.resize(size);

		for (int i = 0; i < size; i++)
			sets[i].parent = i;
	}

	int getParent(int table) {
        if (sets[table].parent != table)
            sets[table].parent = getParent(sets[table].parent);

        return sets[table].parent ;
	}

	void merge(int destination, int source) {
		int realDestination = getParent(destination);
		int realSource = getParent(source);
		if (realDestination != realSource) {
            if (sets[realDestination].rank > sets[realSource].rank)
            {
            sets[realDestination].size += sets[realSource].size;
            sets[realSource].size = 0;
            sets[realSource].parent = realDestination;

            if (sets[realDestination].size > max_table_size)
                max_table_size = sets[realDestination].size;

            if (sets[realDestination].rank == sets[realSource].rank)
                sets[realDestination].rank ++;
            }
            else
            {
            sets[realSource].size += sets[realDestination].size;
            sets[realDestination].size = 0;
            sets[realDestination].parent = realSource;

            if (sets[realSource].size > max_table_size)
                max_table_size = sets[realSource].size;

            if (sets[realDestination].rank == sets[realSource].rank)
                sets[realSource].rank ++;
            }
		}
	}
};

class edge {
public:
    int from;
    int to;
    float cost;
    edge(int f,int t, float c)
    {
        from = f;
        to = t;
        cost = c;
    }
};

vector<edge> make_edges(vector<pair<int,int> > points)
{
    vector<edge> edges;

    int n = points.size();

    for (int i = 0; i < n ; i++)
    {
        pair<int,int> p1 = points[i];
        for (int j = i+1 ; j < n ; j++)
        {
            pair<int,int> p2 = points[j];
            float dist =  sqrt(pow(p2.first - p1.first, 2) +  pow(p2.second - p1.second, 2));
            edges.push_back( edge(i, j, dist));
        }
    }

    return edges;
}

int main() {
	int n;  cin >> n;
	vector<pair<int,int>> points(n);
	for (int i =0 ; i < n ; i++)
        cin >> points[i].first >> points[i].second;
    int k ; cin >> k;

    vector<edge> min_edges = make_edges(points);
    sort(min_edges.begin(), min_edges.end(), [&] (edge e1, edge e2) -> bool {return e1.cost < e2.cost;}  );

    vector<edge> edges;
    double total_cost = 0.0;
	DisjointSets disjoint(n);
	int unions = 0;
    for (int i =0 ; i < min_edges.size(); i++)
    {
        edge e = min_edges[i];
        if ( disjoint.getParent(e.from) != disjoint.getParent(e.to) )
        {
            unions++;
            disjoint.merge(e.from, e.to);
        }
            // if we have 10 poins and k = 3, so we need to do union at most 7 times to make them 3 clusters
        if (unions > n - k )
        {
                cout.precision(10);
                cout << fixed <<  e.cost << endl;
                return 0;
        }
    }




	return 0;
}
