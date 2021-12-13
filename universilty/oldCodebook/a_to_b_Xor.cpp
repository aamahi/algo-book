#include<iostream>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<utility>
#include<cstdlib>
#include<cstring>
#include<string>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cctype>
#include<cmath>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#define pi 2*acos(0.0)
using namespace std;
int f(int a)
{
     int res[] = {a,1,a+1,0};
     return res[a%4];
}

int  getXor(int a, int b)
{
     return f(b)^f(a-1);
}
int main()
{

    return 0;
}
