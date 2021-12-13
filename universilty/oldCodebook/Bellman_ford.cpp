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
#define pi 2*acos(0.0)
using namespace std;

vector  < int >  grap[100001],cost[100001];
long long int dis[100001];
int node_n ,edge ;

int main()
{
    int t;
    cin >>t ;
    while( t-- )
    {
        cin >> node_n >> edge;
        int x,y,z;
        for( int i=0 ; i<edge ; i++ )
        {
            cin >> x >> y >> z;
            grap[x].push_back(y);
            ///grap[y].push_back(x);
            cost[x].push_back(z);
            ///cost[y].push_back(z);
        }
        memset(dis,100000000000000,sizeof(dis));
        for( int i=0 ; i < node_n-1 ; i++ )
        {
            for( int n=0 ; n <node_n ; n++ )
            {
                for( int j=0 ; j< grap[n].size() ; j++ )
                {
                    if( dis[grap[n][j]] > dis[n] + cost[n][j] )
                    {
                        dis[grap[n][j]] = dis[n] + cost[n][j];
                    }
                }
            }
        }
        /*for( int n=0 ; n< node_n ; n++ )
        {
            cout << dis[n] << endl;
        }*/
        int f=1;
        for( int n=0 ; f && n <node_n ; n++ )
        {
            for( int j=0 ; f && j< grap[n].size() ; j++ )
            {
                if( dis[grap[n][j]] > dis[n] + cost[n][j] )
                {
                    f=0;
                }
            }
        }
        if( f )cout << "not possible" << endl;
        else cout << "possible" << endl;
        for( int n=0 ; n< node_n ; n++ )
        {
            grap[n].clear();
            cost[n].clear();
        }
    }
    return 0;
}
