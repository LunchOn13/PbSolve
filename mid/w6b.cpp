#include <iostream>
#include <queue>

using namespace std;

// 0 이동가능
// 1 이동불가
// 2 검사 , 소총수
// 3 안전지대
int map[1001][1001];
int n;

const int step[] = {-1, 0, 1};

bool checkBound(int x, int y)
{
    if (x < 1)
        return false;
    if (x > n)
        return false;
    if (y < 1)
        return false;
    if (y > n)
        return false;

    return true;
}

struct dot{
    public:
        int x;
        int y;
        int length = 0;
    dot(int a, int b)
    {
        this->x = a;
        this->y = b;
        this->length = 0;
    }
};

int finding(int startx, int starty)
{
    queue<dot> q;
    q.push(dot(startx, starty));
    
    while(!q.empty())
    {
        dot target = q.front();
        q.pop();
        
        if(map[target.x][target.y] == 3)
            return target.length;

        for(int i = 0; i < 3; i ++)
        {
            for(int j = 0; j < 3; j++)
            {
                int tx = target.x + step[i];
                int ty = target.y + step[j];
                if(checkBound(tx,ty) && map[tx][ty] != 1)
                {
                    dot tmp(tx,ty);
                    tmp.length = target.length +1;
                    q.push(tmp);
                    if(map[tx][ty] == 0)
                        map[tx][ty] = 1;
                }
            }
        }
    }
    return 0;
}

void solving()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = 0;
        }
    }

    int inx, iny, safex, safey;
    int sx, sy, gx, gy;
    cin >> inx >> iny >> safex >> safey;
    cin >> sx >> sy >> gx >> gy;

    // 검사
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int tx = sx + step[i];
            int ty = sy + step[j];
            if(checkBound(tx,ty))
                map[tx][ty] = 1;
        }
    }
    map[sx][sy] = 2;

    // 소총수
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            int tx = gx + step[i];
            int ty = gy + step[j];

            while(checkBound(tx,ty))
            {   
                if(tx == gx && ty == gy)
                    break;
                if(map[tx][ty] == 2)
                    break;
                map[tx][ty] = 1;
                tx += step[i];
                ty += step[j];
            }

        }
    }
    map[gx][gy] = 2;

    // 안전지역
    map[safex][safey] = 3;

    cout << finding(inx,iny) << "\n";
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