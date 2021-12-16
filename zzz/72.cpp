#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

struct store
{
    int x, y;

    // 이거는 대충 외우면 될듯?
    bool operator<(const store s) const
    {
        int first = pow(this->x, 2) + pow(this->y, 2);
        int second = pow(s.x, 2) + pow(s.y, 2);

        if (first != second)
            return first < second;

        if (this->x == s.x)
        {

            return this->y < s.y;
        }
        else
        {
            return this->x < s.x;
        }
    }
};

void solving()
{
    int m, n, k;
    cin >> m >> n >> k;

// 이부분 진짜 개지리네
// k 개까지만 보는거고 역순으로 정렬되서 top이 항상 k번째에 있는 애로 유지되게 하면됨
    priority_queue<store> q;
    for (int i = 0; i < m; i++)
    {
        store tmp;
        cin >> tmp.x >> tmp.y;
        q.push(tmp);

        if(q.size() > k)
            q.pop();
    }

    for (int i = 0; i < n; i++)
    {
        store tmp;
        cin >> tmp.x >> tmp.y;
        q.push(tmp);
        q.pop();
        cout << q.top().x << " " << q.top().y << "\n";
    }
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