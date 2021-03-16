// Q- Farmer John has built N (2 <= N <= 100,000) stalls.
// The stalls are located along a straight line at positions x1,...,xN (0 <= xi <= 1,000,000,000).
// His C (2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall.
// To prevent the cows from hurting each other, FJ wants to assign the cows to the stalls,
// such that the minimum distance between any two of them is as large as possible.
// What is the largest minimum distance? (All xi are distinct)

#include <bits/stdc++.h>
using namespace std;
int N, C;
bool check(int mid, int x[])
{
	int cow_placed = 1, previousPos = x[0]; // assuming we places 1st cow at x1
	for (int i = 1; i < N; i++)
	{
		if (x[i] - previousPos >= mid)
		{
			previousPos = x[i];
			cow_placed++;
		}
		if (cow_placed == C)
			return true;
	}
	return false;
}
int main()
{
	int low, high, ans = 0, mid;
	cout << "Enter the no. of stalls and cows : ";
	cin >> N >> C;
	int x[N];
	cout << "Enter the positions of stalls : " << endl;
	for (int i = 0; i < N; i++)
		cin >> x[i];
	low = 1;
	high = x[N - 1] - x[1];
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (check(mid, x))
		{
			ans = max(ans, mid);
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	cout << "The largest minimum distance is " << ans;
}