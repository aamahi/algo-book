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

struct node
{
    node *left;
    node *right;
    int freq;
    char ch;
};
int main()
{
    int ara[200]={0};
    char St[10000];
    gets(St);
    printf("%s\n",St);
    int len=strlen(St);
    for( int i=0 ; i<len ; i++ )
    {
        ara[St[i]]++;
    }
    fclose(fp);
    node *nde;
    nde=(node *)malloc(30*sizeof(node));
    nde->ch=' ';
    nde->freq=ara[32];
    nde->left=NULL;
    nde->right=NULL;
    printf("%c->%d\n",32,ara[32]);
    for( int i=97,j=1 ; i<123 ; i++,j++ )
    {
        printf("%c->%d\n",i,ara[i]);
        (nde+j)->ch=i;
        (nde+j)->freq=ara[i];
        (nde+j)->left=NULL;
        (nde+j)->right=NULL;
    }
    int f,f1;
    for( int i=0 ; i<26 ; i++ )
    {
        f=f1=0;
        node *mx,*mx_2;
        mx=(node *)malloc(sizeof(node));
        mx_2=(node *)malloc(sizeof(node));
     ara[i]   mx->freq=1000000;
        mx_2->freq=1000000;
        for( int j=0 ; j<27 ; j++ )
        {
            if( (nde+j)->freq!=-1 &&(nde+j)->freq < mx->freq )
            {
                mx=nde+j;
                f=j;
            }
        }
        for( int j=0 ; j<27 ; j++ )
        {
            if( (nde+j)->freq!=-1 && mx!=nde+j && (nde+j)->freq < mx_2->freq )
            {
                mx_2=nde+j;
                f1=j;
            }
        }
        node *temp;
        temp=(node *)malloc(sizeof(node));
        temp->freq=mx->freq + mx_2->freq;
        temp->ch=0;
        if( mx->freq < mx_2->freq )
        {
            temp->left=mx;
            temp->right=mx_2;
        }
        else
        {
            temp->left=mx_2;
            temp->right=mx;
        }
        node *curr,*curr_2;
        nde+f=temp;
        (nde+f1)->freq=-1;
    }
    node *tree;
    for( int i=0 ; i< 27 ; i++ )
    {
        printf("%c->%d\n",(nde+i)->ch,(nde+i)->freq);
        if( (nde+i)->freq!=-1 )
        {
            cout <<(nde+i)->freq<<endl;
            tree=nde+i;
        }
    }
    return 0;
}


