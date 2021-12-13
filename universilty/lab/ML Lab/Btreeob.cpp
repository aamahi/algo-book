#include <bits/stdc++.h>
using namespace std ;

struct node
{
    bool lf_flag;
    int  n;
    int  *keys;
    node **ch_ptr;
    node *par;
};

struct Btree
{
    node *root=NULL;
    node* init();
    node* search(node *curr , int key);
    void insert( int key );
    void delete_n(int key);
    void split(node *curr);
    void internal_node_split(node *curr);
    void print( node *curr );
};

node* Btree ::  init()
{
    node *ob = new node;
    ob->keys = new int[4];
    ob->ch_ptr = new node *[4];
    ob->par = NULL;
    ob->lf_flag = true;
    ob->n = 0;
    for (int i = 0; i < 4; i++)
    {
        ob->ch_ptr[i] = NULL;
    }
    return ob;
}

void Btree ::insert( int key )
{
    if( root==NULL )
    {
        root=init();
        root->keys[0]=key;
        root->n++;
        return;
    }
    node *curr = search(root,key);
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
        split(curr);
    }

}

node* Btree :: search(node *curr , int key)
{
    if(curr->lf_flag) return curr;
    for(int i=0; i < curr->n ; i++ )
    {
        if( curr->keys[i] > key )
        {
            return search(curr->ch_ptr[i],key);
        }
    }
    return search(curr->ch_ptr[curr->n],key);
}

void Btree ::split(node *curr)
{
    node * newNode= init();
    for( int i=(curr->n/2) , j=0 ; i < curr->n ; i++ , j++ )
    {
        newNode->keys[j]=curr->keys[i];
        newNode->n++;
    }
    curr->n = curr->n/2 ;
    if( curr->par == NULL )
    {
        node * newRoot=init();
        newRoot->keys[0]=newNode->keys[0];
        newRoot->n++;
        newRoot->lf_flag=false;
        newRoot->ch_ptr[0]=curr;
        newRoot->ch_ptr[1]=newNode;
        newNode->par=newRoot;
        curr->par=newRoot;
        root=newRoot;
    }
    else
    {
        int key = newNode->keys[0];
        curr=curr->par;
        int i;
        curr->ch_ptr[curr->n+1]=curr->ch_ptr[curr->n];
        for( i=0; i < curr->n ; i++ )
        {
            if( curr->keys[i] > key )
            {
                for( int j=curr->n-1 ; j>=i  ; j-- )
                {
                    curr->keys[j+1]=curr->keys[j];
                    curr->ch_ptr[j+1]=curr->ch_ptr[j];
                }
                curr->keys[i]=key;
                curr->ch_ptr[i]=curr->ch_ptr[i+1];
                curr->ch_ptr[i+1]=newNode;
                break;
            }
        }
        if( i == curr->n )
        {
            curr->keys[curr->n]=key;
            curr->ch_ptr[curr->n]=curr->ch_ptr[curr->n+1];
            curr->ch_ptr[curr->n+1]=newNode;
        }
        curr->n++;
        newNode->par=curr;
        if(curr->n > 3 )
            internal_node_split(curr);
    }
}


void Btree ::internal_node_split(node *curr)
{
    node * newNode= init();
    newNode->lf_flag=false;
    int i,j;
    for(  i=(curr->n/2)+1 , j=0 ; i < curr->n ; i++ , j++ )
    {
        newNode->keys[j]=curr->keys[i];
        newNode->ch_ptr[j]=curr->ch_ptr[i];
        newNode->ch_ptr[j]->par=newNode;
        newNode->n++;
    }
    newNode->ch_ptr[j]=curr->ch_ptr[i];
    newNode->ch_ptr[j]->par=newNode;
    curr->n = curr->n/2 ;

    int upperkey = curr->keys[curr->n/2+1];
    if( curr->par == NULL )
    {
        node * newRoot=init();
        newRoot->keys[0]=upperkey;
        newRoot->n++;
        newRoot->lf_flag=false;
        newRoot->ch_ptr[0]=curr;
        newRoot->ch_ptr[1]=newNode;
        newNode->par=newRoot;
        curr->par=newRoot;
        root=newRoot;
    }
    else
    {
        ///int key = newNode->keys[0];
        curr=curr->par;
        int i;
        curr->ch_ptr[curr->n+1]=curr->ch_ptr[curr->n];
        for( i=0; i < curr->n ; i++ )
        {
            if( curr->keys[i] > upperkey )
            {
                for( int j=curr->n-1 ; j>=i  ; j-- )
                {
                    curr->keys[j+1]=curr->keys[j];
                    curr->ch_ptr[j+1]=curr->ch_ptr[j];
                }
                curr->keys[i]=upperkey;
                curr->ch_ptr[i]=curr->ch_ptr[i+1];
                curr->ch_ptr[i+1]=newNode;
                break;
            }
        }
        if( i == curr->n )
        {
            curr->keys[curr->n]=upperkey;
            curr->ch_ptr[curr->n]=curr->ch_ptr[curr->n+1];
            curr->ch_ptr[curr->n+1]=newNode;
        }
        curr->n++;
        newNode->par=curr;
        if(curr->n > 3 )
            internal_node_split(curr);
    }
}

