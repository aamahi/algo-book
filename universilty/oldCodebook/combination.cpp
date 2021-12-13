#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
unsigned long long com(unsigned long long n, unsigned long long k);
int main()
{
    int n,m;
    while( cin >> n >> m )
    {
        cout << com(n,m) << endl;
    }
    return 0;
}
unsigned long long com(unsigned long long n, unsigned long long k)
{
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; d++)
    {
        r *= n--;
        r /= d;
    }
    return r;
}
