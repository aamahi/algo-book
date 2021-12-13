#include <bits/stdc++.h>
using namespace std ;


struct node
{
    int  *keys;
    node **childs;
    node *parent;
    bool leaf;
    int  n;
}*root;
node * initNode();
void insert( int key );
node* searchNode(node *curr , int key);
void print( node *curr );
void printBFS( node *curr );
void splitNode(node *curr);
void splitinnerNode(node *curr);
void margeNode( node *curr );

node * initNode()
{
    int i;
    node *np = new node;
    np->keys = new int[4];
    np->childs = new node *[5];
    np->parent = NULL;
    np->leaf = true;
    np->n = 0;
    for (i = 0; i < 4; i++)
    {
        np->childs[i] = NULL;
    }
    return np;
}

void insert( int key )
{
    if( root==NULL )
    {
        root=initNode();
        root->keys[0]=key;
        root->n++;
        return;
    }
    node *curr = searchNode(root,key);
    int i;
    for( i=0; i < curr->n ; i++ )
    {
        if( curr->keys[i] > key )
        {
            for( int j=curr->n-1 ; j>=i  ; j-- )
            {
                curr->keys[j+1]=curr->keys[j];
            }
            curr->keys[i]=key;
            break;
        }
    }
    if( i == curr->n )
    {
        curr->keys[curr->n]=key;
    }
    curr->n++;

    if( curr->n > 3 )
    {
        splitNode(curr);
    }

}

node* searchNode(node *curr , int key)
{
    if(curr->leaf) return curr;
    for(int i=0; i < curr->n ; i++ )
    {
        if( curr->keys[i] > key )
        {
            return searchNode(curr->childs[i],key);
        }
    }
    return searchNode(curr->childs[curr->n],key);
}

void splitNode(node *curr)
{
    node * newNode= initNode();
    for( int i=(curr->n/2) , j=0 ; i < curr->n ; i++ , j++ )
    {
        newNode->keys[j]=curr->keys[i];
        newNode->n++;
    }
    curr->n = curr->n/2 ;
    if( curr->parent == NULL )
    {
        node * newRoot=initNode();
        newRoot->keys[0]=newNode->keys[0];
        newRoot->n++;
        newRoot->leaf=false;
        newRoot->childs[0]=curr;
        newRoot->childs[1]=newNode;
        newNode->parent=newRoot;
        curr->parent=newRoot;
        root=newRoot;
    }
    else
    {
        int key = newNode->keys[0];
        curr=curr->parent;
        int i;
        curr->childs[curr->n+1]=curr->childs[curr->n];
        for( i=0; i < curr->n ; i++ )
        {
            if( curr->keys[i] > key )
            {
                for( int j=curr->n-1 ; j>=i  ; j-- )
                {
                    curr->keys[j+1]=curr->keys[j];
                    curr->childs[j+1]=curr->childs[j];
                }
                curr->keys[i]=key;
                curr->childs[i]=curr->childs[i+1];
                curr->childs[i+1]=newNode;
                break;
            }
        }
        if( i == curr->n )
        {
            curr->keys[curr->n]=key;
            curr->childs[curr->n]=curr->childs[curr->n+1];
            curr->childs[curr->n+1]=newNode;
        }
        curr->n++;
        newNode->parent=curr;
        if(curr->n > 3 )
            splitinnerNode(curr);
    }
}


