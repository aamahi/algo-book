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
int node, edge;
vector<  int  > g_input[222];
int visit[220],dis[220],par[220],col[220];

/// Watch for  Forest
void take_input( void )
{
    cin >> node >> edge ;
    int node_1,node_2,i;
    for( i=0 ;i <=220 ; i++ )
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
    col[start]=1;
    int i,j,root;
    for( i=0 ; q.empty()==0 ; i++ )
    {
        root=q.front();
        q.pop();
        for(j=0; j<g_input[root].size() ; j++)
        {
            if(visit[g_input[root][j]]==0)
             {
                par[g_input[root][j]]=root;
                q.push(g_input[root][j]);
                visit[g_input[root][j]]=1;
                dis[g_input[root][j]]=dis[root]+1;
                if( col[root]==1)col[g_input[root][j]]=2;
                else col[g_input[root][j]]=1;
             }
        }
    }
}

int main()
{

    int t,T,cnt1,cnt2,flag,sum;
    scanf("%d",&T);
    for( int t=1 ; t<=T ; t++ )
    {
        sum=0;
        memset(visit,0,sizeof(visit));
        memset(dis,0,sizeof(dis));
        memset(col,0,sizeof(col));
        memset(par,0,sizeof(par));
        take_input();
        flag=0;
        while( 1 )
        {
            int i;
            cnt1=cnt2=0;
            for( i=0 ; i < node ; i++ )
                if( visit[i]==0 )
            {
                bfs(i);
                break;
            }
            if( i==node )break;

            for( int i=0 ; flag==0 && i< node ; i++ )
                for( int j=0 ; j<g_input[i].size() ; j++ )
            {
                if(  col[i] && col[g_input[i][j]] && col[i]==col[g_input[i][j]])
                {
                    flag=1;
                    break;
                }
            }
            if(flag)break;
            for( int i=0 ; i < node ; i++ )
            {
                if( col[i]==1 )cnt1++;
                if( col[i]==2 )cnt2++;
                col[i]=0;
            }
            if( cnt1==1 && cnt2==0 )sum++;
            sum+=min(cnt1,cnt2);

        }
        if( flag )printf( "-1\n");
        else printf("%d\n",sum);
    }
    return 0;
}
