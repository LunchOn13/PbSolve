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

    sort(arr, arr + n, greater<pair<int, int>>());

    int min = 500001;
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (min > arr[i].second)
        {
            cnt++;
            min = arr[i].second;
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