#include <iostream>
#include <set>
using namespace std;

// n은 딱 한번만 쓴다 포문 조건문으론 다 m 씀
int arr[500000];
int result[500000];
void solving()
{
    long long n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        result[i] = 0;
    }

    set<int> s;
    for (int i = m - 1; i >= 0; i--)
    {
        s.insert(arr[i]);
        result[i] = n - s.size();
    }

    for (int i = 0; i < m; i++)
    {
        cout << result[i] << "\n";
    }
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