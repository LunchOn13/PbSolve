#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


vector<pair<int,int>> arr;

void solving()
{
    int n;
    cin >> n;

    arr.clear();
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        arr.push_back(make_pair(a,b));
    }

    sort(arr.begin(), arr.end(),greater<pair<int,int>>());

    int distance = arr[0].second;
    int cnt = 1;
    for(int i = 0; i <n; i++)
    {
        if(arr[i].second < distance)
        {
            distance = arr[i].second;
            cnt++;
        }
    }

    cout << cnt << "\n";
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