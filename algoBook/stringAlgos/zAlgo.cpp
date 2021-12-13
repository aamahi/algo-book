#include <bits/stdc++.h>
using namespace std;

void zAlgo(string src, string pattern)
{
    string calc = pattern + "$" + src;

    vector<int> zArr(calc.size(), 0);

    /* First part calculation */
    int idx = 1;

    while (idx < zArr.size())
    {
        if(calc[idx] != calc[idx-1])
        {
            break;
        }
        idx++;
    }
    
    int samePrefix = idx-1;
    for( int i=1 ; i < zArr.size() && samePrefix ; i++)
    {
        zArr[i] = samePrefix;
        samePrefix--;
    }

    /* Main calculation */
    int L,R;
    L=R=0;
    int cnt;
    while(idx < zArr.size())
    {
        if(R<idx)
        {
            L=R=idx;
            while(R < zArr.size() && calc[R] == calc[R-L])
                R++;
            zArr[idx] = R-L;
            R--;
        }
        else
        {
            if(R > idx + zArr[idx - L] - 1)
            {
                zArr[idx] = zArr[idx-L];
            }
            else
            {
                L = idx;
                cnt = R-L;

                while(R < zArr.size() && calc[R] == calc[R-L])
                    R++;
                zArr[idx] = R-L;
                R--;
            }
        }
        idx++;
    }

    // Print prefixArray
    vector<int> ret;
    for( int i=0 ; i<zArr.size() ; i++)
    {
        if(zArr[i] == pattern.size())
        {
            ret.push_back(i-pattern.size());
        }
    }

    if(ret.size() != 0)
    {
        printf("%d\n", ret.size());

        for( int i=0 ; i<ret.size() ; i++ )
        {
            printf("%d ", ret[i]);
        }

        printf("\n\n");
    }
    else
    {
        printf("Not Found\n\n");
    }
}

int main()
{
    string src, pattern;
    int n;
    cin >> n; 

    while ( n )
    {
        cin >> src >> pattern;
        zAlgo(src, pattern);
        n--;
    }
}