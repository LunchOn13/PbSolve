#include <iostream>
#include <queue>
#include <cmath>
using namespace std;
int n, l, r;

int map[50][50];
int check[50][50];

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};

int uni = 0;
int day = 0;

int condition(int x, int y, int a, int b)
{
    // check bound
    if (a < 0 || b < 0 || a >= n || b >= n)
        return false;

    int result = abs((map[x][y] - map[a][b]));

    if (result >= l && result <= r)
        return true;

    return false;
}

void find(int x, int y)
{
    if (check[x][y] == 0)
    {
        bool tmpcheck = false;
        for (int i = 0; i < 4; i++)
        {
            int tmpx = x + adjx[i];
            int tmpy = y + adjy[i];

            if (condition(x, y, tmpx, tmpy) && check[tmpx][tmpy] == 0)
            {
                tmpcheck = true;
            }
        }
        if(!tmpcheck)
            return;

        uni++;
        int unionCnt = 0;
        check[x][y] = uni;

        queue<pair<int, int>> qdot;
        qdot.push(make_pair(x, y));

        while (!qdot.empty())
        {
            int tx = qdot.front().first;
            int ty = qdot.front().second;
            qdot.pop();

            int tmpx, tmpy;
            for (int i = 0; i < 4; i++)
            {
                tmpx = tx + adjx[i];
                tmpy = ty + adjy[i];

                if (condition(tx, ty, tmpx, tmpy) && check[tmpx][tmpy] == 0)
                {
                    qdot.push(make_pair(tmpx, tmpy));
                    check[tmpx][tmpy] = uni;
                }
            }
        }
    }
}

bool calc()
{
    bool repeat = false;

    for (int i = 1; i <= uni; i++)
    {
        int cnt = 0;
        int people = 0;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (check[j][k] == i)
                {
                    people += map[j][k];
                    cnt++;
                }
            }
        }

        int movedPeo = floor((people / cnt));

        if (movedPeo != people)
            repeat = true;

        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (check[j][k] == i)
                {
                    map[j][k] = movedPeo;
                    check[j][k] = 0;
                }
            }
        }
    }

    // 초기화
    uni = 0;
    day++;

    return repeat;
}

int main()
{
    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
            check[i][j] = 0;
        }
    }

    while (true)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                find(i, j);
            }
        }

        if (!calc())
            break;
    }

    cout << day - 1;
}