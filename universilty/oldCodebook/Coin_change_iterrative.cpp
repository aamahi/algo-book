#include <bits/stdc++.h>
using namespace std;
#define eps 1e-7
long long int coin[]={1,5,10,25,50};
long long int make;
long long int dp[30001];
int main()
{
    memset(dp,10,sizeof(dp));
    dp[0]=0;
    while(cin>>make)
    {
        for( int i=0 ; i<5 ; i++ )
            for( int sum=coin[i] ; sum <=make ; sum++ )
        {
            dp[sum]=min(dp[sum],dp[sum-coin[i]]+1);
        }
        cout << dp[make] << endl;
    }
    return 0;
}
