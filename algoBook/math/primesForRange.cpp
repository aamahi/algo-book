#include <bits/stdc++.h>
using namespace std;

set<int> SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    set<int> primes;
    for (int p = 2; p <= n; p++)
        if (prime[p])
            primes.insert(p);

    return primes;
}

int main()
{

    return 0;
}
