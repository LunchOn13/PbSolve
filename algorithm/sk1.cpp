#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int coin[6] = { 1, 5, 10, 50, 100, 500};
int coinCnt[6] = {0,};

struct Co{
    Co() {};
    float coinRatio;
    int coin;
    int cost;

    bool operator< (const Co &c) const{
        if(this->coinRatio == c.coinRatio)
            return this->coin < c.coin;
        return this->coinRatio < c.coinRatio;
    }
};

Co coins[6];

int solution(int money, vector<int> costs) {
    
    int answer = 0;

    for(int i = 0; i < 6; i++)
    {
        coins[i].coin = coin[i];
        coins[i].cost = costs[i];
        coins[i].coinRatio = (float)costs[i]/coin[i];
    }

    sort(coins, coins+6);

    int tmpMoney = money;
    // 선택할 코인의 개수를 앞에서 부터 제한한다.
    for(int i = 0; i < 6; i++)
    {
        int t = floor(tmpMoney / coins[i].coin);
        answer +=  coins[i].cost*t;
        tmpMoney -= coins[i].coin * t;
    }


    return answer;
}

int main()
{
    int money = 1999;
    vector<int> costs = { 2, 11, 20 ,100, 200 ,600};
    int result = 2308;

    cout << solution(money,costs);
}