void splitinnerNode(node *curr)
{
    node * newNode= initNode();
    newNode->leaf=false;
    int i,j;
    for(  i=(curr->n/2)+1 , j=0 ; i < curr->n ; i++ , j++ )
    {
        newNode->keys[j]=curr->keys[i];
        newNode->childs[j]=curr->childs[i];
        newNode->childs[j]->parent=newNode;
        newNode->n++;
    }
    newNode->childs[j]=curr->childs[i];
    newNode->childs[j]->parent=newNode;
    curr->n = curr->n/2 ;

    int upperkey = curr->keys[curr->n/2+1];
    if( curr->parent == NULL )
    {
        node * newRoot=initNode();
        newRoot->keys[0]=upperkey;
        newRoot->n++;
        newRoot->leaf=false;
        newRoot->childs[0]=curr;
        newRoot->childs[1]=newNode;
        newNode->parent=newRoot;
        curr->parent=newRoot;
        root=newRoot;
    }
    else
    {
        ///int key = newNode->keys[0];
        curr=curr->parent;
        int i;
        curr->childs[curr->n+1]=curr->childs[curr->n];
        for( i=0; i < curr->n ; i++ )
        {
            if( curr->keys[i] > upperkey )
            {
                for( int j=curr->n-1 ; j>=i  ; j-- )
                {
                    curr->keys[j+1]=curr->keys[j];
                    curr->childs[j+1]=curr->childs[j];
                }
                curr->keys[i]=upperkey;
                curr->childs[i]=curr->childs[i+1];
                curr->childs[i+1]=newNode;
                break;
            }
        }
        if( i == curr->n )
        {
            curr->keys[curr->n]=upperkey;
            curr->childs[curr->n]=curr->childs[curr->n+1];
            curr->childs[curr->n+1]=newNode;
        }
        curr->n++;
        newNode->parent=curr;
        if(curr->n > 3 )
            splitinnerNode(curr);
    }
}



void print( node *curr )
{
    if(curr==NULL) return ;
    for(int i=0 ; i <curr->n ; i++ )
    {
        printf("%d ",curr->keys[i]);
    }
    cout << endl;
    for(int i=0; i <=curr->n ; i++ )
    {
        print(curr->childs[i]);
    }
}

void printBFS( node *curr )
{
    if(curr==NULL)
    {
        cout << "The tree is empty ." << endl;
        return;
    }
    queue <node *> q;
    map <node *,int> m ;
    m[curr]=0;
    q.push(curr);
    int bf=0;
    while( !q.empty() )
    {
        node * tmp=q.front();
        if( bf != m[tmp] )
        {
            cout << endl;
            bf=m[tmp];
        }

        q.pop();
        for(int i=0 ; i <tmp->n ; i++ )
        {
            printf("%d ",tmp->keys[i]);
        }
        /*if(tmp!=root)
        cout << "|" << tmp->parent->keys[0]<< "|";*/
        cout << "     " ;

        if( tmp->leaf )continue;
        for(int i=0 ; i <= tmp->n ; i++ )
        {
            q.push(tmp->childs[i]);
            m[tmp->childs[i]]=m[tmp]+1;
        }
    }
}

