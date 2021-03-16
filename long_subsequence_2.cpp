#include <bits/stdc++.h>
using namespace std;
int LCS(string s, string t, int m, int n);
int main()
{
    string s = "tezcatlipoca";
    string t = "quetzalcoatl";
    int n = s.length();
    int m = t.length();
    cout << LCS(s, t, n, m);
    return 0;
}
int LCS(string s, string t, int n, int m)
{
    int DP[n + 1][m + 1];
    int i, j;
    for (i = 0; i <= n; i++)
        for (j = 0; j <= m; j++)
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (s[i - 1] == t[j - 1])
                DP[i][j] = DP[i - 1][j - 1] + 1;
            else
                DP[i][j] = max(DP[i - 1][j], DP[i][j - 1]);
    return DP[n][m];
}