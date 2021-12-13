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
char ara[1000],ara_2[1000];
void add ( void )
{
    int len=strlen(ara);
    int len_2=strlen(ara_2);
    int carry=0,sum;
    int ara_r[1000];
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
    char pro[1000],pro_2[1000];
    while( scanf("%s",pro)!=EOF )
    {
        int carry,sum,i,j,k;
        scanf("%s",pro_2);
        int len=strlen(pro);
        int len_2=strlen(pro_2);
        for(  i=len - 1,k=0 ; i>=0 ; i--,k++ )
        {
            carry=0;
            if(i==len-1)
            {
                for( j=len_2-1 ; j>=0 ; j-- )
                {
                    sum=(pro[j]-48)*(pro_2[i]-48)+carry;
                    ara[j+1]=sum%10+48;
                    carry=sum/10;
                    //printf("%d\n",sum);
                }
                if(carry)ara[j+1]=carry+48;
                else ara[j+1]=48;
                //printf("%s\n",ara);
                continue;
            }
            else
            {
                for( j=len_2-1 ; j>=0 ; j-- )
                {
                    sum=(pro[j]-48)*(pro_2[i]-48)+carry;
                    ara_2[j+1]=sum%10+48;
                    carry=sum/10;
                }
                if(carry)ara_2[j+1]=carry+48;
                else ara_2[j+1]=48;
                for( j=len_2+1 ; j<len_2+1+k ; j++ )
                {
                    ara_2[j]=48;
                }
                //printf("%s\n",ara_2);
                add();
            }
        }
        len=strlen(ara);
        //printf("%d",len);
        int flag=1;
        for( int i=0 ; i<len ; i++ )
        {
            if(ara[i]==48&&flag)continue;
            else
            {
                printf("%c",ara[i]);
                flag=0;
            }
        }
        printf("\n");
    }

    return 0;
}
