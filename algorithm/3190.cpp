#include <iostream>

using namespace std;

int n;
int map[100][100];
int direcmap[100][100];

int timearr[100];
char direction[100];

// 시계방향
int adjx[4] = {0, -1, 0, 1};
int adjy[4] = {-1, 0, 1, 0};

int headx = 0;
int heady = 0;
int tailx = 0;
int taily = 0;

// 오른쪽으로 꺾으면 +1 왼쪽으로 꺾으면 -1
int direc = 2;

bool check(int x, int y)
{
    if (x >= n || y >= n || y < 0 || x < 0)
        return false;

    if (map[x][y] == 2)
        return false;

    return true;
}

bool move()
{
    if (!check(headx + adjx[direc], heady + adjy[direc]))
        return false;

    direcmap[headx][heady] = direc;
    headx += adjx[direc];
    heady += adjy[direc];
    
    // 사과 있음
    if (map[headx][heady] == 1)
    {
        
    }
    // 사과 없음
    else
    {
        map[tailx][taily] = 0;
        // 다음 꼬리가 어디냐?
        int taildirec = direcmap[tailx][taily];
        direcmap[tailx][taily] = -1;

        tailx += adjx[taildirec];
        taily += adjy[taildirec];
    }
    
    map[headx][heady] = 2;
    return true;
}

int main()
{
    cin >> n;
    int k;
    cin >> k;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            map[i][j] = 0;
            direcmap[i][j] = -1;
        }
    }

    // 사과의 위치
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        map[a-1][b-1] = 1;
    }

    int l;
    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> timearr[i];
        cin >> direction[i];
    }


    int nowtime = 0;
    int tl = 0;
    while(true)
    {
        int thatTime = timearr[tl];
        char thatDirec = direction[tl];

        if(thatTime == nowtime)
        {
            // direc 수정해야함
            if(thatDirec == 'L')
            {
                // 왼쪽
                direc--;
                if(direc < 0)
                    direc =3;
            }
            else
            {
                // 오른쪽
                direc++;
                if(direc > 3)
                    direc = 0;
            }
            tl++;
        }

        if(!move())
            break;

        nowtime++;
    }
    cout << nowtime + 1;
}