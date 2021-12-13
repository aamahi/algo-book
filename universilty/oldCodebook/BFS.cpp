#include <bits/stdc++.h>
using namespace std;
int node=0, edge=0;
vector<  int  > g_input[20005];
int visit[20005],dis[20005];

/// Watch for  Forest
void take_input( void )
{
    cin >> edge;
    int node_1,node_2,i;
    for( int i=0 ;i <=20002 ; i++ )
    g_input[i].clear();
    for( i=0 ; i<edge ; i++  )
    {
        cin >> node_1 >> node_2;
        g_input[node_1].push_back(node_2);
        g_input[node_2].push_back(node_1);
    }
    return ;
}
void bfs( int start )
{

    queue < int > q;
    q.push(start);
    visit[start]=1;
    dis[start]=0;
    int j,root;
    for(  ; q.empty()==0 ; )
    {
        root=q.front();
        q.pop();
        for(j=0; j<g_input[root].size() ; j++)
        {
            if(visit[g_input[root][j]]==0)
             {
                q.push(g_input[root][j]);
                visit[g_input[root][j]]=1;
                dis[g_input[root][j]]=dis[root]+1;
             }
        }
    }
}
int main()
{
    int t,T;
    scanf("%d",&T);
    for( int t=1 ; t<=T ; t++ )
    {
        memset(visit,0,sizeof(visit));
        memset(dis,0,sizeof(dis));
        take_input();
        bfs(1);
        for( int i=2 ; i<=20002 ; i++ )
        {
            cout << dis[i] << endl;
        }
    }
    return 0;
}
