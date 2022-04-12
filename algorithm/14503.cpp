#include <iostream>

using namespace std;
int n, m;
int x, y;
int d; // 0 북 1 동 2 남 3 서

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, 1, 0, -1};

int map[50][50];
int result = 0;

void work()
{
    while (true)
    {
        // 1. 현재 위치 청소
        if (map[x][y] == 0)
        {
            map[x][y] = -1;
            result++;
        }

        // 2. 현재위치에서 왼쪽 방향부터 차례대로 인접한칸을 탐색한다.

        bool check = false;
        for (int i = 0; i < 4; i++)
        {
            //2.b
            d--;
            if (d < 0)
                d = 3;
            int tx = x + adjx[d];
            int ty = y + adjy[d];

            if (map[tx][ty] == 0)
            {
                // 2.a
                // bool 하나 넣어야될듯
                x = tx;
                y = ty;
                check = true;
                break;
            }
        }

        // 2.c and 2.d
        if (check == false)
        {
            int back = d;
            for (int i = 0; i < 2; i++)
            {
                back--;
                if (back < 0)
                    back = 3;
            }

            int tx = x + adjx[back];
            int ty = y + adjy[back];
            if (map[tx][ty] == 1)
                return;
            else
            {
                x = tx;
                y = ty;
            }
        }
    }
}

int main()
{
    cin >> n >> m;

    cin >> x >> y >> d;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
        }
    }

    work();
    cout << result;
}