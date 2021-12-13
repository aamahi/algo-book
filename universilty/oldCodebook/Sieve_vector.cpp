#include<iostream>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#define pi 2*acos(0.0)
using namespace std;

bool mark [500000];
vector <int> primeList;

void sieve (void )
{
    memset(mark,1,sizeof(mark));
    mark [0] = mark [1] = false;

    for ( int i = 4; i < 500000; i += 2 ) mark [i] = false;

    for ( int i = 3; i * i <= 500000; i += 2 )
        if ( mark [i] ) for ( int j = i * i; j < 500000; j += 2 * i ) mark [j] = false;

    primeList.push_back (2);

    for ( int i = 3; i < 500000; i += 2 ) if ( mark [i] ) primeList.push_back (i);

    // printf ("%d\n", primeList.size ());
}
vector<int> calc_primes(int max);
int ara[1500000];
int ara_2[1000000];
int main()
{
    int max = 100,j=0;

    vector<int> primes = calc_primes(max);
    int k=1;
    for(int i = 2; i <20000000&& j<1500000; i++)
    {
	    if(primes[i] == 0)
        {
            ara[j]=i;
            if( j!=0 && (ara[j] - ara[j-1])==2 )
            {
                ara_2[k]=ara[j];
                k++;
            }
            j++;
        }
    }
    int num;
    while( cin >> num )
    {
        printf("(%d, %d)\n",ara_2[num]-2,ara_2[num]);
    }
    return 0;
}

vector<int> calc_primes(int max)
{
    vector <int> primes;

    for(int i = 0; i <= 20000000; i++)
    {
	    primes.push_back(0);
    }

    for(int i = 2; i < primes.size(); i++)
    {
	    if( primes[i] == 0)
        {
            for( int j=2 ; i*j<=20000000  ;  j++ )
                primes[i*j]=1;
        }
    }
    return primes;
}
