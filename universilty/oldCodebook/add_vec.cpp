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

void add ( char ara[],char ara_2[] )
{
    int len=strlen(ara);
    int len_2=strlen(ara_2);
    int carry=0,sum;
    int ara_r[100000];
    int l=0;
    for( int i=len-1 ,j=len_2-1  ; i>=0 || j >=0 ; i--, j--,l++ )
    {
        if(  j>=0 && i>=0 )
        {
            sum=ara[i]+ara_2[j]-96+carry;
            if(sum>9)
            {
                ara_r[l]=sum%10;
                carry=1;
            }
            else
            {
                ara_r[l]=sum;
                carry=0;
            }
        }
        else if( i >= 0 )
        {
            sum=ara[i]-48+carry;
            if(sum>9)
            {
                ara_r[l]=sum%10;
                carry=1;
            }
            else
            {
                ara_r[l]=sum;
                carry=0;
            }
        }
        else if( j >= 0 )
        {
            sum=ara_2[j]-48+carry;
            if(sum>9)
            {
                ara_r[l]=sum%10;
                carry=1;
            }
            else
            {
                ara_r[l]=sum;
                carry=0;
            }
        }
    }
    if(carry)ara_r[l]=1;
    else l--;
    for( int i=l,j=0 ; i>= 0 ; i--,j++ )
    {
        ara[j]=ara_r[i]+48;
    }
}

int main()
{
    int t;
    cin >> t;
    char ara[100000],ara_2[100000];
    while( t-- )
    {
        scanf("%s %s",ara,ara_2);
        add(ara,ara_2);
        printf("%s\n",ara);
    }
    return 0;
}
