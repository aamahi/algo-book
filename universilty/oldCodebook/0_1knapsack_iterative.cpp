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

int dp[100][1000];


int main()
{
    ///READ("in.txt");
    ///WRITE("out.txt");
    int w[101],cost[101];
    int n;
    int k;
    cin >> n;
    for( int i=1 ; i<=n ; i++ )
    {
        cin >> w[i] >> cost[i];
    }
    cin >> k;
    SET(dp);
    dp[0][0]=0;
    int mx=0;
    for( int i=1; i <=n ; i++ )
    {
        for( int s=0 ; s<=k ; s++ )
        {
            if( dp[i-1][s]!=-1 )
            {
                dp[i][s+w[i]]=dp[i-1][s]+cost[i];
                if( s+w[i]<=k )mx=max(mx,dp[i][s+w[i]]);
                dp[i][s]=dp[i-1][s];
                mx=max(mx,dp[i][s]);
            }
        }
    }
    cout << mx;NL;
    return 0;
}
