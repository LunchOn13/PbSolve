#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

char map[1025][1025];

int blue;
int red;
int bluearea;
int redarea;

bool check(int x, int y ,int len)
{
    int r = 0;
    int b = 0;
    int ra = 0;
    int ba = 0;

    for (int i = x; i < x + len; i++)
    {
        for (int j = y; j < y + len; j++)
        {
            if (map[i][j] == 'R')
            {
                if (ba > 0)
                    return true;
                ra++;
            }
            else
            {
                if (ra > 0)
                    return true;
                ba++;
            }
        }
    }

    if (ra > 0 && ba == 0)
        r++;
    else if (ba > 0 && ra == 0)
        b++;

    red += r;
    blue += b;
    redarea += ra;
    bluearea += ba;
    return false;
}

void solving()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    blue = 0;
    red = 0;
    bluearea = 0;
    redarea = 0;

    int x, y;
    int len = n/2;

    queue<pair<int, int>> q;
    queue<int> ql;

    q.push(make_pair(0, 0));
    q.push(make_pair(len, 0));
    q.push(make_pair(0, len));
    q.push(make_pair(len, len));

    for (int i = 0; i < 4; i++)
    {
        ql.push(len);
    }

    while (!q.empty())
    {
        int tx = q.front().first;
        int ty = q.front().second;
        q.pop();
        int lenth = ql.front();
        ql.pop();

        if (check(tx, ty, lenth))
        {
            int halflen = lenth / 2;
            q.push(make_pair(tx, ty));
            q.push(make_pair(tx + halflen, ty));
            q.push(make_pair(tx, ty + halflen));
            q.push(make_pair(tx + halflen, ty + halflen));

            for (int i = 0; i < 4; i++)
            {
                ql.push(halflen);
            }
        }
    }

    cout << red << " " << redarea << " " << blue << " " << bluearea << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solving();
    }
}