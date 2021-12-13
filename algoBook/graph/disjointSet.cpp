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

class Node
{
public:
    int val;
    vector<Node *> childs;
};

/// Find
int find(vector<pii> &graphPar, int r)
{
    if (graphPar[r].first == r)
        return r;
    graphPar[r].first = find(graphPar, graphPar[r].first);
    return graphPar[r].first;
}

/// Union
void unionn(unordered_map<int, Node *> &nodeMaper, vector<pii> &graphPar, int x, int y)
{
    Node *xtmp, *ytmp;
    if (graphPar[x].second == graphPar[y].second)
    {
        graphPar[y].first = x;
        ytmp = nodeMaper[y];
        xtmp = nodeMaper[x];
        xtmp->childs.push_back(ytmp);

        graphPar[x].second++;
    }
    else if (graphPar[x].second > graphPar[y].second)
    {
        graphPar[y].first = x;
        ytmp = nodeMaper[y];
        xtmp = nodeMaper[x];
        xtmp->childs.push_back(ytmp);
    }
    else
    {
        graphPar[x].first = y;
        ytmp = nodeMaper[y];
        xtmp = nodeMaper[x];
        ytmp->childs.push_back(xtmp);
    }
}

void dfsPreorder(Node *root)
{
    cout << root->val + 1 << " ";

    for (int i = 0; i < root->childs.size(); i++)
    {
        dfsPreorder(root->childs[i]);
    }
}

int main()
{
    int n;

    sdi(n);

    vector<pii> graphPar(n);
    unordered_map<int, Node *> nodeMaper;

    /// Make Set
    for (int i = 0; i < n; i++)
    {
        graphPar[i].first = i;
        graphPar[i].second = 1;
        Node *tmp = new Node();
        tmp->val = i;
        nodeMaper[i] = tmp;
    }

    int x, y;
    for (int i = 0; i < n - 1; i++)
    {
        sdii(x, y);
        x = find(graphPar, x - 1);
        y = find(graphPar, y - 1);

        unionn(nodeMaper, graphPar, x, y);
    }

    int root = find(graphPar, 0);

    dfsPreorder(nodeMaper[root]);
    cout << endl;
}
