#include <bits/stdc++.h>
using namespace std;


int main()
{
    int ara[10000];
    int numberOfInput;
    cin >> numberOfInput;
    for( int i=0,j ; i<numberOfInput  ; i++)
    {
        cin >> ara[i];
        for( j=0 ; j<i ; j++ )
        {
            if(ara[j]==ara[i])break;
        }
        if(i==j)printf("%d ",ara[i]);
    }
}
