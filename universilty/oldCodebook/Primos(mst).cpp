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

struct num
{
	int u,v,w;
	bool operator < ( const num& p ) const
	{
		return w > p.w;
	}
};
int node=0, edge=0;
vector<  int  > g_input[20005],cost[20005];
int visit[20005],dis[20005];
int sum;
/// Watch for  Forest
void take_input( void )
{
    cin >> node >> edge;
    int node_1,node_2,i,z;
    for( int i=0 ;i <=20002 ; i++ )
    g_input[i].clear();
    for( i=0 ; i<edge ; i++  )
    {
        cin >> node_1 >> node_2 >> z;
        g_input[node_1].push_back(node_2);
        g_input[node_2].push_back(node_1);
        cost[node_1].push_back(z);
        cost[node_2].push_back(z);
    }
    return ;
}
void mst_p( int start )
{
    priority_queue < num > q;
    num get;
    get.u=start;
    for(int i=0 ; i<(int)g_input[start].size() ; i++ )
    {
        get.v=g_input[start][i];
        get.w=cost[start][i];
        q.push(get);
        ///cout <<"   " <<get.w << endl;
    }
    visit[start]=1;
    while( !q.empty() )
    {
        num top=q.top();
        q.pop();
        int u=top.u;
        int v=top.v;
        if( visit[u]==0 || visit[v]==0 )
        {
            for(int i=0 ; i<(int)g_input[v].size() ; i++ )
            {
                get.u=top.u;
                get.v=g_input[v][i];
                get.w=cost[v][i];
                if( visit[get.v]==0 )
                {
                    q.push(get);
                    ///cout <<"   " <<get.w << endl;
                }
            }
            sum+=top.w;
            cout<< sum << endl;
            visit[v]=1;
        }
    }
}
int main()
{
    take_input();
    sum=0;
    mst_p(1);
    cout << sum;
    return 0;
}
