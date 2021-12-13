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
#define pi 2*acos(0.0)
using namespace std;
int found;
char g_input[600][600];
int chk[550][550];
int n,m;
void bfs( int i, int j )
{
    if( i <0 || j <0 || i >=n || j >=m ) return;
    if( chk[i][j]==-1 )return;
    if( g_input[i][j] == '#' ) return;
    if( g_input[i][j]=='C')
    {
        found++;
    }
    chk[i][j]=-1;
    bfs(i-1,j);
    bfs(i,j-1);
    bfs(i,j+1);
    bfs(i+1,j);
}
void bfs_2( int i, int j ,int fd )
{
    if( i <0 || j <0 || i >=n || j >=m ) return;
    ///cout << i << "  " << j << endl;
    if( g_input[i][j] == '#' ) return;
    if( chk[i][j]==fd )return;
    if( g_input[i][j]=='C')chk[i][j]=fd;
    if( chk[i][j]==-1 )chk[i][j]=fd;
    bfs_2(i-1,j,fd);
    bfs_2(i,j-1,fd);
    bfs_2(i,j+1,fd);
    bfs_2(i+1,j,fd);
}
int main()
{
    int T,Q,x,y;
    cin >> T;

    for( int t=1 ;t<= T ; t++ )
    {
        cin >> n>> m >> Q ;
        memset(chk,0,sizeof(chk));
        for( int i=0 ; i < n ;i++ )
        {
            scanf("%s",g_input[i]);
        }
        printf("Case %d:\n",t);
        for( int i=0 ; i< Q ; i++ )
        {
            found=0;
            cin >> x >> y;
            if( chk[x-1][y-1]==0 )
            {
                bfs(x-1,y-1);
                bfs_2(x-1,y-1,found);
                cout << found << endl;
            }
            else
            {
                cout << chk[x-1][y-1] << endl;
            }
            /*for( int j=0 ; j< n ; j++ )
            {
                for( int k=0  ; k < m ; k++ )
                    cout << chk[j][k];
                cout << endl;
            }*/
        }
    }
    return 0;
}
