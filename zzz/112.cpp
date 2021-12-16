#include <iostream>

using namespace std;

// 이건 쉽다
char arr[1024][1024];

int redpaper;
int redcnt;
int bluepaper;
int bluecnt;

void div(int x, int y, int len)
{
    // 할당된 범위가 모두 같은색인지 확인

    // 모두 같은색이면 함수를 종료하면서 cnt와 paper 증가

    // 아니면  나눠서 보냄
    char color = arr[x][y];
    int cnt = 0;
    bool check = true;
    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (arr[i][j] != color)
            {
                check = false;
                break;
            }
            cnt++;
        }
        if(!check)
            break;
    }

    // 다른색이 있으면
    if(!check)
    {
        int half = len/2;
        div(x,y,half);
        div(x+half, y , half);
        div(x, y+half, half);
        div(x+half, y+half, half);
    }
    else
    {
        if(color == 'R')
        {
            redcnt+=cnt;
            redpaper++;
        }
        else
        {
            bluecnt+=cnt;
            bluepaper++;
        }
    }
}

void solving()
{
    int n;
    cin >> n;

    redpaper = 0;
    redcnt = 0;
    bluepaper = 0;
    bluecnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    div(0,0,n);

    cout << redpaper << " " << redcnt << " " << bluepaper << " " << bluecnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solving();
    }
}