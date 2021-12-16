#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct cust
{
public:
    int time;
    int cost;
};

struct desk
{
public:
    int time;
    int wholecost;
    int number;

    bool operator<( desk c) const
    {
        if (this->time == c.time)
            return this->number > c.number;

        return this->time > c.time;
    }
};

void solving(int n, int m)
{

    queue<cust> arr;
    for (int i = 0; i < m; i++)
    {
        cust tmp;
        int a, b;
        cin >> a;
        cin >> b;
        tmp.time = a;
        tmp.cost = b;
        arr.push(tmp);
    }

    priority_queue<desk> arr_desk;
    for (int i = 0; i < n; i++)
    {
        desk tmp;
        tmp.time = 0;
        tmp.wholecost = 0;
        tmp.number = i;
        arr_desk.push(tmp);
    }

    int result_time = 0;
    while (!arr.empty())
    {
        for (int i = 0; i < n; i++)
        {

            desk tmp = arr_desk.top();
            arr_desk.pop();
            if (tmp.time > result_time)
                result_time = tmp.time;

            cust ctmp = arr.front();
            arr.pop();

            tmp.time += ctmp.time;
            tmp.wholecost += ctmp.cost;

            arr_desk.push(tmp);

            if (arr.empty())
                break;
        }
    }

    // 정리
    vector<desk> result;
    for (int i = 0; i < n; i++)
    {
        desk tmp;
        result.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        desk tmp = arr_desk.top();
        arr_desk.pop();

        result[tmp.number] = tmp;
        if(result_time < tmp.time)
            result_time = tmp.time;
    }

    cout << result_time << "\n";
    for(int i = 0; i < n; i++){
        cout << result[i].wholecost << "\n";
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
