#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#include <math.h>

bool sortByX(Point a , Point b)
{
    return a.x < b.x;
}
bool sortByY(Point a , Point b)
{
    return a.y < b.y;
}

class Point
{
    public : int x, y;
};

float calculateDistance(Point a,Point b)
{
    return
}

int findMinDistance(vector<Point> arr, int l , int r )
{

}

int main()
{
    int n ; cin >> n ;
    vector<Point> arr(n);
    for ( int i =0 ; i < n ; i++ )
    {
        Point point ;
        cin >> point.x >> point.y;
        arr[i] = point;
    }

    sort(arr.begin(),arr.end(),sortByX);


    return 0;
}
