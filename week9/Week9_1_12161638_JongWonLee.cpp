#include<iostream>
#include<vector>
using namespace std;

void solving()
{
    int x,n,m;
    cin >> x >> n >> m;

    int rmCnt = n%m;
    bool check = false;
    if((m-rmCnt) < rmCnt)
    {
        rmCnt = m-rmCnt;
        check = true;
    }
    int modular = x%m;
    long long result = 0;
    int tmp = 1;
    for(int i = 0; i < rmCnt; i++)
    {
        if(check)
            tmp = m-(tmp*modular) %m;
        else
            tmp = (tmp*modular) % m;
        result +=tmp;
    }

        cout << result % m << "\n";

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    for(int i = 0; i < t; i ++)
    {
        solving();
    }
}

/***
 * 아무리 해도 숫자가 존나 크다 
 * x = m*c +b
 * x^2 = m( ~~~ ) + b^2의 모듈러
 * 
 * 숫자 크기만 신경써서 모듈러 다 쳐도 시간초과 때문에 안된다
 * 
 * 분할 정복 해야된다는거같은데
 * 모두 다 곱셈치면 O(n)이된다
 * 근데 그것보다 빨라야됨
 * 
 * 제곱수가 짝수일때 홀수일때로 나눠서 푼다
 * 
 * 짝수면 5 ^ 10 = 5^5 * 5^5
 * 홀수면 5 ^ 10 = 5 * 5^5 * 5^5
 * O(log n) 된다
 * 재귀쓰셈
 * 
 ***/
