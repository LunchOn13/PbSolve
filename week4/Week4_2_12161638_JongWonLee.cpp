#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// x가 작은게 먼저오도록
void swap(int *x1, int *y1, int *x2, int *y2)
{
    if (*x1 > *x2)
    {
        int tmp = *x1;
        *x1 = *x2;
        *x2 = tmp;
        tmp = *y1;
        *y1 = *y2;
        *y2 = tmp;
    }
    else if (*x1 == *x2)
    {
        if (*y1 > *y2)
        {
            int tmp = *y1;
            *y1 = *y2;
            *y2 = tmp;
        }
    }
}

double inclination(int x1, int y1, int x2, int y2)
{
    if (x2 == x1)
        return NAN;
    return (y2 - y1) / (x2 - x1);
}

string judge(int x1, int x2, int x3, int x4)
{
    // 관계 1
    if((x1 != x3) && (x1!=x4) && (x2!=x3) && (x2 != x4)){
        if (((x1 > x3) == (x1 > x4)) && ((x2 > x3) == (x2 > x4)) && ((x1 > x3) == (x2 > x3)) && ((x1 > x4) == (x2 > x4)))
        {
            return "1\n";
        }
    }

    // 관계 2
    if (x1 == x4 || x2 == x3)
        return "2\n";

    // 관계 3
    if ((((x1 > x3) && (x1 < x4)) || ((x2 > x3) && (x2 < x4))) && (x1 != x3) && (x2 != x4))
    {
        return "3\n";
    }
    // 1 1 1 3
    // 1 0 1 4 에러

    return "4\n";
}

void solving()
{
    int x1, y1, x2, y2;
    int x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> x3 >> y3 >> x4 >> y4;

    swap(&x1, &y1, &x2, &y2);
    swap(&x3, &y3, &x4, &y4);

    double ic1 = inclination(x1, y1, x2, y2);
    double ic2 = inclination(x3, y3, x4, y4);

    double yo1 = y1 - ic1 * x1;
    double yo2 = y3 - ic2 * x3;

    // y축에 평행한 경우
    if (isnan(ic1) && isnan(ic2))
    {
        if (x1 != x3)
        {
            cout << "1\n";
            return;
        }
        cout << judge(y1, y2, y3, y4);
        return;
    }

    // 기울기가 같은경우
    if (ic1 == ic2)
    {

        // 기울기가 같고 y 절편이 같은경우
        if (yo1 == yo2)
        {
            cout << judge(x1, x2, x3, x4);
            return;
        }
        cout << "1\n";
        return;
    }

    // 기울기가 다른 경우
    else
    {

        // 선분의 끝에서 만나는 경우
        if ((x1 == x3) && (y1 == y3))
        {
            cout << "2\n";
            return;
        }
        if ((x1 == x4) && (y1 == y4))
        {
            cout << "2\n";
            return;
        }
        if ((x2 == x3) && (y2 == y3))
        {
            cout << "2\n";
            return;
        }

        if ((x2 == x4) && (y2 == y4))
        {
            cout << "2\n";
            return;
        }

        // x값의 범위가 겹치지 않는경우 관계1
        if((x1 != x3) && (x1!=x4) && (x2!=x3) && (x2 != x4)){
            if (((x1 > x3) == (x1 > x4)) && ((x2 > x3) == (x2 > x4)) && ((x1 > x3) == (x2 > x3)) && ((x1 > x4) == (x2 > x4)))
            {
                cout << "1\n";
                return;
            }
        }
        // y값의 범위가 겹치지 않는경우 관계1
        if((y1 != y3) && (y1!=y4) && (y2!=y3) && (y2 != y4)){
            if (((y1 > y3) == (y1 > y4)) && ((y2 > y3) == (y2 > y4)) && ((y1 > y3) == (y2 > y3)) && ((y1 > y4) == (y2 > y4)))
            {
                cout << "1\n";
                return;
            }
        }
        // x,y 범위가 겹치는경우
        // 범위 안에 겹치는 점이 있는지 확인해야함

        bool target = x2 - x1 < x4 - x3 ? true : false;
        double tIC = target ? ic2 : ic1;
        double tYo = target ? yo2 : yo1;
        int tx1 = target ? x1 : x3;
        int tx2 = target ? x2 : x4;
        int ty1 = target ? y1 : y3;
        int ty2 = target ? y2 : y4;

        double resulty1 = tIC * tx1 + tYo;
        double resulty2 = tIC * tx2 + tYo;

        if ((resulty1 < ty1) != (resulty2 < ty2))
        {
            cout << "2\n";
            return;
        }

        cout << "1\n";
    }
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