#include <iostream>
#include <limits.h>

using namespace std;

int n;
int A[21][21];
int voteArea[21][21];

long long lastResult = LONG_LONG_MAX;

/*
1. 선거구 나누기 n^2 - 4 만큼의 cell 에서
    1부터 n 만큼의 길이를 늘일 수 잇으니까
    (n-1)/2의 제곱근 보다 적은 수를 돌리게 된다.
    n^2 * sqrt((n-1)/2) 만큼 하면 모든 선거구를 확인가능하다
    n이 20이니까
    400 *  10근사치 얼마 안되네
    대충 4천이고

2. 선거구 인원 계산
    4천에 * n^2 이니까 4000 * 400 1600000
    백 60만
    에서 인구 많은것과 작은것의 최소값

*/

bool checkBound(int x, int y)
{
    if (x < 1 || y < 1 || x > n || y > n)
        return false;
    return true;
}

void calcHuman()
{
    int result[6] = {
        0,
    };
    bool isFirst = true;
    bool isFifth = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (voteArea[i][j] == 5)
            {
                if (isFirst)
                    isFirst = false;
                else{
                    if(checkBound(i+1,j+1) && voteArea[i+1][j+1] ==5)
                            isFifth = !isFifth;
                    else if(checkBound(i+1,j-1) && voteArea[i+1][j-1] == 5)
                            isFifth = !isFifth;
                    // 마지막 5
                    else
                        isFifth = false;
                }
                
                result[5] += A[i][j];
            }
            else
            {
                if (isFifth)
                    result[5] += A[i][j];
                else
                {
                    result[voteArea[i][j]] += A[i][j];
                }
            }
        }
    }
    int min = 99999;
    int max = -1;

    for (int i = 1; i < 6; i++)
    {
        min = result[i] < min ? result[i] : min;
        max = result[i] > max ? result[i] : max;
    }
    int r = max - min;
    lastResult = r < lastResult ? r : lastResult;
}

void makeVoteArea(int x, int y)
{
    int d1;
    int d2;

    // 선거구 지정
    for (d1 = 1; d1 <= n - 2; d1++)
    {
        for (d2 = 1; x + d1 + d2 <= n; d2++)
        {
            // 경계선만 지정하고
            // 다시 5 가 나올 때까지
            // 해당 구역 인원을 더하면된다
            // 처음 5와 마지막 5만 예외 처리하면된다.

            // 위 꼭짓점 제외한 꼭짓점이 범위에 들어가는지 확인한다
            if (!checkBound(x + d1, y - d1) ||
                !checkBound(x + d2, y + d2) ||
                !checkBound(x + d1 + d2, y)
            )
                continue;

            // 1 ~ 4 번째 선거구 지정
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    // 각 선거구 지정
                    if (i < x + d1 && j <= y)
                        voteArea[i][j] = 1;
                    else if (i <= x + d2 && j <= n && y < j)
                        voteArea[i][j] = 2;
                    else if (x + d1 <= i && i <= n && j < y - d1 + d2)
                        voteArea[i][j] = 3;
                    else if (x + d2 < i && i <=n && y - d1 + d2 <= j && j<=n)
                        voteArea[i][j] = 4;
                    
                    if( voteArea[i][j] == 5)
                        voteArea[i][j] = 0;
                }
            }

            int i, j;
            // 5번째 선거구 지정
            // 첫번째 경계선
            i = x;
            j = y;
            while (i <= x + d1 && j >= y - d1)
            {
                voteArea[i][j] = 5;
                i++;
                j--;
            }

            // 두번째 경계선
            i = x;
            j = y;
            while (i <= x + d2 && j <= y + d2)
            {
                voteArea[i][j] = 5;
                i++;
                j++;
            }

            // 세번째 경계선
            i = x + d1;
            j = y - d1;
            while (i <= x + d1 + d2 && j <= y - d1 + d2)
            {
                voteArea[i][j] = 5;
                i++;
                j++;
            }

            // 네번째 경계선
            i = x + d2;
            j = y + d2;
            while (i <= x + d1 + d2 && j >= y + d2 - d1)
            {
                voteArea[i][j] = 5;
                i++;
                j--;
            }
            calcHuman();
            // //디버깅
            // cout << "-------------------\n";
            // for (int i = 1; i <= n; i++)
            // {
            //     for (int j = 1; j <= n; j++)
            //     {
            //         if(voteArea[i][j]!=5)
            //             cout << 0 << " ";
            //         else
            //             cout << voteArea[i][j] << " ";
            //     }
            //     cout << "\n";
            // }
            // // 디버깅
            // cout << "-------------------\n";
        }
    }
}

void solve()
{
    // 선거구 지정방법으로 인해 구조상 안되는 것 예외 처리해야함
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=n; j++)
        {
            makeVoteArea(i, j);
        }
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> A[i][j];
        }
    }

    solve();
    cout << lastResult;
}