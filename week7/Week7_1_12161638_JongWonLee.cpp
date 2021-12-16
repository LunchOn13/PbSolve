#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class linkedlist
{
public:
    int num;
    bool check;
    vector<linkedlist *> back;

    bool checked()
    {
        return check;
    }
};

linkedlist arr[101];

int calc(int num)
{
    int result = 0;
    queue<int> q;
    q.push(num);
    while (!q.empty())
    {
        int target = q.front();
        q.pop();

        int sz = arr[target].back.size();
        if (sz != 0)
        {
            for (int i = 0; i < sz; i++)
            {
                vector<linkedlist *> tmp = arr[target].back;
                if (!tmp[i]->checked())
                {
                    q.push(tmp[i]->num);
                    result++;
                    tmp[i]->check = true;
                }
            }
        }
    }
    return result;
}

void solving()
{
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        arr[i].num = i;
        arr[i].check = false;
        arr[i].back.clear();
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        arr[a].back.push_back(&arr[b]);
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            arr[j].check = false;
        }

        cout << calc(i) << " ";
    }
    cout << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(0);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        solving();
    }
}