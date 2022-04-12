#include <iostream>
using namespace std;

int n;
int map[15][15];

int adjx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int adjy[8] = {1, 1, 1, 0, 0, -1, -1, -1};

int cb(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;
    return true;
}

bool queen(int x, int y)
{
    map[x][y]++;

    for (int i = 0; i < 8; i++)
    {
        int tx = x + adjx[i];
        int ty = y + adjy[i];
        while (cb(tx, ty))
        {
            map[tx][ty]++;
            tx += adjx[i];
            ty += adjy[i];
        }
    }
    return true;
}

bool unqueen(int x, int y)
{
    map[x][y]--;

    for (int i = 0; i < 8; i++)
    {

        int tx = x + adjx[i];
        int ty = y + adjy[i];
        while (cb(tx, ty))
        {
            map[tx][ty]--;
            tx += adjx[i];
            ty += adjy[i];
        }
    }
    return true;
}

void clear()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
        }
    }
}

int result;
void solving(int cnt, int i)
{
    for (int j = 0; j < n; j++)
    {
        if (map[i][j] == 0)
        {

            if ((cnt + 1) == n)
            {
                result++;
                return;
            }
            else
            {
                queen(i, j);
                solving(cnt + 1, i +1);
                unqueen(i, j);
            }
        }
    }
}

int main()
{
    cin >> n;
    clear();

    solving(0,0);
    cout << result;
}