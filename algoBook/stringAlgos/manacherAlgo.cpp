#include <bits/stdc++.h>
using namespace std;

int main()
{
    int tmp;
    cin >> tmp;
    while (tmp--)
    {
        string str;
        cin >> str;

        string calc(2 * str.size() + 1, '.');
        for (int i = 0; i < str.size(); i++)
        {
            calc[2 * i + 1] = str[i];
        }

        int n = calc.size();
        vector<int> man(n);

        int i = 0;
        int j;
        int L = -1, R = -1;
        int mx = 0;
        while (i < n)
        {
            if (i > L && i <= R && i + man[2 * L - i] < R)
            {
                man[i] = man[2 * L - i];
            }
            else
            {
                if (i > L && i <= R)
                {
                    j = R - i;
                }
                else
                    j = 1;
                L = i;
                while (i - j >= 0 && i + j < n && calc[i - j] == calc[i + j])
                {
                    man[i] = j;
                    R = i + j;
                    j++;
                }
            }
            mx = max(mx, man[i]);
            i++;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (man[i] == mx)
            {
                cnt++;
            }
        }
        cout << mx << " " << cnt << endl;
    }
}