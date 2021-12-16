#include <iostream>
#include <vector>

using namespace std;

int t, b, answer;

struct roadInfo
{
public:
    int neighbor, distance;
    roadInfo()
    {
        this->neighbor = 0;
        this->distance = 0;
    }
};

vector<vector<roadInfo>> house;
bool visitedHouse[2001];

int treeSearch(int start)
{
    int first = 0;
    int second = 0;
    int tmpD;

    visitedHouse[start] = true;
    int size = house[start].size();
    for(int i = 1; i<=size; i++)
    {
        if(visitedHouse[house[start][i-1].neighbor] == false)
        {
            tmpD = treeSearch(house[start][i-1].neighbor) + house[start][i-1].distance;
            if(tmpD > first)
                swap(tmpD, first);
            if(tmpD>second)
                swap(tmpD, second);
        }
    }
    answer = max(answer,first + second);
    return first;
}

void solving()
{
    int n;
    cin >> n;

    house.clear();
    for (int i = 0; i <= n; i++)
    {
        vector<roadInfo> tmp;
        house.push_back(tmp);
        visitedHouse[i] = false;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        roadInfo tmp;
        tmp.neighbor = b;
        tmp.distance = c;
        house[a].push_back(tmp);
        tmp.neighbor = a;
        house[b].push_back(tmp);
    }
    answer = 0;

    treeSearch(1);
    cout << answer << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> t;
    for (int i = 0; i < t; i++)
    {
        solving();
    }
}