// Sieve of Eratosthenes
// its basically an algorithm to find the primes less than a given number

#include <iostream>
using namespace std;

#define N 1000005
int prime[N];

void seive()
{
	for (int i = 2; i <= N; i++)
	{
		if (!prime[i])
		{
			for (int j = i; j <= N; j += i)
				if (!prime[j])
					prime[j] = i;
		}
	}
}

int main()
{
	seive();
	int n, primes = 0;
	cout << "Enter the value of n : ";
	cin >> n;
	for (int i = 0; i < n; i++)
		if (prime[i] == i)
			primes++;
	cout << "The no. of primes less than n are : " << primes;
}