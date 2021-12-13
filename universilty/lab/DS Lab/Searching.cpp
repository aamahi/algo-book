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
void b_sort( int ara[] ,int n )
{
    int x,y;
    for( int i=0 ; i<n ; i++ )
        for( int j=i+1 ; j<n ; j++ )
        if( ara[i] > ara[j] )
    {
        x=ara[i];
        ara[i]=ara[j];
        ara[j]=x;
    }
}
int liner_search( int ara[] ,int number, int n)
{
    for( int i=0 ; i< n ; i++ )
    {
        if( ara[i]==number )
        {
            return 1;
        }
    }
    return 0;
}
int b_search( int ara[] ,int number ,int low, int high )
{
    int mid=( low+high)/2;
    if( high < low )return 0;
    if( ara[mid]==number )return 1;
    else if( ara[mid] < number)return b_search( ara , number , mid+1 ,high );
    else if( ara[mid] > number)return b_search( ara , number , low , mid-1 );
}
int main()
{
    int ara[1000];
    FILE *fp;
    fp=fopen("Dcoment.txt","r");
    int x,y,i=0;
    while( scanf("%d",&x ))
    {
        if( x==1 )
        {
            scanf("%d",&y);
            ara[i]=y;
            i++;
        }
        if( x==2 )
        {
            b_sort(ara,i);
        }
        if( x==3 )
        {
            for( int j=0 ; j<i ; j++ )
            {
                printf("%d ",ara[j]);
            }
            cout << endl;
        }
        if( x==4 )
        {
            scanf("%d",&y);
            int z=liner_search(ara,y,i);
            if( z==1)cout << "Found"<<endl;
            else cout << "Not Found" << endl;
        }
        if( x==5 )
        {
            scanf("%d",&y);
            int z=b_search(ara,y,0,i-1);
            if( z==1)cout << "Found"<<endl;
            else cout << "Not Found" << endl;
        }
    }
    return 0;
}
