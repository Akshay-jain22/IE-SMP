// Ques - You have n jobs.
// Each job can be completed at any time and takes ti time to complete and has a point value of pi.
// But with each second, the point value of the ith job decreases by di. If you have to complete all the jobs,
// what is the maximum points that you can get?
// For ith job where 1 <= i <= n
//        ti - time taken to complete the job
//        pi - points received after completing the job
//        di - points decreased from pi for every second till the job has not finished

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of jobs : ";
    cin >> n;
    int t[n], p[n], d[n], ratio[n];
    cout << "Enter time taken, points received and points decreased for n jobs : " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> t[i] >> p[i] >> d[i];
        ratio[i] = d[i] / t[i];
    }
    int points = 0, time = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (ratio[i] < ratio[j])
            {
                ratio[i] += ratio[j] - (ratio[j] = ratio[i]);
                t[i] += t[j] - (t[j] = t[i]);
                p[i] += p[j] - (p[j] = p[i]);
                d[i] += d[j] - (d[j] = d[i]);
            }
    for (int i = 0; i < n; i++)
    {
        time += t[i];
        points += p[i] - d[i] * time;
    }
    cout << "The maximum points are : " << points;
}