void Btree ::print( node *curr )
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
        cout << "|" << tmp->par->keys[0]<< "|";*/
        cout << "     " ;

        if( tmp->lf_flag )continue;
        for(int i=0 ; i <= tmp->n ; i++ )
        {
            q.push(tmp->ch_ptr[i]);
            m[tmp->ch_ptr[i]]=m[tmp]+1;
        }
    }
    cout << endl;
}

void Btree ::delete_n(int key)
{
    node *curr = search(root,key);
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
                if(tmp->par==NULL)break;
                tmp2=tmp;
                tmp=tmp->par;
                for( i=0 ; i <tmp->n ; i++ )
                {
                    if( tmp->ch_ptr[i] == tmp2 )
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
            if(tmp->par==NULL)
            {
                flag=0;
                break;
            }
            tmp2=tmp;
            tmp=tmp->par;
            for( i=0 ; i <tmp->n ; i++ )
            {
                if( tmp->ch_ptr[i] == tmp2 )
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
            tmp=tmp->ch_ptr[i-1];
            ///cout << "Debug  =" <<tmp2->keys[0] << endl;
            ///cout << "Debug  =" <<tmp->keys[0] << endl;
            while( 1 )
            {
                if(tmp->lf_flag)break;
                tmp=tmp->ch_ptr[tmp->n];
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
            node *curr2 = curr->par;
            int j;
            for( j=0 ; j < curr2->n ; j++ )
            {
                if(curr2->ch_ptr[j]==curr)
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
                    curr2->ch_ptr[k+1]=curr2->ch_ptr[k+2];
                }
                ///curr2->ch_ptr[curr2->n-1]=curr2->ch_ptr[curr2->n];
                curr2->n--;
                if( j==0 )
                {
                    tmp2->keys[i-1]=curr2->ch_ptr[0]->keys[0];
                }
            }
            if( curr2->n == 0 )
            {
                if(curr2==root)
                {
                    root=root->ch_ptr[0];
                    root->par=NULL;
                    return;
                }
                flag=1;
                tmp=curr2;
                while( 1 )
                {
                    if(tmp->par==NULL)
                    {
                        flag=0;
                        break;
                    }
                    tmp2=tmp;
                    tmp=tmp->par;
                    for( i=0 ; i <tmp->n ; i++ )
                    {
                        if( tmp->ch_ptr[i] == tmp2 )
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
                    tmp=tmp->ch_ptr[i-1];
                    while( 1 )
                    {
                        if(tmp->lf_flag)break;
                        tmp=tmp->ch_ptr[tmp->n];
                    }
                    ///From Here
                    if(tmp->par->n >= 2)
                    {
                        tmp->par->n--;
                        curr2->ch_ptr[1]=curr2->ch_ptr[0];
                        curr2->ch_ptr[0]=tmp;///Change
                        tmp->par=curr2;
                        tmp2->keys[i-1]=curr2->ch_ptr[0]->keys[0];
                        curr2->keys[0]=curr2->ch_ptr[1]->keys[0];
                        curr2->n++;
                    }
                    else
                    {
                        tmp2->n--;
                        tmp->par->ch_ptr[tmp->par->n+1]=curr2->ch_ptr[0];
                        curr2->ch_ptr[0]->par=tmp->par;///Change
                        tmp->par->keys[tmp->par->n]=curr2->ch_ptr[0]->keys[0];
                        tmp->par->n++;
                        if(root->n==0)
                        {
                            root=root->ch_ptr[0];
                            root->par=NULL;
                        }
                    }
                }
                else
                {
                    curr=curr2->ch_ptr[0];
                    tmp=curr2->par->ch_ptr[1];
                    if(tmp->n >= 2)
                    {
                        ///cout << "Here" << endl;
                        curr2->ch_ptr[1]=tmp->ch_ptr[0];
                        tmp->ch_ptr[0]->par=curr2;///Change
                        curr2->keys[0]=curr2->ch_ptr[1]->keys[0];
                        curr2->n++;
                        for( int i=1  ; i <= tmp->n ; i++ )
                        {
                            tmp->ch_ptr[i-1]=tmp->ch_ptr[i];
                        }
                        for( int   i=0  ; i < tmp->n ; i++ )
                        {
                            tmp->keys[i]=tmp->ch_ptr[i+1]->keys[0];
                        }
                        tmp->n--;
                        curr2->par->keys[0]=tmp->ch_ptr[0]->keys[0];
                    }
                    else
                    {
                        ///cout << "Here" << endl;
                        tmp->ch_ptr[tmp->n+1]=tmp->ch_ptr[tmp->n];
                        for( int i=tmp->n-1 ; i>=0 ; i-- )
                        {
                            tmp->ch_ptr[i+1]=tmp->ch_ptr[i];
                            tmp->keys[i+1]=tmp->keys[i];
                        }
                        tmp->ch_ptr[0]=curr2->ch_ptr[0];
                        curr2->ch_ptr[0]->par=tmp;///Change
                        tmp->keys[0]=tmp->ch_ptr[1]->keys[0];
                        tmp->n++;
                        root=root->ch_ptr[1];
                        root->par=NULL;

                    }
                }
            }
        }
        else if( flag == 0 )
        {
            ///Borrow Right
            tmp=curr->par->ch_ptr[1];
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
                curr->par->keys[0]=tmp->keys[0];
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
                curr=curr->par;
                for(int j=0 ; j < curr->n ; j++ )
                {
                    curr->ch_ptr[j]=curr->ch_ptr[j+1];
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
                        root=root->ch_ptr[0];
                        root->par=NULL;
                        return;
                    }
                    node *curr2=curr->par;
                    tmp=curr2->ch_ptr[1];
                    if(tmp->n >= 2)
                    {
                        curr->ch_ptr[1]=tmp->ch_ptr[0];
                        tmp->ch_ptr[0]->par=curr;
                        curr->keys[0]=curr->ch_ptr[1]->keys[0];
                        curr->n++;
                        for( i=1 ; i<tmp->n+1 ; i++ )
                        {
                            tmp->ch_ptr[i-1]=tmp->ch_ptr[i];
                        }
                        tmp->n--;
                        for( i=0 ; i<tmp->n ; i++ )
                        {
                            tmp->keys[i]=tmp->ch_ptr[i+1]->keys[0];
                        }
                        curr2->keys[0]=tmp->ch_ptr[0]->keys[0];
                    }
                    else
                    {
                        cout << "Eue" << endl;
                        tmp->ch_ptr[2]=tmp->ch_ptr[1];
                        tmp->ch_ptr[1]=tmp->ch_ptr[0];
                        tmp->keys[0]=tmp->ch_ptr[1]->keys[0];
                        tmp->keys[1]=tmp->ch_ptr[2]->keys[0];
                        tmp->ch_ptr[0]=curr->ch_ptr[0];
                        tmp->ch_ptr[0]->par=tmp;
                        tmp->n++;
                        curr2->n--;
                        if(curr2->n==0)
                        {
                            root=root->ch_ptr[1];
                            root->par=NULL;
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
    Btree ob;
    ob.insert(10);
    ob.insert(20);
    ob.insert(13);
    ob.insert(25);
    ob.insert(30);
    ob.insert(21);
    ob.insert(22);
    ob.insert(28);
    ob.insert(27);
    ob.insert(23);
    ob.insert(32);
    ob.insert(35);
    ob.print(ob.root);
    /*print(root);
    cout << endl;
    /*delete_n(22);
    print(root);
    cout << endl;
    delete_n(10);
    print(root);
    cout << endl;
    /*delete_n(10);
    print(root);
    cout << endl;
    delete_n(22);
    print(root);
    cout << endl;
    delete_n(21);
    print(root);
    cout << endl;
    delete_n(28);
    print(root);
    cout << endl;
    delete_n(32);
    print(root);
    cout << endl;
    delete_n(25);
    print(root);
    cout << endl;
    delete_n(30);
    print(root);
    cout << endl;
    /*delete_n(23);
    print(root);
    cout << endl;
    delete_n(21);
    print(root);
    cout << endl;
    delete_n(20);
    print(root);
    cout << endl;
    delete_n(27);
    print(root);
    cout << endl;
    delete_n(22);
    print(root);
    cout << endl;
    delete_n(13);
    print(root);
    cout << endl;
    /*insert(29);
    delete_n(10);
    print(root);
    cout << endl;
    delete_n(28);
    print(root);
    cout << endl;
    /*delete_n(22);
    print(root);
    cout << endl;
    /*delete_n(17);
    print(root);
    cout << endl;
    delete_n(23);
    print(root);
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
    print(root);*/
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
            ob.insert(n);
            ob.print(ob.root);
            cout << endl;
        }
        else if( n==2 )
        {
            cout <<"Deletion"<<endl;
            cout <<"Enter the Key : ";
            cin>>n;
            ob.delete_n(n);
            ob.print(ob.root);
            cout << endl;
        }
        else if( n==3 )
        {
            ob.print(ob.root);
        }
        else cout << "Please , enter a valid option!!!!" << endl;
    }
}
