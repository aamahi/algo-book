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
class node
{
public :
    int val ;
    node *left;
    node *right;
};

class b_tree
{
private :
    node *root;
public :
    b_tree();
    ~b_tree();
    void insert_tree( int nodevalue );
    node *find_tree( int num );
    void bfs( void );
    void dfs( int val );
    int root_val(void);
    void delet_val(int val);
    void destroy_tree( int val);
};

b_tree::b_tree()
{
    root=NULL;
}

b_tree :: ~b_tree()
{

}
int b_tree :: root_val(void)
{
    if( root!=0)
    return root -> val;
    else printf("There is no root\n");
    return 0;
}
void b_tree :: destroy_tree( int val)
{
    node *current;
    if(val==root->val)
    {
        root=NULL;
        return ;
    }
    for( current=root ;       ;        )
    {
        if(current->val<val)
        {
            if( current->left->val == val )
            {
                current->left=NULL;
                return;
            }
            else
            {
                current=current->left;
            }
        }
        else if(current->val>val)
        {
            if( current->right->val == val )
            {
                current->right=NULL;
                return;
            }
            else
            {
                current=current->right;
            }
        }
    }
}
void b_tree :: delet_val(int val)
{
    node *temp,*temp_before;
    temp=find_tree(val);
    if( temp==0 )return ;
    if(temp->left==0 && temp->right==0)
    {
        destroy_tree(val);
        return;
    }
    node *current;
    for( current=root ;       ;        )
    {
        if(current->val<val)
        {
            if( current->left->val == val )
            {
                temp_before=current;
                break;
            }
            else
            {
                current=current->left;
            }
        }
        else if(current->val>val)
        {
            if( current->right->val == val )
            {
                temp_before=current;
                break;
            }
            else
            {
                current=current->right;
            }
        }
    }
    if(temp->left==0)
    {
        if(temp_before->val>val)
        {
            temp_before->right=temp->right;
            return;
        }
        else
        {
            temp_before->left=temp->right;
            return;
        }
    }
    else if(temp->right==0)
    {
        if(temp_before->val>val)
        {
            temp_before->right=temp->left;
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
        now=temp->right;
        for(     ;   now->left    ; now=now->left );
            destroy_tree(now->val);
            temp->val=now->val;
            return ;
    }
}

void b_tree :: insert_tree( int nodevalue )
{
    node *temp,*current;
	temp=(node*)malloc(sizeof(node));
	temp->val=nodevalue;
	temp->left=NULL;
	temp->right=NULL;
	if(!root)
	{
		root=temp;
		return;
	}
	for( current=root ;       ;        )
    {
        if( current->val > nodevalue && current -> right )current=current -> right;
        else if(current->val < nodevalue &&current -> left)current =current -> left;
        else break;
    }
    if( current -> val > nodevalue  )current -> right=temp;
    else if(current -> val < nodevalue )current -> left=temp;
	return;
}
node * b_tree :: find_tree( int num)
{
    node *current;
    for( current=root ;       ;        )
    {
        if(current->val==num )return current;
        if( current->val > num && current -> right )current=current -> right;
        else if(current->val < num &&current -> left)current =current -> left;
        else break;
    }
    return NULL ;
}
void b_tree :: bfs( void )
{
    node *temp;
    queue < int > q;

    q.push(root->val);

    printf("%d ",root->val);
    while( !q.empty())
    {
        int value=q.front();
        q.pop();
        temp=find_tree(value);
        if(temp->left)
        {
            printf("%d ",temp->left->val);
            q.push(temp->left->val);
        }
        if(temp->right)
        {
            printf("%d ",temp->right->val);
            q.push(temp->right->val);
        }
    }
}
void b_tree :: dfs( int val )
{
    node *temp;
    temp=find_tree(val);
    if(temp)printf("%d ",val);
    else return ;
    if(temp->left)dfs(temp->left->val);
    if(temp->right)dfs(temp->right->val);
    else return ;
}

int main()
{
    b_tree tuhin;
    int num,value;
    cin >> num;
    for (int i=0 ; i<num ; i++ )
    {
        cin >> value;
        tuhin.insert_tree(value);
    }
    tuhin.bfs();
    printf("\n");
    tuhin.dfs(tuhin.root_val());
    printf("\n");
    tuhin.bfs();
    cin >>  num;
    node *current;
    for (int i=0 ; i<num ; i++ )
    {
        cin >> value;
        current=tuhin.find_tree(value);
        if(current)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
