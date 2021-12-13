#include <bits/stdc++.h>
using namespace std;

///number constant
#define eps 1e-9
#define inf 1e19
#define pi 3.14159265358979323846264338327950

///memset
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))

///stl
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define pii pair< int, int >
#define psi pair< string, int >

///data type
#define i64 long long
#define ui64 unsigned long long
#define ld long double

///printf
#define NL printf("\n")
#define OK printf("ok\n")

///file
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)


/// Powers
template <class T> inline T sqr( T x ) { return x*x; }
template <class T> inline T cube( T x ) { return x*x*x; }
template <class T> inline T powr( T x, T y) { T ret = 1; while(y--) ret *= x;  return ret;}

///mod
template <class T> inline T mod ( T a , T b ){return (a%b+b)%b;}

/// GCD, LCM
template <class T> inline T GCD( T a, T b ) { if( a < 0 ) return GCD( -a , b );if( b < 0 ) return GCD( a, -b ); return ( b == 0 ) ? a : GCD( b, a%b ); }
template <class T> inline T LCM( T a, T b ) { if( a < 0 ) return LCM( -a, b );if( b < 0 ) return LCM( a, -b ); return a * ( b / GCD( a, b ) ); }

/// Prime
template <class T> inline bool isPrime( T n ) { if( n <= 1 ) return false;for( T i = 2; i*i <= n; i++ ) if( n % i == 0 ) return false; return true; }

/// Debugs
template <class T> inline void debug( T x ){ cout << "x = " << x << endl; }
template <class T1, class T2> inline void debug( T1 x, T2 y ){ cout << "x = " << x << ", y = " << y << endl; }
template <class T1, class T2, class T3> inline void debug( T1 x, T2 y, T3 z ){ cout << "x = " << x << ", y = " << y << ", z = " << z << endl; }

/// 4 Direction
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

/// 8 Direction
//int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};


char g_input[100][100];
int px[100][100],py[100][100];
int chk[100][100];
int n,m;
int flag;

int valid( int i ,int j )
{
    if( i < 0 || j < 0  || i >= n || j >= m )return 0;
    return 1;
}

void bfs ( int a , int b  )
{
    chk[a][b]=1;
    char ch=g_input[a][b];
    int i,j,x,y;
    SET(px);
    SET(py);
    queue < int > p,q;
    p.push(a);
    q.push(b);
    while( !q.empty() &&!p.empty() )
    {
        i=p.front();
        j=q.front();
        p.pop();
        q.pop();
        ///debug(i,j);
        for( int k=0 ; k < 4 ; k++  )
        {
            x=i+dx[k];
            y=j+dy[k];
            if( valid(x,y) && g_input[x][y]==ch && chk[x][y]==0)
            {
                p.push(x);
                q.push(y);
                chk[x][y]=chk[i][j]+1;
                px[x][y]=i;
                py[x][y]=j;
            }
            else if( valid(x,y) && g_input[x][y] == ch  && chk[x][y]!= 0 && chk[x][y]+1 != chk[i][j] )
            {
                ///debug( x,y );
                ///debug(i,j);
                flag=1;
                return ;
            }
        }
        ///if( i==a && j ==b ) chk[a][b]=-100000;
    }
}

int main()
{
    ///READ("in.txt");
    ///WRITE("out.txt");
    flag=0;
    CLR(chk);
    cin >> n  >> m ;
    for( int i=0 ; i < n ;i++ )
    {
        scanf("%s",g_input[i]);
    }
    for( int i=0 ; i< n ; i++ )
    {
        for( int j=0 ;j < m ; j++ )
        {
        if( chk[i][j]==0)
        {
            bfs(i,j);
        }
        if( flag )break;
        }
        if( flag )break;
    }
    if( flag )printf("Yes\n");
    else printf("No\n");
    return 0;
}
