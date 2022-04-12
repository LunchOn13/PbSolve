#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
int map[500][500];
int check[500][500];

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};

int checkCnt = 1;

struct dot
{
    dot()
    {
    }
    dot(int xx, int yy, int sscore)
    {
        this->x = xx;
        this->y = yy;
        this->score = sscore;
    }
    int x;
    int y;
    int score;

    bool operator<(const dot d) const
    {
        return this->score < d.score;
    }
    bool operator==(const dot d) const
    {
        return  (this->x == d.x) && (this->y == d.y);
    }
};

// check bound
bool cb(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return true;
}

dot big;
dot nextBig;

void finding(int x, int y)
{
    // 4칸 찾아보기
    for (int i = 0; i < 4; i++)
    {
        int tmpx = x + adjx[i];
        int tmpy = y + adjy[i];
        if (cb(tmpx, tmpy))
        {
            if (check[tmpx][tmpy] < checkCnt)
            {
                dot tmp = dot(tmpx, tmpy, map[tmpx][tmpy]);
                if (big < tmp)
                {
                    nextBig = big;
                    big = tmp;
                }
                else if (nextBig < tmp)
                {
                    nextBig = tmp;
                }

                check[tmpx][tmpy] = checkCnt;
            }
        }
    }
}

int solving(int x, int y)
{

    big = dot(-1, -1, -1);
    nextBig = dot(-1, -1, -1);

    // 첫번째 선택한 칸
    check[x][y] = checkCnt;
    int result = map[x][y];
    int cnt = 3;

    // 4칸찾아서 최대값 만들기
    while (cnt--)
    {
        finding(x, y);
        result += big.score;
        x = big.x;
        y = big.y;
        dot tmp = big;
        big = nextBig;
        // 초기화가 제대로 안되는 경우가 있다...
        if(big == tmp)
        {
            big = dot(-1,-1,-1);
        }
        if(nextBig == tmp)
        {
            nextBig = dot(-1,-1,-1);
        }
    }

    checkCnt++;
    return result;
}

// 입력받기용
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
            check[i][j] = 0;
        }
    }

    int max = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] != 0)
            {
                int result = solving(i, j);
                if (result > max)
                    max = result;
            }
        }
    }
    cout << max;
}