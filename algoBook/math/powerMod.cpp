#include <bits/stdc++.h>
using namespace std;

#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
typedef long long LL;

LL modpow(LL base, LL exp, LL modulus)
{
    base %= modulus;
    LL result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = (result * base) % modulus;
        base = (base * base) % modulus;
        exp >>= 1;
    }
    return result;
}

int main()
{
    LL n, m, k;

    sdlll(n, m, k);

    cout << modpow(m, n, 1000000007) << endl;
}