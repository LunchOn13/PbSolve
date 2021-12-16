#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        int n;
        cin >> n;

        vector<int> stack;

        int q;
        int min = 1001;
        int max = -1;
        for (int k = 0; k < n; k++)
        {
            cin >> q;
            if (q == 1)
            {
                int tmp;
                cin >> tmp;
                if (stack.empty())
                {
                    min = tmp;
                    max = tmp;
                }
                else
                {
                    if (tmp > max)
                        max = tmp;
                    if (tmp < min)
                        min = tmp;
                }
                stack.push_back(tmp);

                cout << min << " " << max << "\n";
            }
            else
            {
                if (stack.empty())
                {
                    min = 1001;
                    max = -1;
                    continue;
                }
                int tmp = stack.back();
                stack.pop_back();
                if (max == tmp)
                {
                    max = *max_element(stack.begin(), stack.end());
                }
                if (min == tmp)
                {
                    min = *min_element(stack.begin(), stack.end());
                }

                if (stack.empty())
                {
                    min = 1001;
                    max = -1;
                    continue;
                }
            }
        }
    }
}