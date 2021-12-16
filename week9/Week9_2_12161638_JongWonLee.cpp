#include <iostream>

using namespace std;

// 0 blank
// 1 black
// 2 white
int map[22][22];

int c[3] = {-1,0,1};

// 0 blank
// 1 black
// 2 white
bool checkAble(int x, int y, int turn)
{   
    int opposite = turn==1?2:1;
    bool result = false;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            bool check = false;
            int tmpx = x + c[i];
            int tmpy = y + c[j];
            while(true)
            {
                if(check && map[tmpx][tmpy] == turn)
                {
                    result =  true;
                    while(true){
                    map[tmpx][tmpy] = turn;
                    tmpx -=c[i];
                    tmpy -=c[j];
                    if(tmpx == x && tmpy == y)
                        break;
                    }
                }
                else if(map[tmpx][tmpy] == opposite)
                {
                    check = true;
                    tmpx +=c[i];
                    tmpy +=c[j];
                }
                else
                    break;
            }
        }
    }

    return result;
}

void turnToMine(int x, int y, int turn)
{
    int opposite = turn==1?2:1;
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int tmpx = x + c[i];
            int tmpy = y + c[j];
            while(true)
            {
                if( map[tmpx][tmpy] == turn)
                    return;
                else if(map[tmpx][tmpy] == opposite)
                {
                    map[tmpx][tmpy] = turn;
                    tmpx +=c[i];
                    tmpy +=c[j];
                }
                else
                    break;
            }
        }
    }

}

void solving()
{
    int n;
    cin >> n;
    int q;
    cin >> q;

    map[n/2][n/2] = 1;
    map[n/2 + 1][n/2 + 1] = 1;
    map[n/2 + 1][n/2] = 2;
    map[n/2][n/2 + 1] = 2;

    // black = 1
    // white = 2
    int turn =  1;
    for(int i = 0; i < q; i++)
    {
        int r, c;
        cin >> r >> c;

        if(checkAble(r,c,turn))
        {
            // turnToMine(r,c,turn);
            turn = turn==1? 2: 1;
        }
    }

    int black = 0;
    int white = 0;

    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <=n; j++)
        {
            if(map[i][j]==1)
                black++;
            else if(map[i][j]==2)
                white++;
        }
    }

    if(black > white)
        cout << "2\n";
    else if (white > black)
        cout << "1\n";
    else
        cout << "0\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    for(int i = 0; i < 22; i++)
    {
        for(int j = 0; j < 22; j++)
        {
            map[i][j] = 0;
        }
    }


    int t;
    cin >> t;
    for(int i = 0; i <t; i++)
    {
        solving();
    }
}