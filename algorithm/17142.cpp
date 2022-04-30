#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n;
int m;
int arr[50][50];
int tmpArr[50][50];
int unactiveCount = 0;
pair<int, int> unactiveVirus[10];

vector<pair<int, int>> activeVirus;

int result = 999999;

bool checkBound(int x, int y)
{
    if (x < 0 || y < 0 || x >= n || y >= n)
        return false;
    if (tmpArr[x][y] == 1 || tmpArr[x][y] == 2)
        return false;
    return true;
}

void spreadOut()
{
    queue<pair<int, int>> targetVirus;
    for(int i = 0; i < activeVirus.size(); i++)
    {
        targetVirus.push(activeVirus[i]);
    }

    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tmpArr[i][j] = arr[i][j];
        }
    }
    queue<pair<int, int>> newTarget;

    int count = -1;
    bool isOnlyUnactiveVirus = true;
    int onlyUnVicount = 0;
    do
    {
        // cout << "--------------\n";
        // for(int i = 0 ; i < n ; i++)
        // {
        //     for(int j = 0; j < n; j++)
        //     {
        //         cout << tmpArr[i][j] << " ";
        //     }
        //     cout << "\n";
        // }

        while (!newTarget.empty())
        {
            targetVirus.push(newTarget.front());
            newTarget.pop();
        }
        isOnlyUnactiveVirus = true;
        while (!targetVirus.empty())
        {
            pair<int, int> target = targetVirus.front();
            targetVirus.pop();
            int x = target.first;
            int y = target.second;

            // 부딪히는 경우 삭제
            if (tmpArr[x][y] == 2)
                continue;

            if (tmpArr[x][y] != 3)
            {
                isOnlyUnactiveVirus = false;
                onlyUnVicount = 0;
            }
            tmpArr[x][y] = 2;

            if (checkBound(x + 1, y))
                newTarget.push(make_pair(x + 1, y));
            if (checkBound(x, y + 1))
                newTarget.push(make_pair(x, y + 1));
            if (checkBound(x - 1, y))
                newTarget.push(make_pair(x - 1, y));
            if (checkBound(x, y - 1))
                newTarget.push(make_pair(x, y - 1));
        }
        if(isOnlyUnactiveVirus)
            onlyUnVicount++;
        count++;
    } while (!newTarget.empty());

    if (isOnlyUnactiveVirus)
        count-=onlyUnVicount;

    for (int i = 0; i < n; i++)
    {
        bool check = false;
        for (int j = 0; j < n; j++)
        {
            if (tmpArr[i][j] == 0)
            {
                count = 999999;
                check = true;
                break;
            }
        }
        if (check)
            break;
    }
    result = count < result ? count : result;
}

void select(int times, int start = 0)
{
    if (times == 0)
    {
        // 선택 종료
        // 바이러스 퍼트리기 시작
        spreadOut();
        return;
    }

    for (int i = start; i < unactiveCount; i++)
    {
        pair<int, int> tmp = unactiveVirus[i];

        if (tmp.first != -1 && tmp.second != -1)
        {
            unactiveVirus[i] = make_pair(-1, -1);
            activeVirus.push_back(tmp);
            select(times - 1, i);
            activeVirus.pop_back();
            unactiveVirus[i] = tmp;
        }
    }
}

void solve()
{
    cin >> n >> m;

    bool isFool = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int tmp;
            cin >> tmp;
            if (tmp == 0)
                isFool = false;
            if (tmp == 2)
            {
                unactiveVirus[unactiveCount++] = make_pair(i, j);
                arr[i][j] = 3;
            }
            else
                arr[i][j] = tmp;
        }
    }
    if(isFool){
        result = 0;
        return;
    }
    else
        select(m);
}

int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(0);
    solve();
    if (result == 999999)
        cout << -1;
    else
        cout << result;
}