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

int node , edge;
vector < int  > ara[100002],cost[100002];
vector <  int > dis,from;

void bfs( int start  );
int main()
{
    int x,y,z;
    stack < int > s;
    cin >> node >> edge ;
    for( int j=0 ; j <= node ; j++ )
    for( int i=0 ; i <= node ; i++)
    {
        cost[j].push_back(0);
    }
    for( int i=0 ; i < edge  ; i++ )
    {
        cin >> x >> y >> z;
        ara[y].push_back(x);
        ara[x].push_back(y);
        cost[x][y]=z;
        cost[y][x]=z;
    }
    bfs(1);
    int last=node;
    if( dis[node]==1000000000)printf("-1\n");
    else
    {
    while( 1 )
    {
        if( from[node]==1 )break;
        else
        {
            s.push(from[node]);
            node=from[node];
        }
    }
    printf("1 ");
    while( !s.empty() )
    {
        printf("%d ",s.top() );
        s.pop();
    }
    printf("%d\n",last);
    }
}
void bfs( int start  )
{
    for ( int i=0 ; i<=node ; i++ )
    {
        dis.push_back(1000000000);
        from.push_back(-1);
    }
    queue < int > q;
    q.push(start);
    dis[start]=0;
    while( !q.empty())
    {
        int u=q.front();
        q.pop();
        for( int i=0 ; i <(int)ara[u].size() ; i++ )
        {
            int v=ara[u][i];
            if( dis[v]> dis[u] +cost[u][v])
            {
                dis[v]=dis[u]+cost[u][v];
                q.push(v);
                from[v]=u;
            }
        }
    }
}

