#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 초기화 하는거 잊지 말것
// 여기 n은 1부터 시작한다.

struct node{
    int num;
    bool check = false;
    vector<node*> back;
};

node arr[101];

int calc(int x)
{
    queue<int> q;
    q.push(x);

    int cnt = 0;
    while(!q.empty())
    {
        int target = q.front();
        q.pop();

        node tmp = arr[target];
        int size = tmp.back.size();
        for(int i = 0; i < size; i++)
        {
            if(!tmp.back[i]->check)
            {
                tmp.back[i]->check = true;
                q.push(arr[target].back[i]->num);
                cnt++;
            }
        }
    }
    return cnt;
}

void solving()
{
    int n, m;
    cin >> n >> m;

    for(int i = 1; i <=n; i++)
    {
        arr[i].back.clear();
    }

    for(int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].num = a;
        arr[b].num = b;
        arr[a].back.push_back(&arr[b]);
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j= 1; j <= n; j++)
            arr[j].check=false;
        
        cout << calc(i) << " ";
    }
    cout << "\n";
}

// 5 53
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