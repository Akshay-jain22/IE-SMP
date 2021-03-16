// Ques - Given weights and values of n items,
// we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.

#include <iostream>
using namespace std;

int KnapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    int DP[n + 1][W + 1];
    for (i = 0; i <= n; i++)
        for (j = 0; j <= W; j++)
        {
            if (i == 0 || j == 0)
                DP[i][j] = 0;
            else if (wt[i - 1] <= j)
                DP[i][j] = max(val[i - 1] + DP[i - 1][j - wt[i - 1]], DP[i - 1][j]);
            else
                DP[i][j] = DP[i - 1][j];
        }
    return DP[n][W];
}
int main()
{
    int n = 1, val[] = {500}, wt[] = {30}, W = 10;
    cout << KnapSack(W, wt, val, n);
}