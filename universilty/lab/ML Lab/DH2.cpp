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

void insert( int key )
{
    int mod = key % hash;
    int searchKey = mod / pow(2,log2(hash)-bits);
    buck[searchKey]->val[buck[searchKey]->n] = key;
    buck[searchKey]->n++;
    if( buck[searchKey]->n > 3 )
    {
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
        /*if(!flag)
        {
            searchKey = searchKey / pow( 2 , bits - bit - 1 );
            for( int i= bit-1 ; i < bits ; i++ )
            {
                searchKey=searchKey*2;
            }
        }*/
        bucket *b0=new bucket();
        bucket *b1=new bucket();
        int sK;
        mark = searchKey / pow( 2 , log2(hash) - bit -  1 );
        for( int i=0 ; i < 4 ; i++ )
        {
            mod = save[i] % hash;
            sK = mod / pow(2,log2(hash)-bit);
            if( 2*mark == sK )
            {
                b0->bit=bit;
                b0->val[b0->n]=save[i];
                b0->n++;
            }
            else
            {
                b1->bit=bit;
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
    }

}



int main()
{
    buck=new bucket*[100];
    cin >> hash;
    buck[0]=new bucket();
    buck[0]->n=0;
    buck[0]->bit=0;
    insert(10);
    insert(12);
    insert(15);
    insert(17);
    insert(25);
    insert(33);
    insert(18);
    insert(26);
    //insert(35);
    /*insert(20);
    insert(23);*/
    for( int i=0 ; i < pow (2,bits) ; i++ )
    {
        cout << i << endl;
        cout << "        " << buck[i]->bit << endl;
        for( int j=0 ; j < buck[i]->n  ; j++ )
        {
            cout << "        " << buck[i]->val[j] << endl;
        }
    }

    return 0;
}
