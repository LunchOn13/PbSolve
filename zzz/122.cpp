#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> arr[500000];

void solving()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[i] = make_pair(a, b);
    }

    // 이쪽 부분만 안 잊어버리면된다
    sort(arr, arr + n,greater<pair<int,int>>());

    int cnt = 1;
    int len = arr[0].second;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].second < len)
        {
            cnt++;
            len = arr[i].second;
        }
    }

    cout << cnt << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--)
        solving();
}