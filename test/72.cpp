#include <iostream>
#include <queue>
#include<cmath>
using namespace std;

// m n k 순이다 ㅋㅋ
// operator만 잘 만들고 pq만 잘 만들어 쓰면 끝임

struct store{
    int x, y;
    
    bool operator<(const store s) const{
        int first = pow(this->x,2) + pow(this->y,2);
        int second = pow(s.x,2) + pow(s.y,2);

        if(first != second)
            return first < second;
        
        if( this->x != s.x)
            return this->y < s.y;
        else
            return this->x < s.x;
    }
};

void solving()
{
    int n, m, k;
    cin >> m >> n >> k;

    priority_queue<store> q;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        q.push(store{x, y});
        if(q.size() > k)
            q.pop();
    }

    for(int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        q.push(store{x,y});
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
    while(t--)
        solving();
}