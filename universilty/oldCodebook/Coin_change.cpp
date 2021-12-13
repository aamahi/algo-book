#include <bits/stdc++.h>
using namespace std;
#define eps 1e-7
long long int coin[]={1,5,10,25,50};
long long int make;
long long int dp[6][30001];
long long int call(long long int i,long long int amount)
{
    if(amount==0)return 1;
    if(amount<0)return 0;
    if(i>=5) return 0;
    if(dp[i][amount]!=-1) return dp[i][amount];
    return dp[i][amount]=call(i,amount-coin[i])+call(i+1,amount);

}
int main()
{
    memset(dp,-1,sizeof(dp));
    while(cin>>make)
    {
        long long int ans=call(0,make);
        if( ans==1)printf("There is only 1 way to produce %lld cents change.\n",make);
        else printf("There are %lld ways to produce %lld cents change.\n",ans,make);
    }
    return 0;
}
