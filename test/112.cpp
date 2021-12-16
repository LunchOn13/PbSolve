#include <iostream>

using namespace std;

char map[1024][1024];
// 좆밥

int redp;
int redc;
int bluep;
int bluec;

void calc(int x, int y , int len)
{
    char color = map[x][y];
    bool check = true;
    int cnt= 0;
    for(int i = x; i < x+len; i++)
    {
        for(int j = y; j< y+len; j++)
        {
            if(map[i][j] != color){
                check = false;
                break;
            }
            cnt++;
        }
        if(!check)
            break;
    }

    if(!check)
    {
        int half = len/2;
        calc(x,y,half);
        calc(x+half, y, half);
        calc(x, y+ half, half);
        calc(x+half, y+half, half);
    }
    else
    {
        if(color == 'R')
        {
            redp++;
            redc += cnt;
        }
        else
        {
            bluep++;
            bluec += cnt;
        }
    }


}

void solving() {
    int n;
    cin >> n;

    for(int i = 0; i  < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    redp = 0;
    redc = 0;
    bluec = 0;
    bluep = 0;

    calc(0,0,n);

    cout << redp << " " << redc << " " << bluep << " " <<bluec << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solving();
}