#include <iostream>
#include <vector>
using namespace std;

int n; // 4 ~ 20 n % 2 == 0

int arr[21][21];

bool selected[21];

int minResult = 99999;

void calc()
{
    // 1팀
    int first = 0;
    vector<int> target;
    for(int i = 1; i <= n; i++)
    {
        if(selected[i] == true)
            target.push_back(i);
    }

    for(int i = 0; i < target.size(); i++)
    {
        for(int j = i; j < target.size(); j++)
        {
            first += arr[target[i]][target[j]];
        }
    }

    // 2팀
    int second = 0;
    target.clear();
    for(int i = 1; i <= n; i++)
    {
        if(selected[i] == false)
            target.push_back(i);
    }

    for(int i = 0; i < target.size(); i++)
    {
        for(int j = i; j < target.size(); j++)
        {
            second += arr[target[i]][target[j]];
        }
    }

    int result = first - second;
    result = result < 0 ? result*-1 : result;

    if ( minResult > result)
        minResult = result;
}


void combihalf(int start, int count)
{
    if (count == 0)
    {
        // combination done
        calc();
        return;
    }

    for (int i = start; i <=n; i++)
    {
        if (count == n / 2 && i > 1)
            break;

        if (selected[i] == false)
        {
            selected[i] = true;
            combihalf(i + 1, count - 1);
            selected[i] = false;
        }
    }
}

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int tmp;
            cin >> tmp;
            if (i > j)
                arr[j][i] += tmp;
            else
                arr[i][j] += tmp;
        }
    }

    // 2n C n
    combihalf(1,n/2);
    cout << minResult;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}