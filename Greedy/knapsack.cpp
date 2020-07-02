#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// functor to compare the heap to make it insert by the max of "Value" attribute
class sortByValue
{
public:
    int operator() (pair<double,double> a, pair<double,double> b)
    {
        return a.first/a.second < b.first/b.second;
    }
};

void knapsack()
{
    int n ; double w ; cin >> n >> w;
    priority_queue< pair<double,double> , vector< pair<double,double>  > , sortByValue > values_weights;
    for(int i =0 ; i < n ; i ++)
    {
        pair<double,double> x ;  cin >> x.first >> x.second;
        values_weights.push(x);
    }
    /*
    while (!values_weights.empty())
    {
        cout<< values_weights.top().first << values_weights.top().second << endl;
        values_weights.pop();
    }
    */
    double knsack= 0.000000;
    while( ! values_weights.empty() && w > 0)
    {
        pair<double,double> largest = values_weights.top();
        float value_per_weight = largest.first/largest.second;

        if( w >= largest.second )
        {
            knsack += largest.first;
            w -= largest.second;
        }
        else
        {
            knsack += w * value_per_weight;
            w = 0;
        }

        values_weights.pop();
    }
    cout << fixed<<setprecision(4) << knsack << endl;


}
