// Ques - Given two arrays (A and B) sorted in ascending order, and an integer x.
//we need to find i and j, such that a[i] + b[j] is equal to X.
//n - the length of the array A, m - the length of the array B

#include <iostream>
using namespace std;

int main()
{
    int A[1000], B[1000];
    int n, m, x;
    cout << "Enter size of array A and B : " << endl;
    cin >> n >> m;
    cout << "Enter values of array A :" << endl;
    for (int i = 0; i < n; i++)
        cin >> A[i];
    cout << "Enter values of array B :" << endl;
    for (int i = 0; i < m; i++)
        cin >> B[i];
    cout << "Enter value of x : " << endl;
    cin >> x;
    int j = m - 1;
    for (int i = 0; i < n; ++i)
    {
        while ((j > 0) && (A[i] + B[j] > x))
        {
            j--;
        }
        if (A[i] + B[j] == x)
        {
            cout << i << " " << j << endl;
            return 0;
        }
    }
    cout << "Not found!" << endl;
}