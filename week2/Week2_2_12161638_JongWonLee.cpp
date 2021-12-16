#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solving()
{
    int n;
    cin >> n;

    long long result = 0;

    vector<pair<int, pair<int, int>>> list;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        pair<int, int> tmp = make_pair(a, b);
        list.push_back(make_pair(a + b, tmp));
    }

    sort(list.begin(), list.end());

    int cnt = 0;
    while (!list.empty())
    {

        // inha
        if (cnt % 2 == 0)
        {
            result += list.back().second.first;
        }
        // bi
        else
        {
            result -= list.back().second.second;
        }
        list.pop_back();
        cnt++;
    }

    return result;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << solving() << "\n";
    }
}