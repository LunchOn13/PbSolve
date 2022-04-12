#include <iostream>
#include <string>
using namespace std;

int n;

string s[6561];

void dot(int x, int y, int t)
{

    for (int i = x; i < x + t; i++)
    {
        for (int j = y; j < y + t; j++)
        {
            s[i][j] = ' ';
        }
    }

    int target = t / 3;
    int xt[3] = { x - 2*target, x + target , x + 4*target };
    int yt[3] = { y - 2*target , y + target , y + 4*target};

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if(target >= 1)
                dot(xt[i], yt[j], target);
        }
    }
}

void solving()
{
    for (int i = 0; i < n; i++)
    {
        string tmp;
        for (int j = 0; j < n; j++)
        {
            tmp.push_back('*');
        }
        s[i] = tmp;
    }

    dot(n / 3, n / 3, n / 3);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << s[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    solving();
}