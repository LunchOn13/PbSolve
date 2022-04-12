#include <iostream>
#include <vector>
using namespace std;

int n, m;
int h;
int line[11][31];
vector<pair<int, int>> choice;
pair<int, int> combi[3];

int result = -1;

bool check()
{
    for(int i=1; i <=n; i++)
    {
        int nowline= i;
        for(int j = 1; j <=h; j++)
        {
            if(line[nowline][j] > 0 && nowline < n)
            {
                nowline++;
            }
            else if(line[nowline-1][j] > 0 && nowline > 1)
            {
                nowline--;
            }
        }
        if(nowline != i)
            return false;
    }
    return true;
}

void combination(int depth, int next, int r)
{
    if(result >=0 && result <4)
        return;
    if (depth == r)
    {
        // 선택완료 그려보기
        for (int i = 0; i < r; i++)
        {
            int a = combi[i].first;
            int b = combi[i].second;
            line[a][b] = 2;
        }

        // 짝수로 있으면 check하고 맞는지 확인
        if(check())
        {
            result = r;
            return;
        }

        // 초기화
        for (int i = 0; i < r; i++)
        {
            int a = combi[i].first;
            int b = combi[i].second;
            line[a][b] = 0;
        }
        return;
    }

    for (int i = next; i < choice.size(); i++)
    {
        combi[depth] = choice[i];
        combination(depth + 1, i + 1, r);
        if(result >=0 && result <4)
            return;
    }
}
void solving()
{
    if(check())
    {
        cout << 0;
        return;
    }

    if(m%2==0)
    {
        combination(0,0,2);
    }
    else
    {
        combination(0,0,1);
        if(result == 1)
        {
            cout << result;
            return;
        }
        combination(0,0,3);
    }

    cout << result;
    return;
}

int main()
{
    cin >> n >> m >> h;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= h; j++)
        {
            line[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        line[b][a] = 1;
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j <= h; j++)
        {

            if (i == 1)
            {
                if (line[i][j] == 0 && line[i + 1][j] == 0)
                    choice.push_back(make_pair(i, j));
            }
            else
            {
                if (line[i][j] == 0 && line[i + 1][j] == 0 && line[i - 1][j] == 0)
                    choice.push_back(make_pair(i, j));
            }
        }
    }
    solving();
}