#include <bits/stdc++.h>
using namespace std;

int node,edge;
vector  < int >  grap[100000],cost[100000];
struct num
{
 public :
    int v,w;
    num(int a,int b){ v=a; w=b; }
    bool operator < ( const num& c )const
    {
        return w > c.w;
    }
};
int visit[100000];
int mst ( int start )
{
    priority_queue < num > q;
    memset(visit,0,sizeof(visit));
    q.push(num(start,0));
    int sum=0,count=0;
    while( count != node )
    {
        num top=q.top();
        q.pop();
        int u=top.v;
        if(visit[u]==0)
        {
            sum+=top.w;
            for( int i=0 ; i<(int)grap[u].size() ; i++ )
            {
                if(visit[grap[u][i]]==0)
                q.push(num(grap[u][i],cost[u][i]));
            }
            count++;
            visit[u]=1;
        }
    }
    return sum;
}
int main()
{
    cin >> node >> edge;
    int x,y,z;
    for( int i=0 ; i<edge ; i++ )
    {
        cin >> x >> y >> z;
        grap[x].push_back(y);
        grap[y].push_back(x);
        cost[x].push_back(z);
        cost[y].push_back(z);
    }
    int n=mst(1);
    cout << n;
    return 0;
}
