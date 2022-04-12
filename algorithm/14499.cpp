#include <iostream>

using namespace std;

int map[20][20];

int n, m;
int x, y;
int k;

struct dice
{
    int top = 0;
    int east = 0;
    int west = 0;
    int north = 0;
    int south = 0;
    int bottom = 0;

    void roll(int direc)
    {
        int tx = x;
        int ty = y;
        if (direc == 1)
        // 동
        {
            ty++;
            int tmp = east;
            east = top;
            top = west;
            west = bottom;
            bottom = tmp;
        }
        else if (direc == 2)
        // 서
        {
            ty--;
            int tmp = west;
            west = top;
            top = east;
            east = bottom;
            bottom = tmp;
        }
        else if (direc == 3)
        // 북
        {
            tx--;
            int tmp = north;
            north = top;
            top = south;
            south = bottom;
            bottom = tmp;
        }
        else
        // 남
        {
            tx++;
            int tmp = south;
            south = top;
            top = north;
            north = bottom;
            bottom = tmp;
        }
        x = tx;
        y = ty;
    }
};

bool cb(int direc)
{
    if (direc == 1)
    {
        if (y + 1 >= m)
            return false;
    }
    else if (direc == 2)
    {
        if (y - 1 < 0)
            return false;
    }
    else if (direc == 3)
    {
        if (x - 1 < 0)
            return false;
    }
    else
    {
        if (x + 1 >= n)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> m >> x >> y >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    dice d;

    int tmp;

    for (int i = 0; i < k; i++)
    {
        cin >> tmp;

        if (cb(tmp))
        {
            d.roll(tmp);
            if (map[x][y] == 0)
            {
               map[x][y] = d.bottom;
            }
            else
            {
                d.bottom = map[x][y];
                map[x][y] = 0;
            }

            cout << d.top << "\n";
        }
    }
}