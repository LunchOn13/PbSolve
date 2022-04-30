#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, K;

struct fireBall
{
public:
    fireBall() {}
    fireBall(int _x, int _y, long long _matter, long long _speed, int _direction)
    {
        this->x = _x;
        this->y = _y;
        this->matter = _matter;
        this->speed = _speed;
        this->direction = _direction;
    }
    int x = -1;
    int y = -1;
    long long matter = -1;
    long long speed = 0;
    int direction = -1;

    bool operator<(const fireBall f) const
    {
        if (this->x == f.x)
            return this->y < f.y;
        return this->x < f.x;
    }
};

queue<fireBall> balls;
priority_queue<fireBall> pq;

bool checkBound(long long x, long long y)
{
    if (x < 1 || y < 1 || x > N || y > N)
        return false;
    return true;
}

void happening()
{
    queue<fireBall> eqlBalls;

    while (!pq.empty())
    {
        fireBall target = pq.top();
        pq.pop();

        while (true)
        {
            if (!pq.empty())
            {
                if (pq.top().x == target.x && pq.top().y == target.y)
                {
                    eqlBalls.push(pq.top());
                    pq.pop();
                }
                else
                    break;
            }
            else
                break;
        }

        bool isCombined = false;
        int combinedCount = 1;
        vector<int> di;
        while (!eqlBalls.empty())
        {
            isCombined = true;
            combinedCount++;
            fireBall combine = eqlBalls.front();
            eqlBalls.pop();

            target.matter += combine.matter;
            target.speed += combine.speed;
            di.push_back(combine.direction);
        }

        di.push_back(target.direction);
        if (isCombined)
        {
            target.matter /= 5;
            if(target.matter == 0)
                continue;
            target.speed /= combinedCount;

            bool isTheCross = true;
            bool isOdd = false;
            bool isRight = false;
            for (int i = 0; i < di.size(); i++)
            {
                if (di[i] % 2 == 0)
                {
                    if (isOdd)
                    {
                        isTheCross = false;
                        break;
                    }
                    isRight = true;
                }
                else
                {
                    if (isRight)
                    {
                        isTheCross = false;
                        break;
                    }
                    isOdd = true;
                }
            }

            for (int i = 0; i < 4; i++)
            {
                fireBall newFireBall = fireBall(target.x, target.y, target.matter, target.speed, -1);
                if (isTheCross)
                    newFireBall.direction = i * 2;
                else
                    newFireBall.direction = i * 2 + 1;
                balls.push(newFireBall);
            }
        }
        else
            balls.push(target);
    }
}

void move()
{
    while (!balls.empty())
    {
        fireBall target = balls.front();
        balls.pop();

        int movex, movey;
        switch (target.direction)
        {
        case 0:
            movex = -1;
            movey = 0;
            break;
        case 1:
            movex = -1;
            movey = 1;
            break;
        case 2:
            movex = 0;
            movey = 1;
            break;
        case 3:
            movex = 1;
            movey = 1;
            break;
        case 4:
            movex = 1;
            movey = 0;
            break;
        case 5:
            movex = 1;
            movey = -1;
            break;
        case 6:
            movex = -0;
            movey = -1;
            break;
        case 7:
            movex = -1;
            movey = -1;
            break;
        }

        movex = target.x + target.speed * movex;
        movey = target.y + target.speed * movey;
        if (!checkBound(movex, movey))
        {
            movex %= N;
            movey %= N;
            if (movex <= 0)
                movex += N;
            if (movey <= 0)
                movey += N;
        }

        target.x = movex;
        target.y = movey;
        pq.push(target);
    }
}
void solve()
{
    cin >> N >> M >> K;
    int r, c, m, s, d;

    for (int i = 0; i < M; i++)
    {
        cin >> r >> c >> m >> s >> d;
        fireBall tmp = fireBall(r, c, m, s, d);
        balls.push(tmp);
    }

    for (int i = 0; i < K; i++)
    {
        move();
        happening();
    }

    int result = 0;
    while (!balls.empty())
    {
        result += balls.front().matter;
        balls.pop();
    }
    cout << result;
}

int main()
{

    solve();
}