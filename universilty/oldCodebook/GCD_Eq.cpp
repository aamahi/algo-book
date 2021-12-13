#include<cstdio>

int main()
{
    return 0;
}
int GCD(int a, int b)
{
    int Remainder;
    while( b != 0 )
    {
        Remainder = a % b;
        a = b;
        b = Remainder;
    }
    return a;
}
int getGCD(int x, int y)
{
    while(x!=y)
    {
        if(x>y)x=x-y;
        else y=y-x;
    }
    return(x);
}
