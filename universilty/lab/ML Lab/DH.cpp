#include <bits/stdc++.h>
using namespace std ;

void insertsplit( int key , int bit );

int bits=0;
int hash;
struct bucket
{
    int n;
    int val[4];
    int bit;
};
struct bucket **buck;

void split(bucket *node , int searchKey)
{
    int sk1 =searchKey;
    int mod;
    int mark;
    int save[4];
    for( int i=0 ; i<buck[searchKey]->n ; i++ )
    {
        save [i] = buck[searchKey]->val[i];
    }
    int bit=buck[searchKey]->bit+1;
    int flag=0;
    if( bits < bit )
    {
        int n = pow(2,bits);
        bits++;
        for( int i=n-1 ; i >=0 ; i-- )
        {
            buck[2*i+1]=buck[i];
            buck[2*i]=buck[i];
        }
        flag=1;
        searchKey=searchKey*2;
    }
    ///cout << "bit " << bit << "  " << bits << endl;
    if(!flag)
    {
        searchKey = searchKey / pow( 2 , bits - bit + 1 );
        for( int i= bit-1 ; i < bits ; i++ )
        {
            searchKey=searchKey*2;
        }
    }
    bucket *b0=new bucket();
    bucket *b1=new bucket();
    int sK;
    ///mark = searchKey / pow( 2 , log2(hash) - bit -  1 );
    for( int i=0 ; i < 4 ; i++ )
    {
        mod = save[i] % hash;
        sK = mod / pow(2,log2(hash)-bit);
        b0->bit=bit;
        b1->bit=bit;
        /*m=sk%2;
        if(m)mark2=skl;
        else mark1=sk1;*/
        if( (sK%2)==0 )
        {
            b0->val[b0->n]=save[i];
            b0->n++;
        }
        else
        {
            b1->val[b1->n]=save[i];
            b1->n++;
        }
    }
    mark=pow(2,bits-bit);
    int i;
    for( i=searchKey ; i < searchKey + mark  ; i++ )
    {
        buck[i]=b0;
    }
    for(     ; i < searchKey + (2*mark)  ; i++ )
    {
        buck[i]=b1;
    }
    ///cout << b0->n << endl << b1->n << endl;
    ///cout << searchKey << "  " << mark << endl;
    if( b0->n > 3 )
        split(b0,searchKey);
    if( b1->n > 3 )
        split(b1,searchKey+mark);
}
void print()
{
    int n;
    int x;
    cout << endl << endl <<  bits << endl;
    for( int i=0 ; i < pow (2,bits) ; i++ )
    {
        n=pow (2,bits);
        x=i;
        while( 1 )
        {
            n=n/2;
            if(!n)break;
            if( x>=n )
            {
                cout << "1" ;
                x=x-n;
            }
            else
            {
                cout << "0" ;
            }
        }
        cout << endl;
        cout << "        " << buck[i]->bit << endl;
        for( int j=0 ; j < buck[i]->n  ; j++ )
        {
            x=buck[i]->val[j];
            x=x%hash;
            cout << "        ";
            n=hash;
            while( 1 )
            {
                n=n/2;
                if(!n)break;
                if( x>=n )
                {
                    cout << "1" ;
                    x=x-n;
                }
                else
                {
                    cout << "0" ;
                }
            }
            cout << "   " << buck[i]->val[j] << endl;
        }
    }
}
void insert( int key )
{
    int mod = key % hash;
    int searchKey = mod / pow(2,log2(hash)-bits);
    buck[searchKey]->val[buck[searchKey]->n] = key;
    buck[searchKey]->n++;
    if( buck[searchKey]->n > 3 )
    {
        split( buck[searchKey] , searchKey );
    }

}



int main()
{
    buck=new bucket*[100];
    cout << "Please enter the Hash function\n\nf(x) = x % ";
    cin >> hash;
    buck[0]=new bucket();
    buck[0]->n=0;
    buck[0]->bit=0;
    /*insert(10);
    insert(12);
    insert(15);
    insert(17+4);
    insert(25);
    insert(33+4);
    insert(18+4);
    insert(26);
    insert(35+4);
    insert(20);
    insert(23);
    print();*/
    int n;
    while( 1 )
    {
        cout << "Insertion"<< endl;
        cout << "Enter a number : ";
        cin >> n;
        insert(n);
        print();
    }
    return 0;
}
