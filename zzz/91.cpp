#include <iostream>
#include <cmath>
using namespace std;

long long x, n, m;

// 아 이것도 외워야될듯;
pair<long long ,long long> geo(long long xx, long long nn){
    if(nn == 1)
        return {xx%m, xx%m};

    pair<long long, long long> half = geo(xx, floor(nn/2));
    long long exp = half.first;
    long long sum = half.second;

    if(nn%2 == 0)
        return { (exp * exp) % m, ((1+exp)*sum) %m};
    else
        return {(xx*exp*exp) %m, (xx+xx*(1+exp)*sum) %m};
}

void solving()
{
    
    cin >> x >> n >> m;

    pair<long long ,long long> answer = geo(x,n);

    cout << answer.second << '\n';

}

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solving();
    }
}