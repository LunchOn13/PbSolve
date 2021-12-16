#include <iostream>
#include <algorithm>
using namespace std;

int arr[500];
int result[500];
// 잘 외웁시당~
// 이것보ㅏ야됨 ㅋ

void solving()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // 이부분 잘 볼 것
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        result[i] = 1;
        for (int j = 0; j < i; j++)
        {
            if (arr[j] < arr[i])
                result[i] = max(result[i], result[j] + 1);

            answer = max(answer, result[i]);
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
    while (t--)
        solving();
}