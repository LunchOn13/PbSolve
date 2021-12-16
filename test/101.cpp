#include <iostream>
#include <queue>
using namespace std;


// 그저 좆밥
int rev(int x)
{
    int result = 0;
    result += x % 10 * 1000;
    x /= 10;
    result += x % 10 * 100;
    x /= 10;
    result += x % 10 * 10;
    x /= 10;
    result += x % 10;
    return result;
}

int arr[10000];

void solving()
{
    for(int i = 0; i < 10000; i++)
        arr[i] = 0;

    int a, b;
    cin >> a >> b;

    queue<int> q;
    q.push(a);

    while (!q.empty())
    {
        int target = q.front();
        q.pop();

        int front = target + 1;
        int back = target - 1;
        int reverse = rev(target);

        if (front == b || back == b || reverse == b)
        {
            cout << arr[target] + 1 << "\n";
            break;
        }

        if (front < 10000)
        {
            q.push(front);
            arr[front] = arr[target] + 1;
        }

        if (back > -1)
        {
            q.push(back);
            arr[back] = arr[target] + 1;
        }
        if (reverse != target)
        {
            q.push(reverse);
            arr[reverse] = arr[target] + 1;
        }
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