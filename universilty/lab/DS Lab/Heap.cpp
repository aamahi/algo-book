#include<cstdio>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<cmath>
#include<algorithm>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<cstring>
#include<map>
#include<iterator>
using namespace std;
int heap[100],n;
void insert(int val)
{
    heap[++n] = val;
    int temp = n;
    while(temp != 1)
    {
        if(heap[temp/2] < heap[temp]) break;
        swap(heap[temp/2] , heap[temp]);
        temp /= 2;
    }
}
int ExtractMin()
{
    swap(heap[1], heap[n]);
    int ret = heap[n];
    heap[n] = 50000000;
    n--;
    int temp = 1;
    while(heap[temp*2] < heap[temp]  ||  heap[(temp*2)+1] < heap[temp])
    {
        if(heap[temp*2] < heap[(temp*2)+1])
        {
            swap(heap[temp], heap[temp*2]);
            temp = temp*2;
        }
        else
        {
            swap(heap[temp], heap[(temp*2)+1]);
            temp = (temp*2)+1;
        }
    }
    return ret;
}
void PrintHip()
{
    int i;
    for(i = 1; i<=n; i++) printf( "%d ",heap[i]);
    printf("\n");
}
void HeapSort()
{
    while(n > 0)
        printf( "%d ", ExtractMin());
    printf("\n");
}
void DecreaseKey(int node, int key)
{
    heap[node] = key;
    int temp = node;
    while(temp != 1)
    {
        if(heap[temp/2] < heap[temp]) break;
        swap(heap[temp/2] , heap[temp]);
        temp /= 2;
    }
}
void del(int node)
{
    DecreaseKey(node, -500);
    ExtractMin();
}

int main()
{

    return 0;
}

