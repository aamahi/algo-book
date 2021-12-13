#include <bits/stdc++.h>
using namespace std;

bool board[10][10]={0};
bool move_conflict( int a , int b )
{
    for(int i=a+1 ; i<9 ; i++ )
    {
        if(board[i][b])return true;
    }
    for(int i=a-1 ; i>0 ; i-- )
    {
        if(board[i][b])return true;
    }
    for(int i=b+1 ; i<9 ; i++ )
    {
        if(board[a][i])return true;
    }
    for(int i=b-1 ; i>0 ; i-- )
    {
        if(board[a][i])return true;
    }
    int x,y;
    x=a;
    y=b;
    for(    ;   ;   )
    {
        x++;
        y++;
        if( x>8 || y>8 )break;
        if(board[x][y])return true;
    }
    x=a;
    y=b;
    for(    ;   ;   )
    {
        x--;
        y--;
        if( x<1 || y<1 )break;
        if(board[x][y])return true;
    }
    x=a;
    y=b;
    for(    ;   ;   )
    {
        x--;
        y++;
        if( x<1|| y>8 )break;
        if(board[x][y])return true;
    }
    x=a;
    y=b;
    for(    ;   ;   )
    {
        x++;
        y--;
        if( x>8 || y<1 )break;
        if(board[x][y])return true;
    }
    return false;
}
bool flag;
void Queen( int r )
{
    if(r==9)
    {
        flag=1;
        return;
    }
    int i;
    for( i=1 ; i < 9 ; i++ )
    {
        if(!move_conflict(r,i))
        {
            board[r][i]=true;
            Queen(r+1);
        }
        if(flag)return;
        else
        {
            board[r][i]=false;
        }
    }
}

int main()
{
    int a,b;
    /*for(int i=0 ; i<8 ; i++ )
    {
        cin >> a >> b;
        board[a][b]=true;
    }*/
    /*for(int x=0 ; x<8 ; x++ )
    {
        bool flag=false;
        for(int i=1 ; i<9 ; i++ )
        {
            for(int j=1  ; j<9 ; j++ )
            {
                if(!move_conflict(i,j) && !board[i][j])
                {
                    board[i][j]=true;
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
    }*/
    flag=false;
    Queen(1);
    for(int i=1 ; i<9 ; i++ )
    {
        for(int j=1  ; j<9 ; j++ )
        {
                if(board[i][j])printf("I ");
                else printf(". ");
        }
        printf("\n");
    }
}
