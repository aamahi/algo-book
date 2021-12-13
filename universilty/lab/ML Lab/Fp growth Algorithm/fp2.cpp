#include <bits/stdc++.h>
using namespace std;

int arr[100001][100];
int minSup ;
int arrcnt[1000001]={0};
struct node
{
    int item;
    int freq;
    node *par;
    node **next;
    int nC;
};

struct freqTable
{
    int item;
    int freq;
    node **links;
    int nL;
};
struct result
{
    vector < set < int > > item;
    vector < int > freq;
};

void print( node *root );
int p;
void transec( node *child , int cnt , int head )
{
    if(child->item==head)return;
    transec( child->par , cnt , head );
    arr[cnt][p]=child->item;
    p++;
}

struct result *fpGrowth( int Tcnt , int head )
{
    ///cout << head << " ::: ::: " << endl;
    map < int , int > m;
    int j;
    int n=0;
    for( int i = 0 ; i < Tcnt ; i ++ )
    {
        j=0;
        while( arr[i][j]!=-1 )
        {
            ///cout << arr[i][j] << "  ";
            if(!m[arr[i][j]])n++;
            m[arr[i][j]]=m[arr[i][j]]+arrcnt[i]+1;
            j++;
        }
        ////cout << endl;
    }
    struct freqTable *ary;
    ary = (struct freqTable*)calloc(n, sizeof(struct freqTable));
    int i=0;
    for (map<int,int>::iterator it=m.begin() ; it!=m.end() ; ++it )
    {
        if( it->second < minSup )
        {
            n--;
            continue ;
        }
        ary[i].item=it->first;
        ary[i].freq=it->second;
        ary[i].links = new  node *[it->second];
        ///cout << ary[i].item << "  " << ary[i].freq << endl;
        i++;
    }
    int tmp;
    for( int i=0 ; i<n ; i++ )
    {
        for( int j=0 ; j<n  ; j++ )
        {
            if( ary[i].freq < ary[j].freq )
            {
                tmp = ary[i].item;
                ary[i].item=ary[j].item;
                ary[j].item=tmp;
                tmp = ary[i].freq;
                ary[i].freq=ary[j].freq;
                ary[j].freq=tmp;
            }
        }
    }
    /*for( int i=0 ; i<n ; i++ )
    {
        cout << ary[i].item << "  " << ary[i].freq << endl;
    }*/

    node *root;
    root = (struct node*)calloc(1, sizeof(struct node));
    root->item=head;
    root->next = new node *[n];
    node *now;
    int flag;
    for( int i = 0 ; i < Tcnt ; i ++ )
    {
        j=0;
        now=root;
        while( arr[i][j]!=-1 )
        {
            ///cout << arr[i][j] << " " ;
            flag=0;
            for( int k=0 ; k<now->nC ; k++ )
            {
                if(now->next[k]->item==arr[i][j])
                {
                    now=now->next[k];
                    now->freq=now->freq+arrcnt[i]+1;
                    flag=1;
                    ///cout << now->item << "  " << now->freq << endl;
                    break;
                }
            }
            if(!flag)
            {
                node *tmp;
                tmp = (struct node*)calloc(1, sizeof(struct node));
                for( int k=0 ; k<n ; k++ )
                {
                    if(ary[k].item==arr[i][j])
                    {
                        ary[k].links[ary[k].nL]=tmp;
                        ary[k].nL++;
                    }
                }
                tmp->item = arr[i][j];
                tmp->freq = arrcnt[i]+1;
                now->next[now->nC] = tmp;
                tmp->next = new node *[n];
                now->nC++;
                tmp->par = now;
                now = tmp ;
                ///cout << "   " <<tmp->item << "  " << tmp->freq << endl;
            }
            j++;
        }
    }
    ///print(root);
    ///cout << endl;
    struct result *rlt;
    rlt = (struct result*)calloc(1, sizeof(struct result));
    for( int i=0 ; i < n ; i++ )
    {
        set < int > s;
        s.insert(head);
        s.insert(ary[i].item);
        rlt->item.push_back(s);
        s.clear();
        rlt->freq.push_back(ary[i].freq);
    }
    int cnt,fr,k;
    for( int i=0 ; i <n ; i++ )
    {
        cnt=0;
        for( int j=0 ; j < ary[i].nL ; j++ )
        {
            now = ary[i].links[j];
            if(now->par->item==head)
            {
                ///set < int > s;
                /*if(now->freq >= minSup)
                {
                    s.insert(now->item);
                    s.insert(head);
                    rlt->item.push_back(s);
                    rlt->freq.push_back(now->freq);
                    ///cout << now->item << "," << head << " => " << now->freq << endl;
                }*/
                ///rlt.item.push_back(s);
                ///rlt.freq.push_back(now->freq);
                continue;
            }
            ///cout << "Next = " << now->item << " " << now->freq << endl;
            arrcnt[cnt]=now->freq-1;
            now=now->par;
            p=0;
            transec(now, cnt , head );
            /*k=0;
            while( 1 )
            {
                if(now->item==head)break;
                arr[cnt][k]=now->item;
                k++;
                now=now->par;
            }*/
            arr[cnt][p]=-1;
            cnt++;
        }
        struct result *found ;
        found = (struct result*)calloc(1, sizeof(struct result));

        if( cnt > 0 )
        found = fpGrowth(cnt,ary[i].item);

        for( int j=0 ; j < found->item.size() ; j++ )
        {
            set <int > s= found->item[j];
            s.insert(head);
            rlt->item.push_back(s);
            rlt->freq.push_back(found->freq[j]);
            s.clear();
        }
        delete found;
    }
    ///cout << head <<"  found " << rlt->item.size() << endl;
    /*for( int i=0 ; i < rlt->item.size() ; i++ )
    {
        set<int> si=rlt->item[i];
        for(set<int>::iterator it=si.begin(); it!=si.end(); ++it)
        {
            if(*it!=-1)
            ///cout << *it << " ";
        }
        cout << " => ";
        cout << rlt->freq[i] << endl;
    }*/
    m.clear();
    delete ary;
    return rlt ;
}


void print( node *root )
{
    cout << root->item << ":" << root->freq << "   ";
    for( int i=0  ; i < root->nC ; i++ )
    {
        print(root->next[i]);
        cout << endl;
    }
}

int main()
{
    FILE *fp;
    fp=fopen("input.txt","r");
    int i=0,j=0;
    int Tcnt;
    while( fscanf(fp,"%d",&arr[i][j])!=EOF )
    {
        ///cout << arr[i][j] << " " ;
        if(arr[i][j]==-1)
        {
            ///cout << endl;
            i++;
            j=-1;
        }
        j++;
    }
    Tcnt = i ;
    printf("Please, Enter the minimum support threshold : ");
    double pt;
    cin >> pt ;
    minSup=Tcnt*0.01*pt;
    struct result *ans = fpGrowth( Tcnt , -1 );
    cout << "Patterns = " << ans->item.size()  <<endl;
    /*for( int i=0 ; i < ans->item.size() ; i++ )
    {
        set<int> si=ans->item[i];
        for(set<int>::iterator it=si.begin(); it!=si.end(); ++it)
        {
            if(*it!=-1)
            cout << *it << " ";
        }
        cout << " => ";
        cout << ans->freq[i] << endl;
    }*/

    return 0;
}
