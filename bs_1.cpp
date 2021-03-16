// Q- You are given an integer array of size N which is initially strictly increasing and then strictly decreasing. It might be only strictly increasing or strictly decreasing.
// Example - { 1, 3, 5, 7, 6, 4, 2} , { 2, 4 ,6} , { 8, 7, 4, 1} are valid arrays and {1, 3, 6, 4, 7} ,
//  { 2, 2, 4} are invalid arrays.
// Your task is to find the max element in the given valid array in O(log(N)).
// (All array elements will be greater than equal to 0)

#include <bits/stdc++.h>
using namespace std;
int maxArr(int arr[]);
int main()
{
    int N;
    cout << "Enter size of array : ";
    cin >> N;
    int arr[N];
    cout << "Enter the values of array elements :" << endl;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    cout << maxArr(arr);
}
int maxArr(int arr[])
{
    int l = 0, h, mid;
    h = 4;
    mid = l + (h - l) / 2;
    int flag = 1;
    while (flag)
    {
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1] || mid == l || mid == h)
        {
            flag = 0;
            return arr[mid];
        }
        if (arr[mid] > arr[mid - 1])
        {
            l = mid;
            mid = l + (h - l) / 2;
        }
        else if (arr[mid] > arr[mid + 1])
        {
            h = mid;
            mid = l + (h - l) / 2;
        }
    }
}