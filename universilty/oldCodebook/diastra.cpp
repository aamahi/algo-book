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

struct node
{
public :
    int v,w;
    node(int a,int b){ v=a; w=b; }
    bool operator < ( const node& c )const
    {
        return w > c.w;
    }
};

vector  < int >  grap[100001],cost[100001];
int par[100001];
long long int dis[100001];
int node_n ,edge ;

void diastra(int start,int finish )
{
    memset(par,-1,sizeof(par));
    for( int i=0 ; i<=node_n ; i++ )
        dis[i]=1000000000000000;
    priority_queue < node > q;
    q.push(node(start,0));
    dis[start]=0;
    par[start]=start;
    while( !q.empty() )
    {
        node top=q.top();
        q.pop();
        int u=top.v;
        ///if(u==finish) return ;
        for( int i=0 ; i<(int)grap[u].size() ; i++ )
        {
            int v=grap[u][i];
            if(dis[u]+cost[u][i] < dis[v] )
            {
                dis[v]=dis[u]+cost[u][i];
                par[v]=u;
                q.push(node(v,dis[v]));
            }
        }
    }
}
void path( int finish  )
{
    if(par[finish]==finish)return;
    path(par[finish]);
    printf("%d ",par[finish]);
}
int main()
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
    diastra(1 , node_n );
    for( int i=1 ; i<=node_n ; i++ )
        printf( "%d ",dis[i]);
        printf("\n");
    if( par[node_n]==-1 )printf("-1\n");
    else
    {
        path(node_n);
        printf("%d\n",node_n);
    }
    return 0;
}
