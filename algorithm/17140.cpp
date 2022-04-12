#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int map[101][101];

int row = 3;
int column = 3;


// x 축 기준
void cCalc()
{
    int maxRow = row;
    for (int i = 0; i < column; i++)
    {
        int hash[1000] = {
            0,
        };
        for (int j = 0; j < row; j++)
        {
            if(map[j][i] > 0)
                hash[map[j][i]]++;
        }

        vector<pair<int, int>> container;
        for (int j = 0; j < 1000; j++)
        {
            if (hash[j] < 1)
                continue;

            container.push_back(make_pair(hash[j], j));
        }

        sort(container.begin(), container.end(), less<pair<int, int>>());
        while(container.size() > 50)
        {
            container.pop_back();
        }

        int length = container.size() * 2;
        if (maxRow < container.size() * 2)
        {
            maxRow = container.size() * 2;
            row = maxRow;
        }
        else
            length = maxRow;

        for (int j = 0; j < length; j += 2)
        {
            if (j >= container.size() * 2)
            {
                if(j<100)
                    map[j][i] = 0;
                if(j+1 < 100)
                    map[j+1][i] = 0;
            }
            else
            {
                if(j<100)
                    map[j][i] = container[j / 2].second;
                if(j+1<100)
                    map[j+1][i] = container[j / 2].first;
            }
        }
    }
}

// y 축 기준
void rcalc()
{
    int maxColumn = column;
    for (int i = 0; i < row; i++)
    {
        int hash[1000] = {
            0,
        };
        for (int j = 0; j < column; j++)
        {
            if(map[i][j] > 0)
                hash[map[i][j]]++;
        }

        vector<pair<int, int>> container;
        for (int j = 0; j < 1000; j++)
        {
            if (hash[j] < 1)
                continue;

            container.push_back(make_pair(hash[j], j));
        }

        sort(container.begin(), container.end(), less<pair<int, int>>());
        int length = container.size() * 2;
        if (maxColumn < container.size() * 2)
        {
            maxColumn = container.size() * 2;
            column = maxColumn;
        }
        else
            length = maxColumn;

        for (int j = 0; j < length; j += 2)
        {
            if (j >= container.size() * 2)
            {
                if(j<100)
                    map[i][j] = 0;
                if(j+1<100)
                    map[i][j + 1] = 0;
            }
            else
            {
                if(j<100)
                    map[i][j] = container[j / 2].second;
                if(j+1<100)
                    map[i][j + 1] = container[j / 2].first;
            }
        }
    }
}

int main()
{
    cin >> r >> c >> k;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> map[i][j];
        }
    }

    int time = 0;
    while(true)
    {
        if(map[r-1][c-1] == k)
        {
            cout << time;
            break;
        }
        else if (time == 100)
        {
            cout << -1;
            break;
        }
        time++;
        if(row>= column)
            rcalc();
        else
            cCalc();

        
    }
}