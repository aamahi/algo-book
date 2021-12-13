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
    while( t-- )
    {
        char ara_3[1000],ara_4[1000];
        char ara[1000],ara_2[1000];
        scanf("%s %s",ara_3,ara_4);
        int len_3=strlen(ara_3);
        int len_4=strlen(ara_4);
        for( int i=0 ; i < 300 ; i++ )
        {
            ara[i]=0;
            ara_2[i]=0;
        }
        for( int i=len_3-1,j=0 ; i>=0 ; i--,j++ )
        {
            ara[i]=ara_3[j];
        }
        for( int i=len_4-1,j=0 ; i>=0 ; i--,j++ )
        {
            ara_2[i]=ara_4[j];
        }
        add(ara,ara_2);
        int len=strlen(ara);
        int flag=0;
        for( int i=len-1 ; i>=0 ; i-- )
        {
            if( flag || ara[i]!='0' )
            {
                printf("%c",ara[i]);
                flag=1;
            }
        }
        printf("\n");
    }
    return 0;
}
