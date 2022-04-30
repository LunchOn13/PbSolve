#include<iostream>

using namespace std;

int n,m;
int arr[500][500];

bool cb(int x, int y)
{
    if(x <0 || y < 0 || x >=n || y>=m)
        return false;
    return true;
}


int tetro1(int x, int y)
{
    int tx = x;
    int ty = y;
    int result1 = 0;
    int result2 = 0;
    for(int i = 0; i < 4; i++)
    {
        if(!cb(tx,ty))
        {
            result1 = -1;
            break;
        }
        else
        {
            result1 +=arr[tx][ty];
        }
        tx++;
    }
    tx =x;
    ty =y;
    for(int i = 0; i < 4; i++)
    {
        if(!cb(tx,ty))
        {
            result2 = -1;
            break;
        }
        else
        {
            result2 += arr[tx][ty];
        }
        ty++;
    }
    return result1 > result2 ? result1 : result2;
}


int tetro2(int x, int y)
{
    if(!cb(x+1,y) || !cb(x,y) || !cb(x+1,y+1))
    {
        return 0;
    }
    return arr[x][y] + arr[x+1][y] + arr[x][y+1] + arr[x+1][y+1];
}

int tetro3(int x, int y)
{
    int tx = x;
    int ty = y;
    
    int result1 = 0;
    for(int i = 0; i < 3; i++)
    {
        if(cb(tx,ty))
        {
            result1 += arr[tx][ty];
        }
        else{
            result1 = -999;
            break;
        }
        tx++;
    }

    


    int result3 = result1;
    if(result1 > 0)
    {
        tx--;
        int tmp1 = -1;
        int tmp2 = -1;
        if(cb(tx,ty+1))
        {
            tmp1 = arr[tx][ty+1];
        }

        if(cb(tx,ty-1))
        {
            tmp2 = arr[tx][ty-1];
        }

        result1 += tmp1 > tmp2 ? tmp1 : tmp2;
    }

    if(result3 > 0)
    {
        tx = x;
        ty = y;

        int tmp1 = 0;
        int tmp2 = 0;
        if(cb(tx,ty+1))
            tmp1 = arr[tx][ty+1];
        if(cb(tx,ty-1))
            tmp2 = arr[tx][ty-1];
        
        result3 += tmp1 > tmp2 ? tmp1: tmp2;
    }

    result1 = result1 > result3 ? result1 : result3;

    tx = x;
    ty = y;
    int result2 = 0;
    for(int i = 0; i < 3; i++)
    {
        if(cb(tx,ty))
        {
            result2 += arr[tx][ty];
        }
        else{
            result2 = -999;
            break;
        }
        ty++;
    }
    int result4 = result2;
    
    if(result2 >0)
    {
        ty--;
        int tmp1 = -1;
        int tmp2 = -1;
        if(cb(tx+1,ty))
        {
            tmp1 = arr[tx+1][ty];
        }

        if(cb(tx-1,ty))
        {
            tmp2 = arr[tx-1][ty];
        }

        result2 += tmp1 > tmp2 ? tmp1 : tmp2;
    }

     if(result4 > 0)
    {
        tx = x;
        ty = y;

        int tmp1 = 0;
        int tmp2 = 0;
        if(cb(tx+1,ty))
            tmp1 = arr[tx+1][ty];
        if(cb(tx-1,ty))
            tmp2 = arr[tx-1][ty];
        
        result4 += tmp1 > tmp2 ? tmp1: tmp2;
    }

    result2 = result2 > result4 ? result2 : result4;

    return result1 > result2 ? result1 : result2;
}

int tetro4(int x, int y)
{
    int tx = x;
    int ty = y;

    int half1 = 0;
    for(int i = 0; i < 2; i++)
    {
        if(!cb(tx,ty))
        {
            half1 = -999;
            break;
        }
        half1 += arr[tx][ty];
        tx++;
    }
    
    if(half1 > 0)
    {
        tx--;
        int tmp1 = 0;
        int tmp2 = 0;

        int ttx = tx;
        int tty1 = ty+1;
        int tty2 = ty-1;

        for(int i = 0; i<2; i++)
        {
            if(cb(ttx, tty1))
            {
                tmp1 += arr[ttx][tty1];
            }
            else{
                tmp1 = -9999;
            }

            if(cb(ttx,tty2))
            {
                tmp2 += arr[ttx][tty2];
            }
            else{
                tmp2 = -9999;
            }
            ttx++;
        }
        half1 += tmp1 > tmp2 ? tmp1:tmp2;
    }


    tx = x;
    ty = y;

    int half2 = 0;
    for(int i = 0; i < 2; i++)
    {
        if(!cb(tx,ty))
        {
            half2 = -999;
            break;
        }
        half2 += arr[tx][ty];
        ty++;
    }
    
    if(half2 > 0)
    {
        ty--;
        int tmp1 = 0;
        int tmp2 = 0;

        int tty = ty;
        int ttx1 = tx+1;
        int ttx2 = tx-1;

        for(int i = 0; i<2; i++)
        {
            if(cb(ttx1, tty))
            {
                tmp1 += arr[ttx1][tty];
            }
            else{
                tmp1 = -9999;
            }

            if(cb(ttx2,tty))
            {
                tmp2 += arr[ttx2][tty];
            }
            else{
                tmp2 = -9999;
            }
            tty++;
        }
        half2 += tmp1 > tmp2 ? tmp1:tmp2;
    }

    return half1 > half2 ? half1 : half2;
}

int tetro5(int x, int y)
{
    int tx = x;
    int ty = y;

    int tri1 = 0;

    for(int i = 0; i < 3; i++)
    {
        if(cb(tx,ty))
        {
            tri1+=arr[tx][ty];
        }
        else
        {
            tri1 = -999;
            break;
        }
        tx++;
    }
    if(tri1 > 0)
    {
        tx-=2;
        int tty1 = ty + 1;
        int tty2 = ty -1;
        int tmp1 = -999;
        int tmp2 = -999;
        if(cb(tx,tty1))
        {
            tmp1 = arr[tx][tty1];
        }

        if(cb(tx,tty2))
        {
            tmp2 = arr[tx][tty2];
        }

        tri1 += tmp1 > tmp2 ? tmp1:tmp2;
    }

    tx = x;
    ty = y;

    int tri2 = 0;

    for(int i = 0; i < 3; i++)
    {
        if(cb(tx,ty))
        {
            tri2+=arr[tx][ty];
        }
        else
        {
            tri2 = -999;
            break;
        }
        ty++;
    }
    if(tri2 > 0)
    {
        ty-=2;
        int ttx1 = tx + 1;
        int ttx2 = tx -1;
        int tmp1 = -999;
        int tmp2 = -999;
        if(cb(ttx1,ty))
        {
            tmp1 = arr[ttx1][ty];
        }

        if(cb(ttx2,ty))
        {
            tmp2 = arr[ttx2][ty];
        }

        tri2 += tmp1 > tmp2 ? tmp1:tmp2;
    }
    
    return tri1 > tri2 ? tri1 : tri2;
}



void solve()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }

    int result = -1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int a = tetro1(i,j);
            int b = tetro2(i,j);
            int c = tetro3(i,j);
            int d = tetro4(i,j);
            int e = tetro5(i,j);

            if(result < a )
                result = a;
            if(result < b )
                result = b;
            if(result < c )
                result = c;
            if(result < d )
                result = d;
            if(result < e )
                result = e;
        }
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}