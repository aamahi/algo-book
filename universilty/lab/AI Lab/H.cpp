#include <bits/stdc++.h>
using namespace std;

class node
{
public :
    int fin[4][4]={
    {1,2,3},
    {4,5,6},
    {7,8,0}
    };
    int w;
    int cnt;
    int mcnt[1000];
    int grid[4][4];
    bool operator < ( const node& c )const
    {
        return w > c.w;
    }
    void calculate()
    {
        int x;
        for(int i=0 ; i<3 ; i++ )
        {
            for( int j=0 ; j<3 ; j++ )
            {
                x=grid[i][j];
                for(int k=0 ; k<3 ; k++ )
                {
                    for( int l=0 ; l<3 ; l++ )
                    {
                        if(x==fin[k][l])
                        {
                            w+=abs(k-i)+abs(j-l);
                        }
                    }
                }
            }
        }
    }
};
struct sw
{
    int x1,y1;
    int x2,y2;
}ara[12];

int fin[4][4]={
    {1,2,3},
    {4,5,6},
    {7,8,0}
    };

void path(int *ar , int i )
{
    int pr[4][4];
    if(i==-1)return;
    int x1,y1,x2,y2;
    x1=ara[ar[i]].x1;
    x2=ara[ar[i]].x2;
    y1=ara[ar[i]].y1;
    y2=ara[ar[i]].y2;
    int tp=fin[x1][y1];
    fin[x1][y1]=fin[x2][y2];
    fin[x2][y2]=tp;
    ///cout <<ar[i] << endl;
    for(int j=0 ;j<3 ; j++ )
    {
        for( int k=0 ; k<3 ; k++ )
        {
            pr[j][k]=fin[j][k];
            ///cout << fin[j][k] << "  ";
        }
        ///cout << endl;
    }
    ///cout << endl << endl;
    path(ar,i-1);
    for(int j=0 ;j<3 ; j++ )
    {
        for( int k=0 ; k<3 ; k++ )
        {
            ///pr[j][k]=fin[j][k];
            cout << pr[j][k] << "  ";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void search()
{
    node st;
    FILE *fp;
    fp = fopen("input.txt", "r");
    for(int i=0 ; i<3 ; i++ )
    {
        for( int j=0 ; j<3 ; j++ )
        {
            fscanf(fp,"%d",&st.grid[i][j]);
        }
    }
    /*for(int i=0 ; i<3 ; i++ )
    {
        for( int j=0 ; j<3 ; j++ )
        {
            printf("%d ",st.grid[i][j]);
        }
        cout << endl;
    }*/
    st.calculate();
    st.cnt=0;
    priority_queue < node > q;
    q.push(st);
    while(!q.empty())
    {
        node curr=q.top();
        q.pop();
        if(curr.w==0)
        {
            /*for(int j=0 ; j<curr.cnt ; j++ )
            {
                cout << curr.mcnt[j] << "  " ;
            }*/
            cout << endl<<endl;
            path(curr.mcnt,curr.cnt-1);
            node lt;
            for(int j=0 ;j<3 ; j++ )
            {
                for( int k=0 ; k<3 ; k++ )
                {
                    ///pr[j][k]=fin[j][k];
                    cout << lt.fin[j][k] << "  ";
                }
                cout << endl;
            }
            cout << endl << endl;
            cout << "Solution from " << curr.cnt << "  moves" << endl;
            return;
        }
        for(int  i=0 ; i < 12 ; i++ )
        {
            node tmp=node();
            for(int k=0 ; k<3 ; k++ )
            {
                for( int j=0 ; j<3 ; j++ )
                {
                    tmp.grid[k][j]=curr.grid[k][j];
                }
            }
            int x1,y1,x2,y2;
            x1=ara[i].x1;
            x2=ara[i].x2;
            y1=ara[i].y1;
            y2=ara[i].y2;
            int tp=tmp.grid[x1][y1];
            tmp.grid[x1][y1]=tmp.grid[x2][y2];
            tmp.grid[x2][y2]=tp;
            tmp.calculate();
            for(int j=0 ; j<curr.cnt ; j++ )
            {
                tmp.mcnt[j]=curr.mcnt[j];
            }
            tmp.mcnt[curr.cnt]=i;
            tmp.cnt=curr.cnt+1;
            /*for(int k=0 ; k<3 ; k++ )
            {
                for( int j=0 ; j<3 ; j++ )
                {
                    cout << tmp.grid[k][j] << "  ";
                }
                cout << endl;
            }
            cout << tmp.w << "  " << tmp.cnt << endl << endl << endl;*/
            q.push(tmp);
        }
        ///for( int i=0 ; i<10000000000 ; i++ );
    }
}


int main()
{
    int c=0;
    for(int i=0 ; i<3 ; i++ )
    {
        for( int j=0 ; j<3 ; j++ )
        {
            int x,y;
            x=i+1;
            y=j;
            if( x<=2 )
            {
                ara[c].x1=i;
                ara[c].y1=j;
                ara[c].x2=x;
                ara[c].y2=y;
                c++;
            }
            x=i;
            y=j+1;
            if( y<=2 )
            {
                ara[c].x1=i;
                ara[c].y1=j;
                ara[c].x2=x;
                ara[c].y2=y;
                c++;
            }
        }
    }
    search();
    /*for( int i=0 ; i <12 ; i++ )
    {
        cout << ara[i].x1 << ara[i].y1 <<  "   ";
        cout << ara[i].x2 << ara[i].y2 << endl;
    }*/
}
