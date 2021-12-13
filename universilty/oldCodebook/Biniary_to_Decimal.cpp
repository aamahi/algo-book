#include<cstdio>
#include<cstring>

int B_to_D(char ara[]);
int main()
{
    char ara[100];

    scanf("%s",ara);

    int ans;

    ans=B_to_D(ara);
    printf("%d\n",ans);

    return 0;
}
int B_to_D(char ara[])
{
    int len=strlen(ara);

    int i,ans=0,a=1;
    for( i=len - 1;  i>=0 ; i-- )
    {
        ans+=a*(ara[i]-48);
        a=a*2;
    }

    return ans ;
}
