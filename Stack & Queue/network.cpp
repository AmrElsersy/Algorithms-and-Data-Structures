#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, n; cin >> s >> n;
    deque<int> finish_times;
    vector<int> output;
    vector<int> input;

    int currentTime = 0;

    for (int i =0 ; i < n; ++i)
    {
        int a,p; cin >> a >> p;
        input.push_back(p);
        // first time
        if (!finish_times.size() && s)
        {
            finish_times.push_back(a+p);
            currentTime = a+p;
            output.push_back(a);
            continue;
        }

        // remove all finish times till the arrival time
        while (a >= currentTime && finish_times.size())
        {
            currentTime = finish_times.front();
            finish_times.pop_front();
        }

        if (finish_times.size() == s)
        {
            output.push_back(-1);
            continue;
        }

        if (currentTime < a)
            currentTime = a;

        finish_times.push_back(currentTime + p);
        output.push_back(currentTime);
    }

    for (int i = 0; i < n; ++i)
    {
        cout << output[i] << endl;
    }
    return 0;
}
