#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// 그냥 자기보다 가벼운거 하나씩 다 돌면서 찾는다
// 한꺼번에 하려고 하지 마셈
// 포인터를 써야된다;
// 다시 풀어야될듯
struct node
{
    int num;
    bool check;
    vector<node*> back;
};

node arr[101];

int calc(int x)
{
    int result = 0;
    queue<int> q;
    q.push(x);
    while (!q.empty())
    {
        int target = q.front();
        q.pop();

        int size = arr[target].back.size();
        for (int i = 0; i < size; i++)
        {
            vector<node*> tmp = arr[target].back;
            if(!tmp[i]->check)
            {
                q.push(tmp[i]->num);
                result++;
                tmp[i]->check = true;
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
            arr[j].check = false;
        cout << calc(i) << " ";
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    while (T--)
        solving();
}