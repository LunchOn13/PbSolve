#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class cord
{
public:
    int x;
    int y;
    double length;

    cord()
    {
        this->x = 0;
        this->y = 0;
        this->length = length;
    }
    cord(int x, int y)
    {
        this->x = x;
        this->y = y;
        this->length = pow(x, 2) + pow(y, 2);
    }

    void clear()
    {
        this->x = 0;
        this->y = 0;
        this->length = 0;
    }

    bool operator<(const cord c)
    {
        if(this->length == c.length)
        {
            if(this->x == c.x)
                return this->y > c.y;
            return this->x > c.x;
        }
        return this->length > c.length;
    }
};

cord oldBg[400000];
cord newBg[200000];

void solving()
{
    int m, n, k;
    cin >> m >> n >> k;

    for(int i = 0; i <m+n;i++)
    {
        oldBg[i].clear();
    }
    for(int i = 0; i < n; i++)
    {
        newBg[i].clear();
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        oldBg[i] = cord(a, b);
    }

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        newBg[i] = cord(a, b);
    }

    cout << "result \n";
    int day = 1;
    int lenthonk = 0;
    sort(oldBg,oldBg+m);
    lenthonk = oldBg[m-k].length;
    for (int i = 0; i < n; i++)
    {
        oldBg[m-1+day] = newBg[i];
        sort(oldBg + m + day -k, oldBg + m + day);
        day++;

        cout << oldBg[m - k + 1].x << " " << oldBg[m - k + 1].y << "\n";
    }
}
// k 개의 햄버거집만 관리해서
// max heap을 사용한다
// priority queue 사용

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