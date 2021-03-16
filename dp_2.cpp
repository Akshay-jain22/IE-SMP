// N buildings are built in a row, numbered 1 to N from left to right.
// Spiderman is on building number 1, and want to reach building number N.
// He can jump from building number i to building number j iff i < j and j-i is a power of 2 (1,2,4, so on).
// Such a move costs him energy |Height[j]-Height[i]|, where Height[i] is the height of the ith building.
// Find the minimum energy using which he can reach building N?

#include <bits/stdc++.h>
using namespace std;
int min_energy(int n, int h[])
{
    int dp[n + 1];
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = INT_MAX;
        for (int j = 1; j < i; j *= 2)
            dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
    }
    return dp[n];
}
int main()
{
    int n;
    cout << "Enter the no. of buildings : ";
    cin >> n;
    int h[n + 1];
    cout << "Enter the heights of buildings :" << endl;
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    cout << "The minimum required energy is " << min_energy(n, h);
}