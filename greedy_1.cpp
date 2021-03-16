// Ques- Given a string and a positive number k, find the length of longest substring of given string containing k distinct characters.

#include <iostream>
#include <string>
using namespace std;
int main()
{
    int f[300], d = 0;
    int i = 0, j = 0, k = 0, ans = 0;
    string s;
    cout << "Enter String and k" << endl;
    cin >> s >> k;
    for (int a = 0; a < 300; a++)
        f[a] = 0;
    for (j = i; j < s.length(); j++)
    {
        f[(int)s[j]] += 1;
        if (f[(int)s[j]] == 1)
            d += 1;
        if (d == k)
            ans = ans > (j - i + 1) ? ans : (j - i) + 1;
        else if (d > k)
        {
            for (; i < j; i++)
            {
                f[(int)s[i]] -= 1;
                if (f[(int)s[i]] == 0)
                {
                    d--;
                    i++;
                    break;
                }
            }
        }
    }
    cout << "The max length is " << ans;
}