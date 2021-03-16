// Q- Little Petya likes points a lot. Recently his mom has presented him n points lying on the line OX.
// Now Petya is wondering how many ways he can choose three distinct points so that the distance between the two farthest of them doesn't exceed d.
// Note that the order of the points inside the group of three chosen points doesn't matter.

// Input : The first line contains two integers: n and d (1 ≤ n ≤ 10^5; 1 ≤ d ≤ 10^9).
// The next line contains n integers x1, x2, ..., xn, their absolute value doesn't exceed 10^9 — the x-coordinates of the points that Petya has got.
// It is guaranteed that the coordinates of the points in the input strictly increase.
// Output : Print a single integer — the number of groups of three points, where the distance between two farthest points doesn't exceed d

#include <bits/stdc++.h>
using namespace std;

int main()
{
	int ans = 0;
	int n, d;
	cout << "Enter the values of n and d : ";
	cin >> n >> d;
	vector<int> v(n);
	cout << "Enter the n coordinates :" << endl;
	for (int i = 0; i < n; i++)
		cin >> v[i];
	for (int i = 0; i < n - 2; i++)
	{
		long long a = (upper_bound(v.begin(), v.end(), v[i] + d) - v.begin());
		long long b = a - i - 1;
		b = (b * (b - 1)) / 2;
		ans += b;
	}
	cout << "The number of groups of three points are " << ans;
}