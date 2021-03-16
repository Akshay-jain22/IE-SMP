// Calculate the  maximum subarray sum in a given array

#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "Enter the size of array : ";
	cin >> n;
	int a[n];
	cout << "Enter the elements of array : " << endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int maxi = a[0];
	int end = a[0];
	for (int i = 1; i < n; i++)
	{
		end = max(a[i], end + a[i]);
		maxi = max(maxi, end);
	}
	cout << maxi;
}