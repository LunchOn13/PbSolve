#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int house[1000000];
int dis[10000];
int cnt_p =1;

bool judge(int d, int n, int m )
{
    cnt_p = 1;
    int prev = house[0];
    for(int i = 1; i < n; i++)
    {
        if(house[i]-prev >= d)
        {
            cnt_p ++;
            prev = house[i];
        }
    }
    if(cnt_p >= m )
        return true;
    return false;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for(int i = 0; i < n ; i ++)
    {
        cin >> house[i];
    }

    int min_d = 1;
    int max_d = house[n-1] - house[0];
    int result = 0;
    while(min_d <= max_d)
    {
        int half_d = (min_d + max_d) /2;

        if(judge(half_d,n,m))
        {
            result = max(half_d, result);
            min_d = half_d + 1;
        }
        else
            max_d = half_d - 1;
    }
    cout << result ;
}