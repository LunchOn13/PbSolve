#include <iostream>

using namespace std;

int n;

int student[401];
int prefer[401][4];

int map[21][21];
int score[21][21];
int base[21][21];

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};

bool cB(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n)
        return false;
    return true;
}

void solving(int stnum)
{
    int *like = prefer[stnum];

    // 기본 자리 점수 배정
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            score[i][j] = base[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x = i;
            int y = j;

            if (map[x][y] != 0)
                continue;

            for (int k = 0; k < 4; k++)
            {
                int tx = x + adjx[k];
                int ty = y + adjy[k];

                // 빈공간과 선호하는 사람에 따라 점수 추가
                if (cB(tx, ty))
                {
                    if (map[tx][ty] == 0)
                        score[x][y] += 10000;

                    for (int l = 0; l < 4; l++)
                    {
                        if (map[tx][ty] == like[l])
                            score[x][y] += 100000;
                    }
                }
            }
        }
    }

    int max = -1;
    int rx, ry;
    // score 비교
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (max < score[i][j] && map[i][j] == 0)
            {
                max = score[i][j];
                rx = i;
                ry = j;
            }
        }
    }
    map[rx][ry] = stnum;
}

// 만족도 계산
int calc(int x, int y)
{
    int target = map[x][y];
    int *like = prefer[target];

    int cnt = 0;

    for (int i = 0; i < 4; i++)
    {
        int tx = x + adjx[i];
        int ty = y + adjy[i];

        if (!cB(tx, ty))
            continue;
        for (int j = 0; j < 4; j++)
        {
            if (map[tx][ty] == like[j])
                cnt++;
        }
    }

    if (cnt == 1)
        return 1;
    if (cnt == 2)
        return 10;
    if (cnt == 3)
        return 100;
    if (cnt == 4)
        return 1000;
    return 0;
}

int main()
{
    cin >> n;

    int size = n * n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = 0;
            score[i][j] = 0;
            base[i][j] = n + 1 - j + (n + 1 - i) * 100;
        }
    }

    for (int i = 1; i <= size; i++)
    {
        int tmp;
        cin >> tmp;

        student[i] = tmp;

        for (int j = 0; j < 4; j++)
        {
            cin >> prefer[tmp][j];
        }
    }

    for (int i = 1; i <= size; i++)
    {
        solving(student[i]);
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            result += calc(i, j);
        }
    }

    cout << result << "\n";
}