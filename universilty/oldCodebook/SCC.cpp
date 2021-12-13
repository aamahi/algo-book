#include <bits/stdc++.h>
using namespace std;
int node=0, edge=0;
vector<  int  > g_input[100001],rev[100001];
int col[100001],flag=1,com[100001];

stack < int > st;
/// Watch for  Forest
void take_input( void )
{
    cin >> node >> edge;
    int node_1,node_2,i;
    for( int i=0 ;i <=100001 ; i++ )
    {
        g_input[i].clear();
        rev[i].clear();
    }
    for( i=0 ; i<edge ; i++  )
    {
        cin >> node_1 >> node_2;
        g_input[node_1].push_back(node_2);
        rev[node_2].push_back(node_1);
    }
    return ;
}

void DFS( int u  )
{
    col[u]=1;
    for( int i=0 ; i< g_input[u].size() ; i++ )
        if( col[g_input[u][i]]==0 )
    {
        DFS(g_input[u][i]);
    }
    col[u]=2;
    st.push(u);
}
void DFS2( int u ,int cn )
{
    com[u]=cn;
    col[u]=1;
    cout << u << " ";
    for( int i=0 ; i< rev[u].size() ; i++ )
        if( col[rev[u][i]]==0 )
    {
        DFS2(rev[u][i],cn);
    }
    col[u]=2;
}

int main()
{
    int t,T,cnt1;
    scanf("%d",&T);
    for( int t=1 ; t<=T ; t++ )
    {
        cnt1=1;
        memset(col,0,sizeof(col));
        take_input();
        for( int i=1 ; i<=node  ; i++ )
            if( col[i]==0 )
        {
            DFS(i);
        }
        memset(col,0,sizeof(col));
        while( !st.empty() )
        {
            if( col[st.top()]==0 )
            {
                cout << cnt1 << "  ->  ";
                DFS2( st.top(),cnt1 );
                cout << endl;
                cnt1++;
            }
            st.pop();
        }
    }
    return 0;
}

