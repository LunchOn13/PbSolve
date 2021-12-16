#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

int arr[5050];
int result[5050];

int goDownRight(int x, int row)
{
    return x + row;
}

int goDownLeft(int x, int row)
{
    return goDownRight(x, row) - 1;
}

void solving()
{
    int n;
    cin >> n;

    int len = n * (n + 1) / 2;
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
        result[i] = INT_MAX;
    }

    result[0] = arr[0];
    // 줄 간의 아이디어만 안 놓치면 될거같음
    int index = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j <= i; j++)
        {   
            // i는 현재 줄 num -1
            int now = result[index];
            int right = goDownRight(index, i+2);
            int left = goDownLeft(index, i+2);

            result[right] = min(now + arr[right], result[right]);
            result[left] = min(now + arr[left], result[left]);
            index++;
        }
    }
    
    int min = INT_MAX;
    for(int i = len-1; i >= len-n; i--)
    {
        min = result[i] < min ? result[i] : min;
    }

    cout << min << "\n";
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