#include <iostream>

using namespace std;

int house[1000000];

int n, m;

int find(int mid)
{
    int cnt = 1;
    int before = 0;
    for(int i = 1; i < n; i++)
    {
        if(mid <= (house[i] - house[before]))
        {
            cnt++;
            before = i;
        }
    }

    return cnt;
}

void solving()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> house[i];
    }

    int min = 1;
    int max = house[n-1] - house[0];
    int result = (min + max) / 2;
    while (result > min && result < max)
    {
        int tmp = find(result);
        if (tmp >= m)
            min = result;
        else
            max = result;
        result = (min + max) / 2;
    }
    cout << result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solving();
}