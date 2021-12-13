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
    int val;
    node *left;
    node *right;
};

node *root;
void insert_tree( int nodevalue )
{
    node *temp,*current;
	temp=(node*)malloc(sizeof(node));
	temp -> val=nodevalue;
	temp->left=NULL;
	temp->right=NULL;
	if(!root)
	{
		root=temp;
		return;
	}
	for( current=root ;       ;        )
    {
        if( current->val < nodevalue && current->right )current=current->right;
        else if(current->val > nodevalue && current->left )current =current->left;
        else break;
    }
    if( current->val > nodevalue  )current->right= temp ;
    else if(current->val < nodevalue )current->left= temp ;
	return;
}

node *  find_tree( int num)
{
    node *current;
    for( current=root ;       ;        )
    {
        if(current->val==num )return current;
        if( current->val < num && current ->right )current=current ->right;
        else if(current->val > num &&current ->left )current =current ->left;
        else break;
    }
    return NULL ;
}

void delet_val(int value)
{
    node *temp,*temp_before;
    node *current;
    if( root==0 )
    {
        printf("Noting to delete\n");
        return ;
    }
    temp_before=NULL;
    for( current=root ;       ;        )
    {
        if(current->val==value )break;
        if( current->val < value && current ->right )current=current ->right;
        else if(current->val > value &&current ->left )current =current ->left;
        else break;
        temp_before=current;
    }
    temp=current;
    if( temp==temp_before )
    {
        printf("Noting to delete\n");
        return ;
    }
    if(temp->left==0 && temp->right==0 && temp_before )
    {
        if( temp_before->val < value )temp_before->right=NULL;
        else temp_before->left=NULL;
        return;
    }
    if(temp->left==0 && temp->right==0 && temp==root )
    {
        root=NULL;
        return;
    }
    if(temp->left==0 && temp_before )
    {
        if( temp_before-> val < value )
        {
            temp_before -> right=temp -> right;
            return;
        }
        else
        {
            temp_before -> left=temp->right;
            return;
        }
    }
    if(temp->left==0 && temp==root )
    {
        root=root->right;
    }
    if(temp->right==0 && temp_before )
    {
        if( temp_before-> val < value )
        {
            temp_before-> right=temp->left;
            return;
        }
        else
        {
            temp_before->left=temp->left;
            return;
        }
    }
    else
    {
        node *now;
        now= temp -> right ;
        for(     ;   now->left    ; now=now->left );
            int x=now->val;
            delet_val(now->val);
            temp->val=x;
            return ;
    }
}
int main()
{

}
