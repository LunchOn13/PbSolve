#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> arr[11];

int map[101][101];

void makeCurve()
{
    arr[0].push_back(make_pair(0,0));
    arr[0].push_back(make_pair(1,0));

    for(int i = 1; i < 11; i++)
    {
        int target = i-1;

        pair<int, int> lastOne = arr[target].back();

        for(int j = 0; j < arr[target].size(); j++)
        {
            arr[i].push_back(arr[target][j]);
        }

        for(int j =arr[target].size()-2; j >=0 ; j--)
        {
            int x, y;
            x = arr[target][j].first - lastOne.first;
            y = arr[target][j].second - lastOne.second;
            int tmp = x;
            x = -1 * y + lastOne.first; 
            y = tmp + lastOne.second;
            arr[i].push_back(make_pair(x,y));
        }
    }
}


int main()
{
    int n;
    cin >> n;

    makeCurve();

    // x , y, 시작 방향, 세대
    int x, y, d, g;

    for(int i = 0; i < n; i ++)
    {
        cin >> x >> y >> d >> g;

        for(int j = 0; j < arr[g].size(); j++)
        {
            int fa = arr[g][j].first;
            int fb = arr[g][j].second;


            for(int k = 0; k < d; k++)
            {
                int tmp = fa;
                fa = fb;
                fb = tmp * -1;
            }
            
            fa+=x;
            fb+=y;

            map[fa][fb]++;
        }
    }

    int result = 0;
    for(int i = 0; i < 100; i++)
    {
        for(int j =0; j< 100; j++)
        {
            if(map[i][j] == 0)
                continue;
            if(map[i+1][j] == 0)
                continue;
            if(map[i][j+1] == 0)
                continue;
            if(map[i+1][j+1]==0)
                continue;
            result++;
        }
    }

    cout << result;
}