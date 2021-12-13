#include <bits/stdc++.h>
using namespace std;

#define for0(i, n) for (i = 0; i < n; i++)
#define for1(i, n) for (i = 1; i <= n; i++)

#define all(x) x.begin(), x.end()
#define mem(x, y) memset(x, y, sizeof(x))

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define pi 3.14159265358979
#define OK cerr << "ok\n"
#define DB(x) cerr << #x << " = " << x << endl

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef pair<int, int> pii;

inline int setBit(int N, int pos) { return N = N | (1 << pos); }
inline int resetBit(int N, int pos) { return N = N & ~(1 << pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1 << pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


class LineEq
{
public:
    double a,b,c,m;

    LineEq(double x, double y, double z)
    {
        a = x;
        b = y;
        c = z;
        m = a/b;
    }

    bool operator <(const LineEq& l) {
        return a < l.a 
            || (a == l.a && b < l.b)
            || (a == l.a && b == l.b  && c < l.c);  
    }

    bool operator ==(const LineEq& l) {
        return (a == l.a && b == l.b  && c == l.c);  
    }
};

LineEq getLineEquationTwoPoints(pair<double, double> p1, pair<double, double> p2)
{
    /// ax − by = c 
    LL a, b, c, mn, d;
    a = p1.second - p2.second;
    b = p1.first - p2.first;
    d = __gcd(a,b);
    a /= d;
    b /= d;
    c = p1.first * a - b * p1.second;
    LineEq line(a, b, c);
    return line;
}

int main()
{
    vector<pair<double, double>> po;

    int n;
    cin >> n;

    double x, y;

    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        pair<double, double> p;
        p.first = x;
        p.second = y;
        po.push_back(p);
    }

    vector<LineEq> lines;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            lines.push_back(getLineEquationTwoPoints(po[i], po[j]));
            //cout << line.a << " " << line.b << " "<< line.c <<endl;
        }
    }

    sort(lines.begin(), lines.end());

    vector<LineEq> rlines;
    rlines.push_back(lines[0]);
    for (int i = 1; i < lines.size(); i++)
    {
        if (!(lines[i] == lines[ i - 1]))
        {
            rlines.push_back(lines[i]);
        }
    }

    // //cout << lines.size() << endl;
    //cout << rlines.size() << endl;

    for (int i = 0; i < rlines.size(); i++)
    {
        //cout << lines[i].a << " " << lines[i].b << " "<< lines[i].c <<endl;
        //if (rlines[i].b != 0)
        rlines[i].a = rlines[i].a/ rlines[i].b;
        //else rlines[i].a = INFINITY;
    }

    sort(rlines.begin(), rlines.end());

    LL cnt = 0;
    x = rlines[0].a;
    //cout << rlines[0].a <<endl;

    LL tmpc = 0;
    for (int i = 1; i < rlines.size(); i++)
    {
        //cout << rlines[i].a <<endl;
        if(rlines[i].a == x)
        {
            tmpc++;
            cnt += tmpc;
        }
        else
        {
            x = rlines[i].a;
            tmpc = 0;
        }
    }

    LL ans = (LL) ((LL)rlines.size()*(rlines.size()-1))/2;

    cout << ans -  cnt << endl;
}