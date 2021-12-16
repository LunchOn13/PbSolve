#include <iostream>

using namespace std;

void solving()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    // 올릴때 x
    // 내릴때 y

    int gcd = abs(a - b);
    if (gcd == 0)
        gcd = a;
    int mincost = -1;

    int tmpcost = 0;
    // 올라가기
    int tmpa = a;
    int tmpb = b;
    for (int i = 0; i <= gcd; i++)
    {
        if (tmpa % gcd == 0 && tmpb % gcd == 0)
        {
            break;
        }
        tmpa++;
        tmpb++;
        tmpcost += x;
    }
    mincost = tmpcost;

    tmpcost = 0;
    tmpa = a;
    tmpb = b;
    // 내려가기
    for (int i = 0; i <= gcd; i++)
    {
        if (tmpa % gcd == 0 && tmpb % gcd == 0)
        {
            break;
        }

        if(tmpa <= 1 || tmpb <= 1)
        {
            tmpcost = -1;
            break;
        }

        tmpa--;
        tmpb--;
        tmpcost += y;
    }
    if (mincost > tmpcost && tmpcost >= 0)
        mincost = tmpcost;

    cout << gcd << " " << mincost << "\n";
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