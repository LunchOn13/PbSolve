#include <iostream>

using namespace std;

int n, m;
int arr[21][21];
bool visited[21][21];

// 윗면 1 동쪽 3
int dx = 1;
int dy = 1;

// 첫 이동 방향 동쪽
// 동 0 남 1 서 2 북 3
int direction = 0;

bool isInBound(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > m)
        return false;
    return true;
}

struct Dice
{
    int top;
    int bottom;
    int east;
    int west;
    int north;
    int south;
    int score;
    Dice()
    {
        top = 1;
        bottom = 6;
        east = 3;
        west = 4;
        north = 2;
        south = 5;
        score = 0;
    }

    void plusScore(int t)
    {
        this->score += t;
    }

    void move()
    {
        int tmp1, tmp2;

        switch (direction)
        {
        case 0:
            if (!isInBound(dx, dy + 1))
                direction = 2;
            break;
        case 1:
            if (!isInBound(dx + 1, dy))
                direction = 3;
            break;
        case 2:
            if (!isInBound(dx, dy - 1))
                direction = 0;
            break;
        case 3:
            if (!isInBound(dx - 1, dy))
                direction = 1;
            break;
        }

        switch (direction)
        {
        // 동
        case 0:
            tmp1 = bottom;
            bottom = east;
            tmp2 = west;
            west = tmp1;
            tmp1 = top;
            top = tmp2;
            east = tmp1;
            dy += 1;
            break;
        // 남
        case 1:
            tmp1 = bottom;
            bottom = south;
            tmp2 = north;
            north = tmp1;
            tmp1 = top;
            top = tmp2;
            south = tmp1;
            dx += 1;
            break;
        // 서
        case 2:
            tmp1 = bottom;
            bottom = west;
            tmp2 = east;
            east = tmp1;
            tmp1 = top;
            top = tmp2;
            west = tmp1;
            dy -= 1;
            break;
        //북
        case 3:
            tmp1 = bottom;
            bottom = north;
            tmp2 = south;
            south = tmp1;
            tmp1 = top;
            top = tmp2;
            north = tmp1;
            dx -= 1;
            break;
        }
    }
};

Dice aDice;

// 이동 방향으로 한칸, 칸이 없다면 반대로 한 칸
void moveDice()
{
    aDice.move();
}

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};
int cellScore(int x, int y, int target)
{
    int result = 0;
    int tmpx;
    int tmpy;
    visited[x][y] = true;
    for (int i = 0; i < 4; i++)
    {
        tmpx = x + adjx[i];
        tmpy = y + adjy[i];
        if (isInBound(tmpx, tmpy) && visited[tmpx][tmpy] == false && arr[tmpx][tmpy] == target)
        {
            result += cellScore(tmpx, tmpy, target);
        }
    }
    return result + arr[x][y];
}

// 이동 후 도착칸의 점수 획득
void getScore()
{
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <=m ;j++)
            visited[i][j] = false;
    }
    aDice.plusScore(cellScore(dx, dy, arr[dx][dy]));
}

// 이동방향 결정
void decideDirection()
{
    int A = aDice.bottom;
    int B = arr[dx][dy];
    if (A > B)
    {
        direction++;
        if (direction == 4)
            direction = 0;
    }
    else if (A < B)
    {
        direction--;
        if (direction == -1)
            direction = 3;
    }
}

void solve()
{
    int k;
    cin >> k;
    aDice = Dice();

    // 맵 입력받아야함
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <=m; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < k; i++)
    {
        moveDice();
        getScore();
        decideDirection();
    }

    cout << aDice.score;
}

int main()
{
    cin >> n >> m;
    solve();
}
