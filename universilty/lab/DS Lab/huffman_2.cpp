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
    node *next;
};

node *head;
void appendNode(int freq,int chr)
{
    node *temp,*current;
	temp=(struct node*)malloc(sizeof(struct node));
	temp->ch=chr;
	temp->freq=freq;
	temp->next=NULL;
	temp->left=NULL;
	temp->right=NULL;
	if(!head)
	{
		head=temp;
		return;
	}
	for(current=head;current->next;current=current->next);
	current->next=temp;
	return;
}
void printlist()
{
    node *current;
	for(current=head;current;current=current->next)
	{
	    printf ("%c = %d\n",current->ch,current->freq);
	}
}

char huff[130][1000];

void preOrder( node *temp ,char ara[] ,int n )
{
    //cout << temp->ch << temp->freq << endl;
    if( temp->ch!=0 )
    {
        cout << temp->ch << "  ";
        for( int i=0 ; i<n  ; i++ )
        {
            cout << ara[i];
            huff[temp->ch][i]=ara[i];
        }
        cout << endl;
        ara[n-1]=0;
        return;
    }
    if( temp->left )
    {
        ara[n]='0';
        preOrder( temp->left , ara , n+1 );
    }
    if( temp->right )
    {
        ara[n]='1';
        preOrder( temp->right , ara , n+1 );
    }
}
int huff_code[10000];
int enCode(char ara[])
{
    int x,len_2,j=0;
    int len=strlen(ara);
    for( int i=0 ; i < len ; i++ )
    {
        x=ara[i];
        printf("%s",huff[x]);
        //cout << endl;
        len_2=strlen(huff[x]);
        for( int k=0  ; k<len_2  ; j++,k++ )
        {
            huff_code[j]=huff[x][k]-48;
        }
    }
    cout << endl;
    /*for( int i=0 ; i< j ; i++ )
        cout << huff_code[i];*/
    return j;
}
void decode( int n )
{
    int i=0,k,j;
    int len;
    while( i<n )
    {
        k=i;
        len=strlen(huff[32]);
        for(  j=0 ; j< len ; j++,k++ )
        {
            //cout << huff[32][j]-48 << huff_code[k];
            if( huff[32][j]-48 != huff_code[k] )
            {
                break;
            }
        }
        //cout << j << len << endl;
        if( j==len )
        {
            cout << " ";
            i+=len;
            continue;
        }
        for( int x=97 ; x< 123 ; x++ )
        {
            k=i;
            len=strlen(huff[x]);
            for( int j=0 ; j< len ; j++,k++ )
            {
                cout << huff[32][j]-48 << huff_code[k];
                if( huff[x][j]-48!=huff_code[k] )
                {
                    break;
                }
            }
            cout << j << len << endl;
            if( j==len )
            {
                printf("%c",x);
                i+=len;
            }
        }
    }
    cout << endl;
}

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
    int min, flag;
    for( int i=0 ; i< 27 ; i++ )
    {
        min=100000000;
        if( ara[32]!=-1)
        {
            min=ara[32];
            flag=32;
        }
        for(int j=97 ; j<123 ; j++ )
        {
            if( ara[j]!=-1 && min>ara[j] )
            {
                min=ara[j];
                flag=j;
            }
        }
        appendNode(min,flag);
        ara[flag]=-1;
    }
    node *root;
    int t=1;
    while( head )
    {
        node *temp,*temp_2;
        temp=head;
        temp_2=head->next;
        head=head->next->next;
        temp->next=NULL;
        temp_2->next=NULL;
        node *curr,*now;
        curr=(struct node *)malloc(sizeof(struct node));
        t++;
        curr->left=temp;
        curr->right=temp_2;
        curr->freq=temp->freq+temp_2->freq;
        curr->ch=0;
        curr->next=NULL;
        root=curr;
        node *par;
        if( head && head->freq > curr->freq )
        {
            curr->next=head;
            head=curr;
        }
        else if( head )
        {
            for( now = head ; now ; now =now->next )
            {
                if( now->freq > curr->freq )
                {
                    curr->next=now;
                    par->next=curr;
                    break;
                }
                par=now;
            }
            if( now==NULL )
            {
                for( now = head ; now->next ; now =now->next );
                now->next=curr;
            }
        }
    }
    char a[1000];
    preOrder(root,a,0);
    int y=enCode(St);
    decode(y);
    return 0;
}
