#include <bits/stdc++.h>
using namespace std;
int node=0, edge=0;
vector<  int  > g_input[1000001];
int col[1000001],par[1000001],des[1000001],fin[1000001],flag=1;
int ti;
/// Watch for  Forest
void take_input( void )
{
    cin >> node >> edge;
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

void DFS( int u )
{
    col[u]=1;
    ti++;
    des[u]=ti;
    for( int i=0 ; i< g_input[u].size() ; i++ )
        if( col[g_input[u][i]]==0 )
    {
        par[g_input[u][i]]=u;
        DFS(g_input[u][i]);
    }
    col[u]=2;
    ti++;
    fin[u]=ti;
}

int main()
{
    int t,T,cnt1,cnt2;
    scanf("%d",&T);
    for( int t=1 ; t<=T ; t++ )
    {
        cnt1=cnt2=0;
        memset(col,0,sizeof(col));
        memset(par,-1,sizeof(par));
        memset(des,-1,sizeof(des));
        memset(fin,-1,sizeof(fin));
        ti=0;
        take_input();
        for( int i=0 ; i<node  ; i++ )
            if( col[i]==0 )
        {
            DFS(i);
        }
        for( int i=0 ; i<node ; i++ )
        {
            cout << des[i] << "  " << fin[i] <<endl;
        }
    }
    return 0;
}

