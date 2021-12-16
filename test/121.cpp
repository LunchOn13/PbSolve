#include <iostream>
#include <limits.h>

using namespace std;

// 좆밥
// 헷갈리지만 않으면된다

int arr[5050];
int result[5050];

int goright(int x, int row)
{
    return x + row;
}

int goleft(int x, int row)
{
    return goright(x, row) - 1;
}

void solving()
{
    int n;
    cin >> n;

    int index = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cin >> arr[index];
            result[index] = INT_MAX;
            index++;
        }
    }

    index = 0;
    result[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int right = goright(index, i + 1);
            int left = goleft(index, i + 1);

            int now = result[index];

            result[right] = arr[right] + now < result[right] ? arr[right] + now : result[right];
            result[left] = arr[left] + now < result[left] ? arr[left] + now : result[left];

            index++;
        }
    }

    int min = INT_MAX;
    int len = n * (n + 1) / 2;
    for (int i = len - 1; i >= len - n; i--)
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