void deleteKey(int key)
{
    node *curr = searchNode(root,key);
    ///cout << "Debug  =" <<curr->keys[0] << endl;
    if(curr==root)
    {
        int i;
        for( i=0 ; i <curr->n ; i++ )
        {
            if( curr->keys[i] == key )
            {
                for( int j=i+1 ; j <curr->n ; j++ )
                {
                    curr->keys[j-1]=curr->keys[j];
                }
                break;
            }
        }
        curr->n--;
        if(curr->n==0)
        {
            root=NULL;
        }
        return;
    }
    if( curr->n > 2 )
    {
        int i;
        for( i=0 ; i <curr->n ; i++ )
        {
            if( curr->keys[i] == key )
            {
                for( int j=i+1 ; j <curr->n ; j++ )
                {
                    curr->keys[j-1]=curr->keys[j];
                }
                break;
            }
        }
        if(i==curr->n)return;
        curr->n--;
        if( i==0 )
        {
            int replaceKey=curr->keys[0];
            node *tmp=curr;
            node *tmp2;
            while( 1 )
            {
                if(tmp->parent==NULL)break;
                tmp2=tmp;
                tmp=tmp->parent;
                for( i=0 ; i <tmp->n ; i++ )
                {
                    if( tmp->childs[i] == tmp2 )
                    {
                        break;
                    }
                }
                if( i==0 )continue;
                tmp->keys[i-1]=replaceKey;
                break;
            }
        }
    }
    else if( curr->n == 2 )
    {
        int i;
        for( i=0 ; i <curr->n ; i++ )
        {
            if( curr->keys[i] == key )
            {
                for( int j=i+1 ; j <curr->n ; j++ )
                {
                    curr->keys[j-1]=curr->keys[j];
                }
                break;
            }
        }
        if(i==curr->n)return;
        curr->n--;
        ///cout << "Debug  =" <<curr->keys[0] << endl;
        if( curr == root )return;
        ///Borrow left
        int flag=1;
        node *tmp=curr;
        node *tmp2;
        while( 1 )
        {
            if(tmp->parent==NULL)
            {
                flag=0;
                break;
            }
            tmp2=tmp;
            tmp=tmp->parent;
            for( i=0 ; i <tmp->n ; i++ )
            {
                if( tmp->childs[i] == tmp2 )
                {
                    break;
                }
            }
            ///cout << i << endl;
            if( i==0 )continue;
            break;
        }
        ///cout << "Debug = " << tmp->keys[0] << endl;
        ///cout << "Debug = " << flag << endl;
        if( flag )
        {
            tmp2=tmp;
            tmp=tmp->childs[i-1];
            ///cout << "Debug  =" <<tmp2->keys[0] << endl;
            ///cout << "Debug  =" <<tmp->keys[0] << endl;
            while( 1 )
            {
                if(tmp->leaf)break;
                tmp=tmp->childs[tmp->n];
            }
        }
        if( flag && tmp->n > 2 )
        {
            key = tmp->keys[tmp->n-1];
            tmp->n--;
            for( int j=0 ; j < curr->n ; j++ )
            {
                curr->keys[j+1]=curr->keys[j];
            }
            curr->n++;
            curr->keys[0]=key;
            tmp2->keys[i-1]=key;
            return;
        }
        ///Merge Left
        else if( flag && tmp->n == 2 )
        {
            for( int j=0 , k=tmp->n ; j < curr->n ; j++ , k++ )
            {
                tmp->keys[k]=curr->keys[j];
                tmp->n++;
            }
            node *curr2 = curr->parent;
            int j;
            for( j=0 ; j < curr2->n ; j++ )
            {
                if(curr2->childs[j]==curr)
                {
                    break;
                }
            }
            if(j==curr2->n)
            {
                curr2->n--;
            }
            else
            {
                ///printf("CK  =  %d\n",i);
                for( int k=j-1 ; k<curr2->n-1 ; k++ )
                {
                    curr2->keys[k]=curr2->keys[k+1];
                    curr2->childs[k+1]=curr2->childs[k+2];
                }
                ///curr2->childs[curr2->n-1]=curr2->childs[curr2->n];
                curr2->n--;
                if( j==0 )
                {
                    tmp2->keys[i-1]=curr2->childs[0]->keys[0];
                }
            }
            if( curr2->n == 0 )
            {
                if(curr2==root)
                {
                    root=root->childs[0];
                    root->parent=NULL;
                    return;
                }
                flag=1;
                tmp=curr2;
                while( 1 )
                {
                    if(tmp->parent==NULL)
                    {
                        flag=0;
                        break;
                    }
                    tmp2=tmp;
                    tmp=tmp->parent;
                    for( i=0 ; i <tmp->n ; i++ )
                    {
                        if( tmp->childs[i] == tmp2 )
                        {
                            break;
                        }
                    }
                    if( i==0 )continue;
                    break;
                }
                if(flag)
                {
                    tmp2=tmp;
                    tmp=tmp->childs[i-1];
                    while( 1 )
                    {
                        if(tmp->leaf)break;
                        tmp=tmp->childs[tmp->n];
                    }
                    ///From Here
                    /*if(tmp->parent->n >= 2)
                    {
                        tmp->parent->n--;
                        curr2->childs[1]=curr2->childs[0];
                        curr2->childs[0]=tmp;///Change
                        tmp->parent=curr2;
                        tmp2->keys[i-1]=curr2->childs[0]->keys[0];
                        curr2->keys[0]=curr2->childs[1]->keys[0];
                        curr2->n++;
                    }
                    else
                    {
                        tmp2->n--;
                        tmp->parent->childs[tmp->parent->n+1]=curr2->childs[0];
                        curr2->childs[0]->parent=tmp->parent;///Change
                        tmp->parent->keys[tmp->parent->n]=curr2->childs[0]->keys[0];
                        tmp->parent->n++;
                        if(root->n==0)
                        {
                            root=root->childs[0];
                            root->parent=NULL;
                        }
                    }*/
                    tmp->parent->childs[tmp->parent->n+1]=curr2->childs[0];
                    curr2->childs[0]->parent=tmp->parent;///Change
                    tmp->parent->keys[tmp->parent->n]=curr2->childs[0]->keys[0];
                    tmp->parent->n++;
                    tmp2->n--;
                    if(root->n==0)
                    {
                        root=root->childs[0];
                        root->parent=NULL;
                    }
                    if(tmp->parent->n >= 4)
                        splitinnerNode(tmp->parent);
                }
                else
                {
                    curr=curr2->childs[0];
                    tmp=curr2->parent->childs[1];
                    /*if(tmp->n >= 2)
                    {
                        ///cout << "Here" << endl;
                        curr2->childs[1]=tmp->childs[0];
                        tmp->childs[0]->parent=curr2;///Change
                        curr2->keys[0]=curr2->childs[1]->keys[0];
                        curr2->n++;
                        for( int i=1  ; i <= tmp->n ; i++ )
                        {
                            tmp->childs[i-1]=tmp->childs[i];
                        }
                        for( int   i=0  ; i < tmp->n ; i++ )
                        {
                            tmp->keys[i]=tmp->childs[i+1]->keys[0];
                        }
                        tmp->n--;
                        curr2->parent->keys[0]=tmp->childs[0]->keys[0];
                    }
                    else
                    {
                        ///cout << "Here" << endl;
                        tmp->childs[tmp->n+1]=tmp->childs[tmp->n];
                        for( int i=tmp->n-1 ; i>=0 ; i-- )
                        {
                            tmp->childs[i+1]=tmp->childs[i];
                            tmp->keys[i+1]=tmp->keys[i];
                        }
                        tmp->childs[0]=curr2->childs[0];
                        curr2->childs[0]->parent=tmp;///Change
                        tmp->keys[0]=tmp->childs[1]->keys[0];
                        tmp->n++;
                        root=root->childs[1];
                        root->parent=NULL;

                    }*/
                    tmp->childs[tmp->n+1]=tmp->childs[tmp->n];
                    for( int i=tmp->n-1 ; i>=0 ; i-- )
                    {
                        tmp->childs[i+1]=tmp->childs[i];
                        tmp->keys[i+1]=tmp->keys[i];
                    }
                    tmp->childs[0]=curr2->childs[0];
                    curr2->childs[0]->parent=tmp;///Change
                    tmp->keys[0]=tmp->childs[1]->keys[0];
                    tmp->n++;
                    root=root->childs[1];
                    root->parent=NULL;
                    if(tmp->n >= 4 )
                    {
                        splitinnerNode(tmp->parent);
                    }
                }
            }
        }
        else if( flag == 0 )
        {
            ///Borrow Right
            tmp=curr->parent->childs[1];
            if( tmp->n > 2 )
            {
                ///cout << "OK1" <<endl;
                key = tmp->keys[0];
                for( int j=0 ; j < tmp->n-1  ; j++ )
                {
                    tmp->keys[j]=tmp->keys[j+1];
                }
                tmp->n--;
                curr->keys[curr->n]=key;
                curr->n++;
                curr->parent->keys[0]=tmp->keys[0];
            }
            else
            {
                ///cout << "OK2" <<endl;
                key =curr->keys[0];
                for( int j=tmp->n-1 ; j >= 0   ; j-- )
                {
                    tmp->keys[j+1]=tmp->keys[j];
                }
                tmp->keys[0]=key;
                tmp->n++;
                curr=curr->parent;
                for(int j=0 ; j < curr->n ; j++ )
                {
                    curr->childs[j]=curr->childs[j+1];
                }
                for(int j=0 ; j < curr->n-1 ; j++ )
                {
                    curr->keys[j]=curr->keys[j+1];
                }
                curr->n--;
                ///Marge Right
                if(curr->n == 0)
                {
                    if( curr==root )
                    {
                        root=root->childs[0];
                        root->parent=NULL;
                        return;
                    }
                    node *curr2=curr->parent;
                    tmp=curr2->childs[1];
                    if(tmp->n >= 2)
                    {
                        curr->childs[1]=tmp->childs[0];
                        tmp->childs[0]->parent=curr;
                        curr->keys[0]=curr->childs[1]->keys[0];
                        curr->n++;
                        for( i=1 ; i<tmp->n+1 ; i++ )
                        {
                            tmp->childs[i-1]=tmp->childs[i];
                        }
                        tmp->n--;
                        for( i=0 ; i<tmp->n ; i++ )
                        {
                            tmp->keys[i]=tmp->childs[i+1]->keys[0];
                        }
                        curr2->keys[0]=tmp->childs[0]->keys[0];
                    }
                    else
                    {
                        cout << "Eue" << endl;
                        tmp->childs[2]=tmp->childs[1];
                        tmp->childs[1]=tmp->childs[0];
                        tmp->keys[0]=tmp->childs[1]->keys[0];
                        tmp->keys[1]=tmp->childs[2]->keys[0];
                        tmp->childs[0]=curr->childs[0];
                        tmp->childs[0]->parent=tmp;
                        tmp->n++;
                        curr2->n--;
                        if(curr2->n==0)
                        {
                            root=root->childs[1];
                            root->parent=NULL;
                        }
                        ///else
                    }
                }
            }

        }
    }
}

