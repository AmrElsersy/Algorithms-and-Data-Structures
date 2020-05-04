#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void coins();
void knapsack();
void carFuel();
void ads();
void Signatures();
void Salary();
void setCovery();
int main()
{
//    while (true)
    setCovery();
    return 0;
}

void setCovery()
{

}


void Salary()
{
    int n ; cin >> n ;
    vector<string> salaries(n);
    vector<char> all_chars;
    for(int i =0 ; i < n ;i ++)
    {
        string x ; cin >> x;
        salaries[i] = x;
        for(int i=0; i < x.size(); i++)
            all_chars.push_back(x[i]);
    }

    sort(all_chars.begin(),all_chars.end());
    string x;
    for(int i = all_chars.size()-1 ; i >= 0; i--)
    {
        x += all_chars[i];
    }

    cout << x << endl;

}

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

void ads()
{
    int n ; cin >> n ;
    vector<long long> a(n); vector<long long> b(n) ;
    for (int i =0 ; i <n ; i ++)
        cin >> a[i];
    for (int i =0 ; i <n ; i ++)
        cin >> b[i];

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    long long profit= 0.0;
    for(int i =0 ; i<n ;i++)
    {
        profit += (long long)a[i] * (long long)b[i];
    }

    cout << profit << endl;
}



void carFuel()
{
    int total_distance , car_distance , n; cin >> total_distance >> car_distance >> n;
    vector<int> stations(n);
    for (int i =0 ; i < n ; i++)
    {
        cin >> stations[i] ;
    }
    stations.push_back(total_distance);
    n++;

    int num = 0;
    int pos_car = 0;
    int i =0 ;
    while(pos_car < total_distance)
    {
        while( stations[i+1] - pos_car <= car_distance  && i+1 < n )
        {
            i++;
        }



        // if the position dosn't change
        if(pos_car == stations[i])
        {
            cout << -1 << endl;
            return;
        }
        if( i < n-1 )
            num++;
        pos_car = stations[i];
    }

    cout << num << endl;
}

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

void coins()
{
    int n ; cin >> n;
    int coin = 0;
    while  (n >= 10)
    {
        coin ++ ;
        n -= 10;
    }
    while  (n >= 5)
    {
        coin ++ ;
        n -= 5;
    }
    while  (n >= 1)
    {
        coin ++ ;
        n -= 1;
    }
    cout << coin << endl;


}
