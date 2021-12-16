#include <iostream>

using namespace std;

struct dot
{
public:
    int x;
    int y;

    dot(){};
    dot(int a, int b)
    {
        this->x = x;
        this->y = y;
    }

    bool operator< (const dot t)
    {
        if(this-> x == t.x)
            return this->y < t.y;
        
        return this->x < t.x;
    }
};

int ccw(dot a, dot b, dot c)
{
    // x1 x2 x3 x1
    // y1 y2 y3 y1
    int first = a.x * b.y + b.x * c.y + c.x * a.y;
    int second = b.x * a.y + c.x * b.y + a.x * c.y;

    int result = first - second;
    if( result < 0)
        return -1;
    else if (result == 0)
        return 0;
    else 
        return 1;
}

void
solving()
{
    dot arr[4];

    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i].x;
        cin >> arr[i].y;
    }
    
    if(arr[1] < arr[0])
        swap(arr[0], arr[1]);

    if(arr[3] < arr[2])
        swap(arr[2], arr[3]);

    // 0 a 1 b 2 c 3 d
    int abc = ccw(arr[0], arr[1], arr[2]);
    int abd = ccw(arr[0], arr[1], arr[3]);
    int cda = ccw(arr[2], arr[3], arr[0]);
    int cdb = ccw(arr[2], arr[3], arr[1]);


    if( abc == 0 && abd == 0)
    {
        // 두 선분이 일직선 상에 존재함

        int a, b, c, d;
        a = arr[0].x;
        b = arr[1].x;
        c= arr[2].x;
        d = arr[3].x;

        if((a < c && b < c) || (a > d && b > d))
            cout << 1 << "\n";
        else if((a<c && b==c) || (b > d && a == d))
            cout << 2 << "\n";
        else if ((a<c && c<b && b < d ) || (c<a && a < d && d<b))
            cout << 3 << "\n";
        else 
            cout << 4 << "\n";
    }
    else if(abc * abd <= 0 && cda*cdb <=0)
        cout << 2 << "\n";
    else
        cout << 1 << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solving();
    }
}