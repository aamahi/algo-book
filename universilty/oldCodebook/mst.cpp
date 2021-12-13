#include <bits/stdc++.h>
using namespace std;

struct num
{
	int u,v,w;
	bool operator < ( const num& p ) const
	{
		return w < p.w;
	}
};
int node ,edge ;
vector < num > ara;
int par[100000];
int find_r( int r )
{
    if(par[r]==r)return r;
    else
    {
        return par[r]=find_r(par[r]);
    }
}
int mst( void )
{
    sort( ara.begin(),ara.end() );
    for( int i=0 ; i< node ; i++ )
        par[i]=i;
    int sum=0,count=0 ;
    for( int i=0 ; i<edge ; i++ )
    {
        int u=ara[i].u;
        int v=ara[i].v;
        int w=ara[i].w;
        int x=find_r(u);
        int y=find_r(v);
        if( x!=y )
        {
            par[x]=y;
            sum+=w;
            count++ ;
            if(count == node - 1 )break;
        }
    }
    return sum;
}

int main()
{
    cin >> node >> edge ;
    num get;
    for( int i=0 ; i < edge ; i++ )
    {
        cin >> get.u >> get.v >> get.w;
        ara.push_back( get );
    }
    cout << mst() ;

    return 0;
}
