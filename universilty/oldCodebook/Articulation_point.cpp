#include <bits/stdc++.h>
using namespace std;

int node=0, edge=0;
vector<  int  > g_input[100001];
int col[100001],par[100001],des[100001],fin[100001],low[100001];
int ti;

pair <int,int> p[10000];
int k;

void take_input( void )
{
    int node_1,num,node_2;
    for( int i=0 ;i <=20002 ; i++ )
    g_input[i].clear();
    for( int  i=0 ; i < node ; i++  )
    {
        scanf("%d (%d)",&node_1,&num);
        for(int j=0 ; j<num ; j++ )
        {
            scanf("%d",&node_2);
            g_input[node_1].push_back(node_2);
        }
    }
    return ;
}
void DFS( int u )
{
    col[u]=1;
    ti++;
    des[u]=ti;
    low[u]=des[u];
    for( int i=0 ; i< g_input[u].size() ; i++ )
    {
        if( col[g_input[u][i]]==0 )
        {
            par[g_input[u][i]]=u;
            DFS(g_input[u][i]);
            if (low[g_input[u][i]] > des[u] )
            {
                if( u < g_input[u][i] )
                {
                    p[k].first=u;
                    p[k].second=g_input[u][i];
                    k++;
                }
                else
                {
                    p[k].second=u;
                    p[k].first=g_input[u][i];
                    k++;
                }
            }
            if (low[g_input[u][i]] < low[u]) low[u] = low[g_input[u][i]];

        }
        if ( par[u]!=g_input[u][i] && des[g_input[u][i]] < low[u]) low[u] = des[g_input[u][i]];
    }
    col[u]=2;
    ti++;
    fin[u]=ti;
}

int main()
{
    while( cin >> node )
    {
        k=0;
        memset(col,0,sizeof(col));
        memset(low,100000000,sizeof(low));
        memset(par,-1,sizeof(par));
        memset(des,100000000,sizeof(des));
        memset(fin,100000000,sizeof(fin));
        ti=0;
        take_input();

        for( int i=0 ; i<node  ; i++ )
            if( col[i]==0 )
        {
            DFS(i);
        }
        cout << k << " critical links"<<endl;
        sort( p,p+k );
        for( int i=0 ; i<k ; i++ )
        {
            cout << p[i].first<< " - " << p[i].second << endl;
        }
        cout << endl;
    }
    return 0;
}

