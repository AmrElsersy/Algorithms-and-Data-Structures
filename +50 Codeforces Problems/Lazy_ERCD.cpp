#include <iostream>
using namespace std;

int main()
{
    freopen("lazy.in","r",stdin);

    int T ; cin >> T;
    for (int t =0 ; t < T ; t++)
    {
        int N ; cin >> N;
        cout << "Case " << t+1 << ": " << N-1 << endl;
    }

    return 0;
}
