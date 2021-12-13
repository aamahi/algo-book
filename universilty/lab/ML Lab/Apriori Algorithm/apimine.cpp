#include <bits/stdc++.h>
using namespace std;

int arr[100001][100];
int Tcnt;
int minSup = 2800 ;
int cnt=0;
int mst,med;
int st;
int fcnt;
struct items
{
    int n;
    int flag;
    int ara[100];
    int freq;
}CI[1000000];

void apriori()
{
    int f;
    while( 1 )
    {
        f=0;
        int ed=cnt;
        int k,x;
        for( int i=st ; i<ed ; i++ )
        {
            if(CI[i].flag)
            {
                for( int j=mst ; j<med ; j++ )
                {
                    if( CI[i].ara[CI[i].n-1] >= CI[j].ara[0] )continue;
                    for( k=0 ; k < CI[i].n ; k++ )
                    {
                        CI[cnt].ara[k] = CI[i].ara[k];
                    }
                    CI[cnt].ara[k] = CI[j].ara[0];
                    CI[cnt].n = CI[i].n + 1;
                    for( int m=0,n ; m<Tcnt ; m++ )
                    {
                        x=n=0;
                        while( 1 )
                        {
                            for( int o = 0 ; o < CI[cnt].n ; o++ )
                            {
                                if(CI[cnt].ara[o]==arr[m][n])
                                {
                                    x++;
                                    break;
                                }
                            }
                            n++;
                            if(arr[m][n]==-1)
                            {
                                break;
                            }
                        }
                        if(x==CI[cnt].n)
                        {
                            CI[cnt].freq++;
                        }
                    }
                    if(CI[cnt].freq>=minSup)
                    {
                        f=1;
                        CI[cnt].flag=1;
                        for( int m=0 ; m < CI[cnt].n ; m++ )
                        {
                            cout << CI[cnt].ara[m] << " ";
                        }
                        cout <<" => => " << CI[cnt].freq << endl;
                        fcnt++;
                    }
                    cnt++;
                }
            }
        }
        st=ed;
        if(f==0)break;
    }
    cout << fcnt << endl;
}




int main()
{
    fcnt=0;
    FILE *fp;
    fp=fopen("input.txt","r");
    int i=0,j=0;
    map <int,int> m;
    while( fscanf(fp,"%d",&arr[i][j])!=EOF )
    {
        ///cout << arr[i][j] << " " ;
        if(arr[i][j]==-1)
        {
            ///cout << endl;
            i++;
            ///j=-1;
        }
        else
        {
            m[arr[i][j]]++;
        }
        j++;
    }
    Tcnt=i;
    double pt;
    cin >> pt;
    minSup=Tcnt*0.01*pt;
    cout << minSup << endl;
    ///cout << endl;

    mst=st=0;
    for (map<int,int>::iterator it=m.begin(); it!=m.end(); ++it)
    {
        ///cout << it->first << " => " << it->second << '\n';
        if(it->second < minSup)continue;
        CI[cnt].ara[0]=it->first;
        CI[cnt].flag=1;
        CI[cnt].n=1;
        CI[cnt].freq=it->second;
        cnt++;
    }
    med=cnt;
    ///cout << "Itesms = " << cnt << endl;
    apriori();
    ///print();

    return 0;
}