int main()
{
    insert(10);
    insert(20);
    insert(30);
    insert(40);
    insert(50);
    insert(60);
    insert(70);
    insert(80);
    insert(90);
    insert(100);
    insert(110);
    printBFS(root);
    cout << endl;
    ///insert(10);
    /*insert(20);
    insert(13);
    insert(25);
    insert(30);
    insert(21);
    insert(22);
    insert(28);
    insert(27);
    insert(23);
    insert(32);
    insert(35);
    printBFS(root);
    cout << endl;
    /*deleteKey(22);
    printBFS(root);
    cout << endl;
    deleteKey(10);
    printBFS(root);
    cout << endl;
    /*deleteKey(10);
    printBFS(root);
    cout << endl;
    deleteKey(22);
    printBFS(root);
    cout << endl;
    deleteKey(21);
    printBFS(root);
    cout << endl;
    deleteKey(28);
    printBFS(root);
    cout << endl;
    deleteKey(32);
    printBFS(root);
    cout << endl;
    deleteKey(25);
    printBFS(root);
    cout << endl;
    deleteKey(30);
    printBFS(root);
    cout << endl;
    /*deleteKey(23);
    printBFS(root);
    cout << endl;
    deleteKey(21);
    printBFS(root);
    cout << endl;
    deleteKey(20);
    printBFS(root);
    cout << endl;
    deleteKey(27);
    printBFS(root);
    cout << endl;
    deleteKey(22);
    printBFS(root);
    cout << endl;
    deleteKey(13);
    printBFS(root);
    cout << endl;
    /*insert(29);
    deleteKey(10);
    printBFS(root);
    cout << endl;
    deleteKey(28);
    printBFS(root);
    cout << endl;
    /*deleteKey(22);
    printBFS(root);
    cout << endl;
    /*deleteKey(17);
    printBFS(root);
    cout << endl;
    deleteKey(23);
    printBFS(root);
    cout << endl;
    /*insert(22);
    /*insert(50);
    insert(40);
    insert(23);
    insert(22);
    insert(15);
    insert(18);
    insert(9);
    insert(8);
    insert(7);
    insert(6);
    insert(9);
    printBFS(root);*/
    cout << "Enten a number to choose a option" << endl << endl;
        cout << "1.Insertion"<< endl;
        cout << "2.Deletion" << endl;
        cout << "3.Print" << endl<< endl;
    while( 1 )
    {
        int n;
        cout << "Option number: ";
        cin >> n;
        if( n==1 )
        {
            cout << "Insertion" <<endl;
            cout <<"Enter the Key : ";
            cin >> n ;
            insert(n);
            printBFS(root);
            cout << endl;
        }
        else if( n==2 )
        {
            cout <<"Deletion"<<endl;
            cout <<"Enter the Key : ";
            cin>>n;
            deleteKey(n);
            printBFS(root);
            cout << endl;
        }
        else if( n==3 )
        {
            cout << "Print BFS or DFS " << endl;
            cout << "1.BFS" << endl;
            cout << "2.DFS" << endl;
            cout << "Option number: ";
            cin >> n;
            if( n==1 )
            {
                printBFS(root);
                cout << endl;
            }
            else if( n==2 )
            {
                print(root);
                cout << endl;
            }
            else cout << "Please , enter a valid option!!!!" << endl;
        }
        else cout << "Please , enter a valid option!!!!" << endl;
    }
}
