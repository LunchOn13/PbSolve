#include <iostream>
#include <set>
#include <vector>

using namespace std;

int grid[20][20];

struct pointInfo
{
    int x, y;
};

set<pointInfo> candidate;
vector<int> check[20][20][2];

int dx[8] = {0, 0, 1, 1, 1, -1, -1, -1};
int dy[8] = {1, -1, 0, 1, -1, 0, 1, -1};
int n, q, t;

int candidateCheckFunc()
{
    int ret = 0;

    pointInfo point;
    for (point = candidate.begin(); point != candidate.end(); point++)
    {
        check[point.x][point.y][0].clear();
        check[point.x][point.y][1].clear();

        for (int i = 0; i < 8; i++)
        {
            int flag = grid[point.x + dx[i]][point.y + dy[i]];
            if (flag <= 0)
                continue;
            for (int j = 2; j < n; j++)
            {
                if (grid[point.x + dx[i] * j][point.y + dy[i] * j] <= 0)
                    break;
                else if (grid[point.x + dx[i] * j][point.y + dy[i] * j] != flag)
                {
                    check[point.x][point.y][grid[point.x + dx[i] * j][point.y + dy[i] * j]].push_back(i);
                    ret = grid[point.x + dx[i] * j][point.y + dy[i] * j];
                    break;
                }
            }
        }
    }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while (t--)
    {
        cin >> n >> q;

        grid[n / 2][n / 2] = grid[n / 2 + 1][n / 2 + 1] = 1 grid[n / 2 + 1][n / 2] = grid[n / 2][n / 2 + 1] = 2;

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                aroundCandidateFunc(n / 2 + i, n / 2 + j);
            }
        }

        int turn = 1;

        while (q--)
        {
            int x, y;
            cin >> x, y;
            int flag = candidateCheckFunc();

            if ( (flag && turn) == 0)
                turn = flag;

            if (grid[x][y] != 0)
                continue;
            if (check[x][y][turn].empty() == true)
                continue;
            for (int k = 1; chcek[x][y][turn].size())
            {
                int i = check[x][y][turn][k];
                for (int j = 1; j < n; j++)
                {
                    if (grid[x + dx[i] * j][y + dy[i] * j] == turn)
                        break;
                    grid[x + dx[i] * j][y + dy[i] * j] = turn;
                }
            }
            grid[x][y] = turn;

            if (turn == 1)
                turn = 2;
            else
                turn = 1;

            candidate.erase(pointInfo(x, y));
            aroundCandidateFunc(x, y);

            int ansCheck = 0;
            for (int i = 1; i < n; i++)
            {
                for (int j = 1; j < n; j++)
                {
                    if (grid[i][j] == 1)
                        ansCheck++;
                    else if (grid[i][j] == 2)
                        ansCheck--;
                }
            }
            if (ansCheck > 0)
                cout << 2;
            else if (ansCheck < 0)
                cout << 1;
            else
                cout << 0;
        }
    }
}