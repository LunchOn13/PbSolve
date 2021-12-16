#include <iostream>
#include <queue>
using namespace std;

int arr[10000] = {
    0,
};

// 그냥 이렇게 하는 방식이 있고
// 미리 갈 수 있는 곳을 다 정해놓고 탐색만 하는 방법도 잇따
// 탐색만 하는게 더 빠르긴함

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

void solving()
{
    for(int i = 0; i< 10000; i++)
        arr[i] = 0;
    int a, b;
    cin >> a >> b;

    queue<int> q;
    q.push(a);
    arr[a] = 1;

    while (!q.empty())
    {
        int target = q.front();
        q.pop();

        int front = target - 1;
        int back = target + 1;
        int reverse = rev(target);

        if (front >= 0)
        {
            if (front == b)
            {
                cout << arr[target] << "\n";
                return;
            }
            if (arr[front] < arr[target])
            {
                arr[front] = arr[target] + 1;
                q.push(front);
            }
        }

        if (back <= 9999)
        {
            if (back == b)
            {
                cout << arr[target] << "\n";
                return;
            }
            if (arr[back] < arr[target])
            {
                arr[back] = arr[target] + 1;
                q.push(back);
            }
        }

        if (reverse == b)
        {
            cout << arr[target] << "\n";
            return;
        }
        if (arr[reverse] < arr[target])
        {
            arr[reverse] = arr[target] + 1;
            q.push(reverse);
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