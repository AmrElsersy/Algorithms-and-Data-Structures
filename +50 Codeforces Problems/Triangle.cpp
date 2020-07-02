#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1,y1  ,x2,y2  ,x3,y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    int ux,uy   ,vx,vy;
    ux = x2 - x1  ;  uy = y2 - y1;   // u = (ux,uy) = vector from p1 to p2
    vx = x3 - x1  ;  vy = y3 - y1;   // v = (vx,vy) = vector from p1 to p3
    int d = ux*vx + uy*vy;               // Dot product of u and v

    if(d == 0)

    return 0;
}
