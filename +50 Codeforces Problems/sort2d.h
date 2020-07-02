#include "my_stl.h"

bool comparsion(pair<int,int> point1 , pair<int,int> point2)
{
    int x1 = point1.first, y1 = point1.second;
    int x2 = point2.first, y2 = point2.second;
    if ((x1>x2) || (x1==x2 && y1<y2))
        return false;
    return true;
}

int ray2()
{
    int t ; cin >> t;
    int n ; cin >> n;

    // read points
    vector< pair<int,int> > points(n);
    for (int i =0 ; i < n; i++)
    {
        int x ; cin >> x ;
        int y ; cin >> y ;
        points[i].first = x;
        points[i].second= y;
    }// ===========================

    sort(points.begin(), points.end(), comparsion);

    // print points
    for (int i =0 ; i<points.size(); i++)
        cout << "(" << points[i].first << "," << points[i].second << ") ";
    cout << endl;
}

