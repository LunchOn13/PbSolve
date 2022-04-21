#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> arr;

void solve()
{
    cin >> n;
    int a;
    for(int i = 0;  i < n; i++)
    {
        cin >> a;
        arr.push_back(a);
    }
    int b, c;
    cin >> b >> c;
    long long count = 0;
    for( int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= 0 )
            continue;
        arr[i] -= b;
        count++;
        if (arr[i] <= 0 )
            continue;
        count += arr[i] / c;
        if (arr[i] % c > 0)
            count++;
    }

    cout << count;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solve();
}