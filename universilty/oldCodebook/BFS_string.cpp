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


map<string , vector < string > > ara;
map<string, int > visit;
map< string , string > par;
int node,edge;
bool bfs( string start , string end )
{
    queue < string > q;
    q.push(start);
    visit[start]=1;
    par[start]=start;
    string s;
    vector < string > :: iterator i;
    while( !q.empty() )
    {
        s=q.front();
        q.pop();
        for( i=ara[s].begin() ; i< ara[s].end() ; i++ )
        {
            if( !visit[*i] )
            {
                visit[*i]=visit[s]+1;
                par[*i]=s;
                q.push(*i);
                if( *i == end )return true;
            }
        }
    }
    return false;
}
void path(string end, string start)
{
   if(end == start) return;
   else
   {
       path( par[end], par[par[end]] );
       cout << par[end] << " " << end << endl;
   }
}

int main()
{
    int x=0;
    string node_1,node_2;
    while( cin >> edge )
    {
        if(x)
        {
           printf("\n");
        }
        else x++;
        visit.clear();
        par.clear();
        ara.clear();
        for( int i=0 ; i< edge ; i++ )
        {
            cin >> node_1 >> node_2;
            ara[node_1].push_back(node_2);
            ara[node_2].push_back(node_1);
        }

        cin >> node_1 >> node_2 ;

        if( !bfs(node_1, node_2) ) printf("No route\n");
        else
        {
            path(node_2, node_1 );
        }
    }
    return 0;
}
