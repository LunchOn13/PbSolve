#include <iostream>
#include <vector>
using namespace std;

void solving()
{
    int n;
    cin >> n;

    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    int length = arr.size();

    vector<int> target;
    int first = arr[0];
    target.push_back(first);
    int targetIter = 1;

    bool right = false;
    while (!right)
    {
        // taget 수정
        while (arr[targetIter] != first)
        {
            if (targetIter >= length)
                break;
            target.push_back(arr[targetIter]);
            targetIter++;
        }

        // taget 체크
        right = true;
        for (int i = targetIter; i < length;)
        {
            for (int j = 0; j < targetIter; j++)
            {
                if (target[j] != arr[i++])
                {
                    right = false;
                    break;
                }
                if (i >= length)
                    break;
            }
            if (right == false)
            {
                // target 수정하고 다시 찾기
                target.push_back(arr[targetIter]);
                targetIter++;
                break;
            }
        }
    }

    for (int i = 0; i < target.size(); i++)
    {
        cout << target[i] << " ";
    }
    cout << "\n";
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