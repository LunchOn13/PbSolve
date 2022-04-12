#include <iostream>

using namespace std;

int start = 1;
int last;
int n, k;

int result = 0 ;

struct node
{
    int num;
    int cnt;
    node *next;
    node *back;
    bool isRobot = false;
};

node arr[201];

bool rotate()
{
    result++;
    // 1단계
    start--;
    if (start <= 0)
        start = 2 * n;
    last--;
    if (last <= 0)
        last = 2 * n;

    if(arr[last].isRobot)
        arr[last].isRobot = false;

    // 2단계
    node *tmp = &arr[last];
    while(tmp->num != arr[start].num)
    {
        // 로봇이 있고
        if(tmp->isRobot)
        {
            // 다음 벨트에 로봇이 없고 cnt가 1이상이면
            if(tmp->next->isRobot == false && tmp->next->cnt >=1)
            {
                tmp->isRobot = false;
                tmp->next->cnt--;
                tmp->next->isRobot = true;
            }
        }
        tmp = tmp->back;
    }
    arr[last].isRobot = false;

    //3단계
    if(arr[start].cnt > 0)
    {
        arr[start].cnt--;
        arr[start].isRobot = true;
    }

    //4단계
    int b = 0;
    for(int i =1 ; i <=2 * n; i++)
    {
        if(arr[i].cnt <=0)
        {
            b++;
            if( b >= k)
                return false;
        }
    }

    return true;
}

void solving()
{
    cin >> n >> k;

    last =n;
    for (int i = 1; i <= 2 * n; i++)
    {
        int a;
        cin >> a;
        node tmp;
        tmp.num = i;
        tmp.cnt = a;
        arr[i] = tmp;
    }

    for (int i = 1; i < 2 * n; i++)
    {
        arr[i].next = &arr[i + 1];
    }
    arr[2 * n].next = &arr[1];


    for(int i = 2*n; i> 1; i--)
    {
        arr[i].back = &arr[i-1];
    }
    arr[1].back = &arr[2*n];

    while(rotate())
    {

    }

    cout << result << "\n";
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solving();
}