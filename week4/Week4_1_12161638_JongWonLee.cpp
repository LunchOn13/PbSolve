#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

void solving()
{
    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int gcd = abs(a - b);
    int target = a % gcd;

    cout << gcd << " ";

    int min = INT32_MAX;
    int tmp;

    // 내려가보기
    if (a >= 1 + target  && b >= target + 1)
    {
        min = target * y;
    }

    // 올라가보기
    tmp = (gcd - target) * x;
    if (tmp < min)
        min = tmp;

    cout << min << " \n";
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