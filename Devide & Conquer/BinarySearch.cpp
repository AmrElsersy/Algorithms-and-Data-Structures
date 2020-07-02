#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int binarySearch(vector<int> arr,int start, int End , int x)
{
    if ( start == End )
    {
        if(x == arr[start])
            return start ; // or end
        else
            return -1 ;
    }

    int mid = (start + End) /2;
    if ( x == arr[mid])
        return mid;
    else if ( x < arr[mid])
        return binarySearch(arr,start,mid ,x );
    else
        return binarySearch(arr,mid+1 , End, x);
}
using namespace std;

int BinarySearch(vector<int> Arr, int n, int Target) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (Arr[mid] == Target)
			return mid;
		else if (Arr[mid] < Target) {
			l = mid + 1;
		}
		else if (Arr[mid] > Target) {
			r = mid - 1;
		}
	}
	return -1;
}
void FindinFirst(vector<int> First, int n, vector<int> Second, int k) {
	for (int i = 0; i < k; i++)
		cout << BinarySearch(First,n, Second[i]) << " ";
}
int main() {
	int n;
	cin >> n;
	vector<int> First(n);
	for (size_t i = 0; i < n; i++)
		cin >> First[i];

	int k;
	cin >> k;
	vector<int> Second(k);
	for (size_t i = 0; i < k; i++)
		cin >> Second[i];

	FindinFirst(First, n, Second, k);
}


    return 0;
}

