#include <iostream>

using namespace std;

int n, m;

int map[8][8];
int check[8];
int camcnt = 0;

int fakeMap[8][8];

int adjx[5] = {0, -1, 0, 1, 0};
int adjy[5] = {0, 0, -1, 0, 1};

int result = 9999;

bool cb(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m || map[x][y] == 6)
        return false;
    return true;
}

void solving()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fakeMap[i][j] = map[i][j];
        }
    }

    int tvcnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // if cctv
            if (map[i][j] > 0 && map[i][j] < 6)
            {
                int theCam = map[i][j];

                int direction = check[tvcnt];
                int tx = i;
                int ty = j;
                while (cb(tx, ty))
                {
                    fakeMap[tx][ty] = -1;
                    tx += adjx[direction];
                    ty += adjy[direction];
                }

                if (theCam == 2 || theCam == 4 || theCam == 5)
                {
                    int opDirec;
                    if (direction == 1)
                        opDirec = 3;
                    else if (direction == 2)
                        opDirec = 4;
                    else if (direction == 3)
                        opDirec = 1;
                    else if (direction == 4)
                        opDirec = 2;

                    int ox = i;
                    int oy = j;
                    while (cb(ox, oy))
                    {
                        fakeMap[ox][oy] = -1;
                        ox += adjx[opDirec];
                        oy += adjy[opDirec];
                    }
                }

                if (theCam == 3 || theCam == 4 || theCam == 5)
                {
                    int opDirec = direction - 1;
                    if (opDirec == 0)
                        opDirec = 4;

                    int ox = i;
                    int oy = j;
                    while (cb(ox, oy))
                    {
                        fakeMap[ox][oy] = -1;
                        ox += adjx[opDirec];
                        oy += adjy[opDirec];
                    }
                }

                if (theCam == 5)
                {
                    int opDirec = direction + 1;
                    if (opDirec == 5)
                        opDirec = 1;

                    int ox = i;
                    int oy = j;
                    while (cb(ox, oy))
                    {
                        fakeMap[ox][oy] = -1;
                        ox += adjx[opDirec];
                        oy += adjy[opDirec];
                    }
                }
                tvcnt++;
            }
        }
    }

    int siz = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (fakeMap[i][j] == 0)
                siz++;
        }
    }

    if (siz < result)
        result = siz;
}

void combi(int idx, int next)
{
    if (next == camcnt)
    {
        // 해보기
        solving();
        return;
    }

    for (int i = idx; i < camcnt; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (check[i] != 0)
                continue;
            check[i] = j;
            combi(i, next + 1);
            check[i] = 0;
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int tmp;
            cin >> tmp;
            map[i][j] = tmp;
            if (tmp > 0 && tmp < 6)
                camcnt++;
        }
    }

    for (int i = 0; i < camcnt; i++)
    {
        check[i] = 0;
    }

    combi(0, 0);

    cout << result;
}