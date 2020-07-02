#include <iostream>
#include <bits/stdc++.h>
using namespace std;


bool sortByBegining(pair<int,int> x , pair<int,int>  y)
{
    return x.first < y.first ;
}

void Signatures()
{
    int n ; cin >> n ;
    vector<pair<int,int> > segments(n) ;
    for (int i = 0 ; i < n; i++)
            cin >> segments[i].first >> segments[i].second;

    sort(segments.begin(),segments.end() ,sortByBegining);

//    for(int i =0 ; i < n ; i++)
 //       cout << "(" << segments[i].first <<"," << segments[i].second << ") " << endl;

    vector< int > points ;

    int m = n ; // max value , wors case senario
    for(int i =0 ; i < n ; i++)
    {
        int last_point = -1;
        for(int j = i+1 ; j < n; j++)
        {
            // if the next segment in the range of the current segment, SO , they have  a common point
            if (segments[i].second >= segments[j].first)
            {
                if(last_point == -1)
                    last_point = min(segments[i].second ,  segments[j].second);
                else
                    last_point = max(last_point,segments[j].first);

                m --;

                if( j == n-1)
                {
                    i = j -1;
                    break;
                }
            }
            // if the next one is not in the range so all the next is not in the range as they are sorted
            else
            {
                i = j -1 ;
                break;
            }

        }
        if (last_point != -1)
            points.push_back(last_point);

    }
    cout << m << endl;
    for(int i =0; i < points.size();i++)
        cout << points[i] << " ";
    cout << endl;

}

