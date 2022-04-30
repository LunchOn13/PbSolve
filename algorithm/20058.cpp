#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, q;
int l;
int arr[64][64];

int lenOfArr;

int adjx[4] = {-1, 0, 1, 0};
int adjy[4] = {0, -1, 0, 1};

bool visited[64][64];

bool checkBound(int x, int y)
{
    if (x < 0 || y < 0 || x >= lenOfArr || y >= lenOfArr)
        return false;
    return true;
}

void meltDown()
{
    vector<pair<int, int>> melt;
    for (int i = 0; i < lenOfArr; i++)
    {
        for (int j = 0; j < lenOfArr; j++)
        {
            if(arr[i][j] <1)
                continue;
            int count = 0;
            for (int adj = 0; adj < 4; adj++)
            {
                if (checkBound(i + adjx[adj], j + adjy[adj]))   
                {
                    if (arr[i + adjx[adj]][j + adjy[adj]] > 0)
                        count++;
                }
            }
            if (count < 3)
                melt.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < melt.size(); i++)
    {
        pair<int, int> target = melt[i];
        if (arr[target.first][target.second] > 0)
            arr[target.first][target.second]--;
    }
}

void rotate(int x, int y, int length)
{
    vector<int> save;
    for (int i = x; i < x + length; i++)
    {
        for (int j = y; j < y + length; j++)
        {
            save.push_back(arr[i][j]);
        }
    }

    int count = 0;
    int tmpx = x;
    int tmpy = y + length - 1;
    while (count != save.size())
    {
        arr[tmpx][tmpy] = save[count];

        tmpx++;
        if (tmpx == x + length)
        {
            tmpx = x;
            tmpy--;
        }
        count++;
    }
}

int secondAnswer = 0;
int bestChunk = 0;

void bfs(int x, int y)
{
    queue<pair<int, int>> qq;
    qq.push(make_pair(x, y));

    int chunk = 0;
    int cellCount = 0;
    while (!qq.empty())
    {
        pair<int, int> target = qq.front();
        qq.pop();
        if (arr[target.first][target.second] < 1)
            continue;
        int tmpx = target.first;
        int tmpy = target.second;
        chunk += arr[tmpx][tmpy];
        arr[tmpx][tmpy] = -1;
        cellCount++;

        for (int i = 0; i < 4; i++)
        {
            int tx = tmpx + adjx[i];
            int ty = tmpy + adjy[i];
            if (checkBound(tx, ty))
            {
                if (arr[tx][ty] > 0)
                    qq.push(make_pair(tx, ty));
            }
        }
    }

    if (chunk > bestChunk)
    {
        bestChunk = chunk;
        secondAnswer = cellCount;
    }
}

int dfs(int y, int x){
    visited[y][x]=true;
    int ret=1;
    for(int i=0;i<4;i++){
        int ny=y+adjy[i];
        int nx=x+adjx[i];
        if(checkBound(ny,nx) && !visited[ny][nx] && arr[ny][nx]>0)
            ret+=dfs(ny,nx);
    }
    return ret;
}

// 가장 큰 덩어리 찾기 - DFS
int getBiggest(){
    int ret=0;
    for(int i=0;i<lenOfArr;i++)
        for(int j=0;j<lenOfArr;j++)
            if(arr[i][j]>0 && !visited[i][j])
                ret=max(ret,dfs(i,j));
    return ret;
}


void solve()
{
    cin >> n >> q;

    lenOfArr = 1;
    lenOfArr = lenOfArr << n;
    for (int i = 0; i < lenOfArr; i++)
    {
        for (int j = 0; j < lenOfArr; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l;

        int len = 1;
        len = len << l;

        // l 만큼 띄워서 반복
        if (len != 0)
            for (int x = 0; x < lenOfArr; x += len)
            {
                for (int y = 0; y < lenOfArr; y += len)
                {
                    rotate(x, y, len);
                }
            }
        meltDown();
    }

    int firstResult = 0;
    for (int i = 0; i < lenOfArr; i++)
    {
        for (int j = 0; j < lenOfArr; j++)
        {
            firstResult += arr[i][j];
        }
    }
    cout << firstResult << "\n";

    // bfs
    for (int i = 0; i < lenOfArr; i++)
    {
        for (int j = 0; j < lenOfArr; j++)
        {
            if (arr[i][j] != 0)
                bfs(i, j);
        }
    }
    cout << secondAnswer << "\n";
    //cout << getBiggest() << "\n";
}

int main()
{
    solve();
}