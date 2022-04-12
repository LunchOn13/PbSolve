#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int map[9][9];
int mapcopy[9][9];
int n, m;
int ssize = 0;
pair<int, int> virus[11];

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};

bool check = false;

// 범위 체크
bool cb(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}

// 배열 초기화
void clear()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mapcopy[i][j] = map[i][j];
        }
    }
}

// 바이러스 퍼트리기 및 범위 계산
int calc()
{
    for (int i = 0; i < ssize; i++)
    {
        queue<pair<int, int>> q;
        pair<int, int> dot = virus[i];
        q.push(dot);

        while (!q.empty())
        {
            dot = q.front();
            q.pop();

            for (int j = 0; j < 4; j++)
            {
                int x = dot.first + adjx[j];
                int y = dot.second + adjy[j];

                if (cb(x, y))
                {
                    if (mapcopy[x][y] == 0)
                    {
                        mapcopy[x][y] = 2;
                        q.push(make_pair(x, y));
                    }
                }
            }

        }
    }

    check = true;

    //범위계산
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapcopy[i][j] == 0)
                cnt++;
        }
    }
    return cnt;
}

// 벽 세우기
int solving(int x, int y)
{
    clear();

    mapcopy[x][y] = 1;
    int result = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mapcopy[i][j] == 0)
            {
                mapcopy[i][j] = 1;

                for (int k = 0; k < n; k++)
                {
                    for (int t = 0; t < m; t++)
                    {
                        if (mapcopy[k][t] == 0)
                        {
                            mapcopy[k][t] = 1;
                            int tmp = calc();
                            if (tmp > result)
                                result = tmp;

                            // 원래대로
                            // 이전에 선택한 벽 원래대로 되돌리기
                            clear();
                            mapcopy[x][y] = 1;
                            mapcopy[i][j] = 1;
                        }
                    }
                }

                // 원래대로
                mapcopy[i][j] = 0;
            }
        }
    }

    return result;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 2)
            {
                virus[ssize] = make_pair(i, j);
                ssize++;
            }
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == 0)
            {
                int tmp = solving(i, j);
                if (max < tmp)
                {
                    max = tmp;
                }
            }
        }
    }

    cout << max;
}