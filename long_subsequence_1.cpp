// Q. Given two sequences, find the length of longest subsequence present in both of them.

#include <iostream>
using namespace std;
int LCS(int n, int m);
string s = "tezcatlipoca", t = "quetzalcoatl";
const int n = 12, m = 12;
int DP[n + 1][m + 1];
int main()
{
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
            DP[i][j] = -1;
    cout << LCS(n, m);
}
int LCS(int n, int m)
{
    if (m == 0 || n == 0)
        return 0;
    if (DP[n][m] != -1)
        return DP[n][m];
    if (s[n - 1] == t[m - 1])
        return DP[n][m] = 1 + LCS(n - 1, m - 1);
    return DP[n][m] = max(LCS(n, m - 1), LCS(n - 1, m));
}