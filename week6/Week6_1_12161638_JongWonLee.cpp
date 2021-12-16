#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class counter
{
public:
    int counter_num;
    int whole_time;
    int whole_cost;

    counter()
    {
        this->counter_num = -1;
        this->whole_time = -1;
        this->whole_cost = -1;
    }

    counter(int n)
    {
        this->counter_num = n;
        this->whole_cost = 0;
        this->whole_time = 0;
    }

    bool operator<(const counter c) const
    {
        if (this->whole_time == c.whole_time)
        {
            return this->counter_num > c.counter_num;
        }
        return this->whole_time > c.whole_time;
    }
};

class customer
{
public:
    int using_time = 0;
    int cost = 0;

    customer(int t, int c)
    {
        this->using_time = t;
        this->cost = c;
    }
};

counter arr[20001];

void solving(int n, int m)
{
    priority_queue<counter> counter_queue;

    // 계산대 초기화
    for (int i = 1; i <= n; i++)
    {
        counter_queue.push(counter(i));
    }

    queue<customer> customer_queue;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        customer tmp(a, b);
        customer_queue.push(tmp);
    }

    int now_time = 0;
    while (!customer_queue.empty())
    {
        now_time++;
        // 빈 계산대에 모두 집어넣기
        for (int i = 0; i < n; i++)
        {
            counter target = counter_queue.top();
            counter_queue.pop();
            if (target.whole_time < now_time)
            {
                if (customer_queue.empty())
                {
                    counter_queue.push(target);
                    break;
                }
                customer now_customer = customer_queue.front();
                customer_queue.pop();
                target.whole_time += now_customer.using_time;
                target.whole_cost += now_customer.cost;
                counter_queue.push(target);
            }
            // 더 이상 빈 계산대가 없음
            else
            {
                counter_queue.push(target);
                break;
            }
        }

        counter target = counter_queue.top();
        if (target.whole_time > now_time)
        {
            now_time = target.whole_time;
        }
    }

    for (int i = 0; i < n; i++)
    {
        counter tmp = counter_queue.top();
        arr[tmp.counter_num] = tmp;
        if (now_time < tmp.whole_time)
            now_time = tmp.whole_time;
        counter_queue.pop();
    }

    cout << now_time << "\n";
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i].whole_cost << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    solving(n, m);
}