#include <bits/stdc++.h>
using namespace std;

///number constant
#define eps 1e-9
#define inf 1e8
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
#define LV printf("8++++++++++++++++++++++++++++8\n")
#define ST getchar()

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

///Bitmask
template <class T> inline T ON(T N,T pos){return N=N | (1<<pos);}
template <class T> inline T OFF(T N,T pos){return N= N & ~(1<<pos);}
template <class T> inline bool check(T N,T pos){return (bool)(N & (1<<pos));}

/// Debugs
template <class T> inline void debug( T x ){ cout << "x = " << x << endl; }
template <class T1, class T2> inline void debug( T1 x, T2 y ){ cout << "x = " << x << ", y = " << y << endl; }
template <class T1, class T2, class T3> inline void debug( T1 x, T2 y, T3 z ){ cout << "x = " << x << ", y = " << y << ", z = " << z << endl; }

///Maths
int BigMod(int B, int P, int M){i64 R=1; while(P>0) {if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}	return R;}
i64 DigSum(i64 n){i64 sum=0;while(n>9){sum=0;while(n){sum+=n%10; n/=10;}n=sum;}return n;}

/// 4 Direction
int dx[]={+1,-1,+0,+0};
int dy[]={+0,+0,+1,-1};

/// 8 Direction
//int dx[]={+0,+0,+1,-1,-1,+1,-1,+1};
//int dy[]={-1,+1,+0,+0,+1,+1,-1,-1};


long long int ara[100001];
struct n_tree
{
    long long int val;
    long long int propt;
} tree[4*100000];

void build_tree( long long int node,long long int i ,long long int j )
{
    if( i==j )
    {
        tree[node].val=ara[i];

        return;
    }
    long long int m=(i+j)/2;
    build_tree(2*node,i,m);
    build_tree(2*node+1,m+1,j);
    tree[node].val=tree[node*2].val+tree[node*2+1].val;
    tree[node].propt=0;
    return;
}

void update_tree(long long int node, long long int st ,long long int ed ,long long int i,long long int j , long long int x )
{
    if( i > ed || j < st )
    {
        return ;
    }
    if( i <= st && ed <= j )
    {
        tree[node].val+=((ed-st+1)*x);
        tree[node].propt+=x;
        return ;
    }
    long long int m=(st+ed)/2;
    update_tree(2*node,st,m,i,j,x);
    update_tree(2*node+1,m+1,ed,i,j,x);
    tree[node].val=tree[2*node].val+tree[2*node+1].val+((ed-st+1)*tree[node].propt);
    return ;
}


long long int query(long long int node, long long int st ,long long int ed ,long long int i,long long int j ,long long int carry )
{
    if( i > ed || j < st )
    {
        return 0;
    }
    if( i <= st && ed <= j )
    {
        return tree[node].val+((ed-st+1)*carry);
    }
    long long int m=(st+ed)/2;
    long long int a=query(2*node,st,m,i,j,carry+tree[node].propt);
    long long int b=query(2*node+1,m+1,ed,i,j,carry+tree[node].propt);
    return a+b;
}

int main()
{
    ///READ("in.txt");
    ///WRITE("out.txt");
    long long int T,Q,x,y,f,val;
    cin >> T;
    long long int n;
    for( long long int t=1 ; t <= T ; t++ )
    {
        scanf("%lld %lld",&n,&Q);
        for( long long int i=1 ; i<=n ; i++ )
        {
            ara[i]=0;
        }
        build_tree(1,1,n);
        for( long long int i=0 ; i<Q ; i++ )
        {
            scanf("%lld",&f);
            if( f==0 )
            {
                scanf("%lld %lld %lld",&x,&y,&val);
                update_tree(1,1,n,x,y,val);
            }
            else if( f==1 )
            {
                scanf("%lld %lld",&x,&y);
                printf("%lld\n",query(1,1,n,x,y,0));
            }
        }
    }

    return 0;
}

