#include <bits/stdc++.h>
using namespace std;

int patternSearch(string src, string pattern)
{
    vector<int> prefixArray(pattern.size(), 0);

    int cnt = 0;
    int i = 1;

    while( i < pattern.size())
    {
        if(pattern[i] == pattern[cnt])
        {
            cnt++;
            prefixArray[i] = cnt;
            i++;
        }
        else
        {
            if(cnt != 0)
                cnt = prefixArray[cnt-1];
            else i++;
        }
    }

    // Print prefixArray
    // for( int i=0 ; i<pattern.size() ; i++)
    //     cout << prefixArray[i] << " ";
    // cout << endl;

    int j;
    i=j=0;

    int rCnt = 0;
    vector<int> ans;
    while( i < src.size() )
    {
        if(src[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if(j != 0) 
                j = prefixArray[j-1];
            else
                i++; 
        }
        
        if(j==pattern.size())
        {
            return i-pattern.size()+1;
            rCnt++;
            ans.push_back(i-pattern.size()+1);
            j = prefixArray[j-1];
        }

    }

    return rCnt;
}

int patternSearchPrefixArray(string src, string pattern)
{
    string clacPattern = pattern + "$" + src;
    vector<int> prefixArray(clacPattern.size(), 0);

    int cnt = 0;
    int i = 1;

    while( i < clacPattern.size())
    {
        if(clacPattern[i] == clacPattern[cnt])
        {
            cnt++;
            prefixArray[i] = cnt;
            i++;
        }
        else
        {
            if(cnt != 0)
                cnt = prefixArray[cnt-1];
            else i++;
        }
    }

    //Print prefixArray
    // for( int i=pattern.size() + 1 ; i<clacPattern.size() ; i++)
    //     cout << prefixArray[i] << " ";
    // cout << endl;

    vector<int> ans;
    for( int i=pattern.size() + 1 ; i<clacPattern.size() ; i++)
    {
        if(prefixArray[i] == pattern.size())
            ans.push_back(i-pattern.size()-pattern.size()+1);
    }

    if(ans.size() != 0)
    {
        printf("%d\n", ans.size());

        for( int i=0 ; i<ans.size() ; i++ )
        {
            printf("%d ", ans[i]);
        }

        printf("\n\n");
    }
    else
    {
        printf("Not Found\n\n");
    }

    return ans.size();
}

int main()
{
    int n;
    cin >> n;
    string src;
    string pattern;

    while (n--)
    {
        cin >> src >> pattern;

        patternSearchPrefixArray(src, pattern);
    }

    return 0;
}