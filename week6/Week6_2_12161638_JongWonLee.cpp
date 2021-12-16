#include <iostream>
#include <queue>

using namespace std;

// 0 이동가능
// 1 이동불가
// 2 소총수, 검사
// 3 이동함
// 4 safe
int map[1001][1001];

const int cnt[3] = { -1, 0, 1 };

int n;
bool check_bound(int x, int y)
{
    if (x <= 0)
        return false;
    if (x > n)
        return false;
    if (y <= 0)
        return false;
    if (y > n)
        return false;

    return true;
}

struct findcord{
    public:
        int x;
        int y;
        int length;

    findcord()
    {
        this->x = 0;
        this->y = y;
        this->length = length;
    }

    findcord(int x, int y, int length)
    {
        this->x = x;
        this->y = y;
        this->length = length;
    }
};

int finding(int x, int y)
{
    if(map[x][y] == 4)
        return 0;
    queue<findcord> q;
    findcord start(x,y,0);
    q.push(start);
    map[x][y] = 3;

    while (!q.empty())
    {
        findcord target = q.front();
        q.pop();
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                int tx = target.x + cnt[i];
                int ty = target.y + cnt[j];
                if(map[tx][ty] == 4)
                {
                    return target.length + 1;
                }
                if(check_bound(tx,ty) && map[tx][ty] == 0)
                {
                    findcord tmp(tx,ty,target.length+1);
                    map[tx][ty] = 3;
                    q.push(tmp);
                }
            }
        }
    }
    return 0;
}

void solving()
{
    cin >> n;

    int inx, iny, safex, safey;
    int sx, sy, gx, gy;

    cin >> inx >> iny >> safex >> safey;
    cin >> sx >> sy >> gx >> gy;

    // 맵 초기화
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            map[i][j] = 0;
        }
    }

    // 이동불가 지역 - 검사
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int t_x = sx + cnt[i];
            int t_y = sy + cnt[j];
            if (check_bound(t_x, t_y))
                map[t_x][t_y] = 1;
        }
    }
    map[sx][sy] = 2;

    // 이동불가 지역 - 소총수
    map[gx][gy] = 2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int tx = gx + cnt[i];
            int ty = gy + cnt[j];

            while (check_bound(tx, ty) && map[tx][ty] != 2)
            {
                map[tx][ty] = 1;
                tx += cnt[i];
                ty += cnt[j];
            }
        }
    }
    map[safex][safey] = 4;

    cout << finding(inx,iny) << "\n";
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solving();
    }
}