#include <iostream>
#include <string.h>
using namespace std;

int hz[5000];
int target[5000];

void solving()
{
    int n;
    cin >> n;

    memset(target, 0, sizeof(target));

    for (int i = 0; i < n; i++)
    {
        cin >> hz[i];
    }

    // 주기로 추정되는 것 찾기
    int target_len = 1;
    int start = hz[0];
    target[0] = start;
    bool check = true;
    do
    {
        while (hz[target_len] != start)
        {
            if(target_len >= n)
                break;
            target[target_len] = hz[target_len];
            target_len++;
        }

        if(target_len>= n)
        {
            check = true;
            break;
        }
        

        // 주기가 맞는지 체크
        check = true;
        for (int i = target_len; i < n;)
        {
            for (int j = 0; j < target_len; j++)
            {
                if(i >= n)
                    break;
                if (hz[i] != target[j])
                {
                    check = false;
                    target[target_len] = hz[target_len];
                    target_len++;
                    break;
                }
                i++;
            }
            if (!check)
                break;
        }
    } while (!check);

    // end
    if (check)
    {
        for (int i = 0; i < target_len; i++)
        {
            cout << target[i] << " ";
        }
        cout << "\n";
    }
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