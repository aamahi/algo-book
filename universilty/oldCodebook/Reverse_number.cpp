#include<stdio.h>

int main()
{
    return 0;
}

long long int rev_num(long long int num)
{
    long long int s=0;
    while(num!=0)
            {
                s=s*10+num%10;
                num/=10;
            }
    return s;
}
