#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int map[5][8];

struct gear
{
    int top = 0;
    int left = 6;
    int right = 2;
};

gear gears[5];
int statusOfgear[5];

void turn(int numOfgear, int direction)
{
    if (direction == -1)
    {
        gears[numOfgear].top++;
        gears[numOfgear].left++;
        gears[numOfgear].right++;
        if (gears[numOfgear].top == 8)
            gears[numOfgear].top = 0;
        if (gears[numOfgear].left == 8)
            gears[numOfgear].left = 0;
        if (gears[numOfgear].right == 8)
            gears[numOfgear].right = 0;
    }
    else if (direction == 1)
    {
        gears[numOfgear].top--;
        gears[numOfgear].left--;
        gears[numOfgear].right--;
        if (gears[numOfgear].top == -1)
            gears[numOfgear].top = 7;
        if (gears[numOfgear].left == -1)
            gears[numOfgear].left = 7;
        if (gears[numOfgear].right == -1)
            gears[numOfgear].right = 7;
    }
}

void solving(int a, int b)
{
    for (int i = 1; i < 5; i++)
    {
        statusOfgear[i] = 0;
    }

    statusOfgear[a] = b;
    for (int k = 0; k < 4; k++)
    {
        for (int i = 1; i <= 4; i++)
        {
            if (statusOfgear[i] == 0)
                continue;

            if (i == 1)
            {
                // 1번 기어
                // 1번 기어의 오른쪽 2번과 맞닿은부분
                int leftOne = map[1][gears[1].right];

                // 2번 기어의 왼쪽 1번과 맞닿은부분
                int rightOne = map[2][gears[2].left];

                if (leftOne == rightOne)
                    continue;

                if (statusOfgear[2] == 0)
                    statusOfgear[2] = statusOfgear[1] * -1;
            }
            else if (i == 4)
            {
                // 4번기어
                // 4번 기어의 왼쪽 3번과 맞닿은 부분
                int leftOne = map[4][gears[4].left];
                // 3번 기어의 오른ㅉ고 4번과 맞닿은 부분
                int rightOne = map[3][gears[3].right];

                if (leftOne == rightOne)
                    continue;
                if (statusOfgear[3] == 0)
                    statusOfgear[3] = statusOfgear[4] * -1;
            }
            else
            {
                // 2,3번 기어
                int targetLeft = map[i][gears[i].left];
                int targetRight = map[i][gears[i].right];

                // 왼쪽 기어의 오른쪽
                int leftOne = map[i - 1][gears[i - 1].right];

                // 오른쪽 기어의 왼쪽
                int rightOne = map[i + 1][gears[i + 1].left];

                if (targetLeft != leftOne && statusOfgear[i - 1] == 0)
                    statusOfgear[i - 1] = statusOfgear[i] * -1;

                if (targetRight != rightOne && statusOfgear[i + 1] == 0)
                    statusOfgear[i + 1] = statusOfgear[i] * -1;
            }
        }
    }
    for (int i = 1; i < 5; i++)
    {
        int status = statusOfgear[i];
        turn(i, status);
    }
}

int main()
{
    // n == 0
    // s == 1
    for (int i = 1; i <= 4; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            map[i][j] = s[j] - 48;
        }
    }

    int k;
    cin >> k;
    // 1 이면 시계
    // -1 이면 반시계
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        solving(a, b);
    }

    int result = 0;
    for (int i = 1; i < 5; i++)
    {
        if (map[i][gears[i].top] == 1)
            result += pow(2, i - 1);
    }

    cout << result;
}