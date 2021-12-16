#include <iostream>
#include <algorithm>
using namespace std;

int arr[500];
int result[500];
void solving()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        result[i] = 0;
    }

    // dp 인데...
    // i 까지 다시 돌면서  모르겟당
    // 이건 외워야된다
    int answer = 0;
    for(int i = 0; i < n; i++)
    {
        result[i] = 1;
        for(int j = 0; j < i; j++)
        {
            if(arr[j]<arr[i])
                result[i] = max(result[i],result[j]+1);
            answer = max(result[i], answer);
        }
    }
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--)
        solving();
}