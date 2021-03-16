// Ques - Given weights and values of n items,
// we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack.
// We can break items for maximizing the total value of knapsack

#include <iostream>
using namespace std;

int main()
{
    int n, W, max = 0;
    cout << "Enter number of items : ";
    cin >> n;
    float arr[n][2], ratio[n]; // arr of n weights[1] and n values[0]
    cout << "Enter weights and values of n items :" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i][0] >> arr[i][1];
        ratio[i] = arr[i][0] / arr[i][1];
    }
    cout << "Enter capacity of knapsack : ";
    cin >> W;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (ratio[i] < ratio[j])
            {
                ratio[i] += ratio[j] - (ratio[j] = ratio[i]);
                arr[i][0] += arr[j][0] - (arr[j][0] = arr[i][0]);
                arr[i][1] += arr[j][1] - (arr[j][1] = arr[i][1]);
            }
    int i = 0;
    while (W)
    {
        if (W - arr[i][1] >= 0)
        {
            W -= arr[i][1];
            max += arr[i][0];
            i++;
        }
        else
        {
            max += arr[i][0] * W / arr[i][1];
            W = 0;
        }
    }
    cout << "The maximum value in Knapsack is : " << max;
}