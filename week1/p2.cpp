#include <iostream>
#include <stack>
using namespace std;

stack<int> real;
stack<int> big;
stack<int> small;

void unstack()
{
    if(real.empty())
        return;
    int target = real.top();
    real.pop();

    if (big.top() == target)
        big.pop();
    if (small.top() == target)
        small.pop();
}

void onstack()
{
    int n;
    cin >> n;
    real.push(n);

    if (big.empty())
        big.push(n);
    else if (big.top() <= n)
        big.push(n);

    if (small.empty())
        small.push(n);
    else if (small.top() >= n)
        small.push(n);

    cout << small.top() << " " << big.top() << "\n";
}

void solving()
{
    // 초기화
    while (!real.empty())
        real.pop();
    while (!big.empty())
        big.pop();
    while (!small.empty())
        small.pop();

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        // 쌓기
        if (a == 1)
            onstack();
        // 빼기
        else
            unstack();
    }
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solving();
    }
}