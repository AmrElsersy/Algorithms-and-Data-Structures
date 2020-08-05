#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string BW_Inverse(string bwt)
{
  string text = "";
  // get the last column of the matrix and store its index ( as we will use that index to get to the mapped line of the same char)
  vector<pair<char, int> > col1(bwt.size());
  for (int i = 0; i < bwt.size(); i++)
  	col1[i] = make_pair(bwt[i], i);
  // sort them
  sort(col1.begin(), col1.end());

  // iterate through the indexes to get the next character
  pair<char, int> symbol = col1[0];
  for (int i = 0; i < bwt.size(); i++) {
  	symbol = col1[symbol.second];
  	text += symbol.first;
  }
  return text;
}


int main()
{
    string s; cin >> s;
    cout << BW_Inverse(s) << endl;
    return 0;
}
