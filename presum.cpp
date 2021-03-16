// Given an array of size n , consisting of integers.
// You have to tell the sum of all integers in a given range( l to r (inclusive))?

#include <iostream>
using namespace std;

void presum(int arr[], int n, int l, int r)
{
	int pre_sum[n + 1] = {0};
	for (int i = 1; i <= n; i++)
		pre_sum[i] = pre_sum[i - 1] + arr[i - 1];
	cout << pre_sum[r] - pre_sum[l - 1];
}

int main()
{
	int n;
	cout << "Enter size of array : ";
	cin >> n;
	int arr[n], l, r;
	cout << "Enter the elements of aray : " << endl;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	cout << "Enter values of l and r : ";
	cin >> l >> r;
	presum(arr, n, l, r);
}