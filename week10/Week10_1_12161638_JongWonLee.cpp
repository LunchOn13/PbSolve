#include <iostream>
#include <queue>
using namespace std;

struct room
{
    int bucket[3] = {-1,-1,-1};
};

room arr[10001];
int check[10001];

int rev(int a)
{
    int result = 0;

    result += a % 10 * 1000;
    a /= 10;

    result += a % 10 * 100;
    a /= 10;

    result += a % 10 * 10;
    a /= 10;

    result += a % 10;

    return result;
}

void solving()
{
    int a, b;
    cin >> a >> b;

    for (int i = 0; i <= 9999; i++)
    {
        check[i] = 10000;
    }

    queue<int> visitRoom;
    visitRoom.push(a);
    check[a] = 0;

   while(visitRoom.empty() == false)
   {
       int now = visitRoom.front();
       visitRoom.pop();

        room tmp = arr[now];
        for(int i = 0; i < 3; i++)
        {
            if(tmp.bucket[i] != -1)
            {
                if(check[tmp.bucket[i]] > check[now] + 1)
                {
                    visitRoom.push(tmp.bucket[i]);
                    check[tmp.bucket[i]] = check[now]+1;
                }
            }
        }
   }
   cout << check[b] << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;

    for (int i = 0; i <= 9999; i++)
    {
        if (i > 0)
            arr[i].bucket[0] = i - 1;
        if (i < 9999)
            arr[i].bucket[1] = i + 1;

        int re = rev(i);
        if (re != i)
            arr[i].bucket[2] = rev(i);
    }

    for (int i = 0; i < t; i++)
    {
        solving();
    }

    return 0;
}