#include<iostream>
#include <cmath>
using namespace std;

long long x, n, m;

pair<long long , long long > geo(long long xx, long long nn)
{
    if(nn == 1)
        return {xx%m, xx%m};

    pair<long long, long long> half = geo(xx, floor(nn/2));
    long long exp = half.first;
    long long sum = half.second;


    // 시발 이건 그냥 외워야됨
    if(nn%2 == 0)
        return {(exp * exp) % m, ((1+exp)*sum) % m};
    else
        return {(xx*exp*exp) % m, (xx+xx*(1+exp)*sum) %m};
}


void solving()
{
    cin >> x >> n >> m;
    pair<long long ,long long> answer = geo(x,n);
    cout << answer.second << '\n';
}

int main()
{
    int t;
    cin >> t;
    while(t--)
        solving();
}