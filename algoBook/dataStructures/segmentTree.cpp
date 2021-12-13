#include <bits/stdc++.h>
using namespace std;

int constructNode(vector<int> &nums, vector<int> &st, int a, int b, int idx)
{
    if (a == b)
    {
        st[idx] = nums[a];
        return st[idx];
    }

    int mid = (a + b) / 2;
    st[idx] = constructNode(nums, st, a, mid, 2 * idx) + constructNode(nums, st, mid + 1, b, 2 * idx + 1);
    return st[idx];
}

vector<int> constructST(vector<int> &nums)
{
    int maxSize = 2 * (int)pow(2, (int)(ceil(log2(nums.size())))) - 1;
    vector<int> st(maxSize + 1, INT_MAX);

    constructNode(nums, st, 0, nums.size() - 1, 1);

    return st;
}

void updateNumNode(vector<int> &nums, vector<int> &st, int p, int q, int i, int x, int idx)
{
    st[idx] += (x - nums[i]);

    if (p == q)
        return;

    int mid = (p + q) / 2;

    if (mid >= i)
    {
        updateNumNode(nums, st, p, mid, i, x, 2 * idx);
    }
    else
    {
        updateNumNode(nums, st, mid + 1, q, i, x, 2 * idx + 1);
    }
}

void updateNum(vector<int> &nums, vector<int> &st, int i, int x)
{
    updateNumNode(nums, st, 0, nums.size() - 1, i, x, 1);
}

int getSumNode(vector<int> &st, int p, int q, int a, int b, int idx)
{
    if (p >= a and q <= b)
    {
        return st[idx];
    }

    if (p > b || q < a)
    {
        return 0;
    }

    int mid = (p + q) / 2;

    return getSumNode(st, p, mid, a, b, 2 * idx) + getSumNode(st, mid + 1, q, a, b, 2 * idx + 1);
}

int getSum(vector<int> &st, int a, int b, int n)
{
    return getSumNode(st, 0, n, a, b, 1);
}

int main()
{
    FILE *fp;
    fp = fopen("input.txt", "r");

    int x, n;
    vector<int> nums;
    fscanf(fp, "%d", &n);

    while (n--)
    {
        fscanf(fp, "%d", &x);
        nums.push_back(x);
    }

    vector<int> st = constructST(nums);

    int q;

    fscanf(fp, "%d", &q);

    int y, z;
    while (fscanf(fp, "%d %d %d", &x, &y, &z) != EOF)
    {
        if (x == 1)
        {
            updateNum(nums, st, y, z);
        }
        else if (x == 2)
        {
            cout << "Sum = " << getSum(st, y, z, nums.size() - 1) << endl;
        }
    }

    return 0;
}