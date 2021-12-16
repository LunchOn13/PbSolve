#include <iostream>
#include <vector>
#include <set>
using namespace std;

int message[500000];
int resultMessage[500000];

void solving()
{
    int n, m;
    cin >> n >> m;

    set<int> user;
    for(int i = 0; i < m; i ++)
    {
        cin >> message[i];
    }

    for(int i = m-1; i >=0; i--)
    {
        user.insert(message[i]);
        resultMessage[i] = n - user.size();
    }

    for(int i = 0; i < m; i++)
    {
        cout << resultMessage[i] << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for(int i = 0; i < t; i++)
    {
        solving();
    }
}