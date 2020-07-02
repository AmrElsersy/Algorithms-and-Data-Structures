#include <iostream>
#include <bits/stdc++.h>


using namespace std;
int CountMinWays(int Coins[], int n, int Money) {
	vector<int> Ways(Money + 1, INT_MAX);
	Ways[0] = 0;
	for (int i = 1; i <= Money; i++) {
		for (int c = 0; c < n; c++) {
			if (i >= Coins[c]) {
				int sub_res = Ways[i - Coins[c]];
				if (sub_res != INT_MAX && sub_res + 1 < Ways[i])
					Ways[i] = sub_res + 1;
			}
		}
	}
	return Ways[Money];
}
int main() {
	int Money;
	cin >> Money;
	int Coins[3] = { 1,3,4 };
	cout << CountMinWays(Coins, 3, Money) << endl;

}
/*
int main()
{
    int n ; cin >> n;

    vector<int> change_money (n+30);
    change_money[0] = 0 ;
    change_money[1] = 1 ;
    change_money[2] = 2 ;
    change_money[3] = 1 ;
    change_money[4] = 1 ;

    if( n < 5) {
        cout << change_money[n] << endl;
        return 0;
    }
    for (int i =5 ; i<= n+1 ; i++)
    {
        int one = change_money[i-1] + 1;
        int three = change_money[i-3] + 1;
        int four = change_money[i-4] + 1;

        int solution =  min( min(one,three) , four );
        change_money[i] = solution;
//        cout << solution << endl;
    }
    cout << change_money[n+1];

    return 0;
}
*/

