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
void  bfs ( void );
void check( int i, int j );
int g_input[1001][1001];
int e_x,e_y;
int n,m;
int s_x,s_y;
int main()
{
    while( cin >> n>> m &&(n||m))
    {
        int col;
        memset(g_input,0,sizeof(g_input));
        cin >>col;
        int x,y,num;
        for( int i=0 ; i< col ;i++ )
        {
            cin >> x >> num;
            for( int j=0 ; j <num ; j++ )
            {
                cin >> y;
                g_input[x][y]=1;
            }
        }
        cin >> s_x >> s_y >> e_x >> e_y ;
        if(s_x==e_x&&s_y==e_y)
        {
            printf("0\n");
            continue;
        }
        bfs();
        printf("%d\n",g_input[e_x][e_y]);
    }
    return 0;
}
void  bfs ( void )
{
    int i,j;
    queue < int > p,q;
    p.push(s_x);
    q.push(s_y);
    int x,y;
    while( !q.empty() &&!p.empty() )
    {
        i=p.front();
        j=q.front();
        p.pop();
        q.pop();
        x=i-1;
        y=j;
        if( x >= 0 && x<n  && y >= 0 && y < m && g_input[x][y]==0)
        {
            p.push(x);
            q.push(y);
            g_input[x][y]=g_input[i][j]+1;
                if( e_x==x && e_y==y )break;
        }
        x=i+1;
        y=j;
        if( x >= 0 && x<n  && y >= 0 && y < m && g_input[x][y]==0)
        {
            p.push(x);
            q.push(y);
            g_input[x][y]=g_input[i][j]+1;
                if( e_x==x && e_y==y )break;
        }
        x=i;
        y=j-1;
        if( x >= 0 && x<n  && y >= 0 && y < m && g_input[x][y]==0)
        {
            p.push(x);
            q.push(y);
            g_input[x][y]=g_input[i][j]+1;
                if( e_x==x && e_y==y )break;
        }
        x=i;
        y=j+1;
        if( x >= 0 && x<n  && y >= 0 && y < m && g_input[x][y]==0)
        {
            p.push(x);
            q.push(y);
            g_input[x][y]=g_input[i][j]+1;
                if( e_x==x && e_y==y )break;
        }
        if(i==s_x&&j==s_y)g_input[i][j]=-1;
    }
}
int found = 0;
void check( int i, int j )
{
    if( i < 0 || j < 0 || i >=n || j >= m ) return;
    if( g_input[i][j] == 'B' ) found  = 1; // mario can reach bipasa
    else if( g_input[i][j] == 'X' ) return;
    else
    {
        check(i-1,j);
        check(i,j-1);
        check(i,j+1);
        check(i+1,j);
    }
}
