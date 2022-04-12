#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int n, m;
int houseCnt = 0;
int chikenCnt = 0;

pair<int,int> house[100];
pair<int,int> chicken[13];

int chickenLen[100][13];

int len(int x, int y, int a, int b)
{
    return abs(x-a) + abs(y-b);
}

bool check[13];
int result = 9999;

vector<int> selectedChicken;
void combination(int idx, int next, int r)
{
    if (next == r)
    {
        selectedChicken.clear();
        for (int i = 0; i < chikenCnt; i++)
	    {
	        if (check[i] == true)
	        {
	            selectedChicken.push_back(i);
	        }
	    }

        int tmpMin = 0;
        for(int i = 0; i < houseCnt; i++)
        {
            int minmin = 9999;
            for(int j = 0; j < m; j++)
            {
                int target = chickenLen[i][selectedChicken[j]];
                if(target < minmin)
                {
                    minmin = target;
                }
            }
            tmpMin+=minmin;
        }

        if(tmpMin < result)
        {
            result = tmpMin;
        }
        return;
    }
 
    for (int i = idx; i < chikenCnt; i++)
    {
        if (check[i] == true) continue;
        check[i] = true;

        combination(i,next+1,r);
        check[i] = false;
    }
}


void solving()
{
    for(int i = 0; i < m; i++)
    {
        check[i] = false;
    }

    combination(0,0,m);

    cout << result;

}


int main()
{
    cin >> n >> m;

    int tmp;
    
    for(int i =0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> tmp;        
            // 집
            if(tmp==1)
            {
                house[houseCnt] = make_pair(i,j);
                houseCnt++;
            }
            // 치킨집
            else if(tmp == 2)
            {
                chicken[chikenCnt] = make_pair(i,j);
                chikenCnt++;
            }
        }
    }

    for(int i = 0; i < houseCnt; i++)
    {
        for(int j = 0; j < chikenCnt; j++)
        {
            chickenLen[i][j] = len(house[i].first, house[i].second, chicken[j].first, chicken[j].second);
        }
    }

    solving();


}