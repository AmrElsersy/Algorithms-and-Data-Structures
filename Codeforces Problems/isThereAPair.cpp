#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n , sum ; cin >> n >> sum;

    vector<int> arr(n);
    map<int,int> pairs ;

    for (int i =0 ; i < n ; i++) {
        cin >> arr[i];
        pairs[arr[i]] ++;
    }

    int count = 0;
    for (int i =0 ; i < n ; i++) {
        count += pairs[sum-arr[i]] ; // increment with the number of apperance of that ray2
        if ( sum == arr[i] * 2 && pairs[arr[i]] == 1)
            count --;
    }
    cout << count/2 << endl;

    return 0;
}
