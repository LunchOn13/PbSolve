#include <iostream>

using namespace std;

int r, c, t;

int map[50][50];
int tmp[50][50];

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};

int ax;
int ay;

int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};
int ddirx[4] = {-1, 0, 1, 0};
int ddiry[4] = {0, 1, 0, -1};

bool cb(int x, int y)
{
    if (x < 0 || y < 0 || x >= r || y >= c)
        return false;
    return true;
}

void dust()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            tmp[i][j] = 0;
        }
    }

    tmp[ax][ay] = -1;
    tmp[ax - 1][ay] = -1;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] > 0)
            {
                int boom = (int)(map[i][j] / 5);
                int cnt = 0;
                for (int z = 0; z < 4; z++)
                {
                    int tx = i + adjx[z];
                    int ty = j + adjy[z];
                    if (cb(tx, ty) && map[tx][ty] != -1)
                    {
                        cnt++;
                        tmp[tx][ty] += boom;
                    }
                }

                tmp[i][j] += map[i][j] - (map[i][j] / 5 * cnt);
            }
        }
    }
    // 다시 map에 넣기
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            map[i][j] = tmp[i][j];
        }
    }
}

void activate()
{
    int topx = ax - 1;
    int topy = ay;

    int botx = ax;
    int boty = ay;

    int direction = 0;

    int tmpx = topx;
    int tmpy = topy;

    while (map[tmpx+ddirx[direction]][tmpy+ddiry[direction]] != -1)
    {
        int bx = tmpx;
        int by = tmpy;

        tmpx += ddirx[direction];
        tmpy += ddiry[direction];
        if (!cb(tmpx, tmpy) || tmpx == topx + 1)
        {
            tmpx -= ddirx[direction];
            tmpy -= ddiry[direction];
            direction++;
            tmpx += ddirx[direction];
            tmpy += ddiry[direction];
        }

        if (map[bx][by] != -1)
        {
            map[bx][by] = map[tmpx][tmpy];
        }
    }
    map[topx][topy + 1] = 0;

    direction = 0;
    tmpx = botx;
    tmpy = boty;

    while (map[tmpx+dirx[direction]][tmpy+diry[direction]] != -1)
    {
        int bx = tmpx;
        int by = tmpy;

        tmpx += dirx[direction];
        tmpy += diry[direction];
        if (!cb(tmpx, tmpy) || tmpx == botx - 1)
        {
            tmpx -= dirx[direction];
            tmpy -= diry[direction];
            direction++;
            tmpx += dirx[direction];
            tmpy += diry[direction];
        }

        if (map[bx][by] != -1)
        {
            map[bx][by] = map[tmpx][tmpy];
        }
    }
    map[botx][boty + 1] = 0;
}

int main()
{
    cin >> r >> c >> t;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == -1)
            {
                ax = i;
                ay = j;
            }
        }
    }

    for (int i = 0; i < t; i++)
    {
        dust();
        activate();
    }

    int result = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] > 0)
                result += map[i][j];
        }
    }

    cout << result;
}