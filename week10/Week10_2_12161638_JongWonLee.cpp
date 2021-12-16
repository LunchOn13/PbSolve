#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001];
int dp[100001];

int n;

void solving()
{
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }

    int answer = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i] = 1;
        for(int j = 1; j <= i-1; j++)
        {
            if(arr[j] < arr[i])
            {
                dp[i] = max(dp[i], dp[j]+1);
            }
            answer = max(dp[i],answer);
        }
    }
    cout << answer << "\n";
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