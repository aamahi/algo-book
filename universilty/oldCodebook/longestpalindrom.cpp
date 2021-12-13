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
char ara[1010];
int len;
int dp[1001][1001];
int longestPalin(int l, int r)
{
    if (l == r)return 1;
    if (l + 1 == r)
    {
        if (ara[l] == ara[r])  return 2;
        else return 1;
    }
    if (dp[l][r] != -1) return dp[l][r];
    if (ara[l] == ara[r])return dp[l][r] = 2 + longestPalin(l + 1, r - 1);
    else return dp[l][r] = max(longestPalin(l, r - 1), longestPalin(l + 1, r));
}
int main()
{
    ///READ("in.txt");
    ///WRITE("out.txt");
    int T;
    cin >> T;
    getchar();
    for( int t=1 ; t <= T ; t++ )
    {
        SET(dp);
        gets(ara);
        len=strlen(ara);
        if( len==0 )
        {
            printf("0");NL;
            continue;
        }
        int mx=0;
        cout << longestPalin(0,len-1) ; NL;
    }

    return 0;
}
