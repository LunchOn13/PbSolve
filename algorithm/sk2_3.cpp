#include <string>
#include <vector>
using namespace std;
vector<vector<int>> map;

// 시간초과남

int diffEdge(vector<vector<int>> &b)
{
    int answer = 0;
    for(int i = 0; i < b.size(); i++)
    {
        int targetx = b[i][0];
        int targety = b[i][1];

        if(map[targetx][targety] == 1)
        {
            answer++;
        }
    }
    return answer;
}

int answer;
void chDot(vector<vector<int>> a, int d , int k , int m)
{
    if(m == 0)
    {
        int result = diffEdge(a);
        if((a.size() - result) < answer)
            answer = a.size()-result;
        return;
    }

    for(int i = 0; i < a.size(); i++)
    {
        if( a[i][0] == d )
            a[i][0] = k;
        else if( a[i][0] == k)
            a[i][0] = d;
        if( a[i][1] == d )
            a[i][1] = k;
        else if( a[i][1] == k)
            a[i][1] = d;

        if(a[i][0] > a[i][1])
        {
            int tmp = a[i][0];
            a[i][0] = a[i][1];
            a[i][1] = tmp;
        }
    }

    for(int i = 1; i <= a.size() + 1; i++)
    {
        for(int j = i+1; j <= a.size() + 1; j++)
        {
            if(i == d && j == k)
                continue;
            else
                chDot(a, i,j,m-1);
        }
    }
    return;
}

int solution(vector<vector<int>> a, vector<vector<int>> b, int m) {
    answer = 999999;
    // a, b를 정렬하고
    for(int i = 0; i < a.size(); i++)
    {
        if(a[i][0] > a[i][1])
        {
            int tmp = a[i][0];
            a[i][0] = a[i][1];
            a[i][1] = tmp;
        }
    }

    for(int i = 0; i < b.size(); i++)
    {
        if(b[i][0] > b[i][1])
        {
            int tmp = b[i][0];
            b[i][0] = b[i][1];
            b[i][1] = tmp;
        }
    }

    int len = a.size() + 2;
    for (int i = 0; i < len; i++)
    {
         vector<int> tmp;
        for (int j = 0; j < len; j++)
        {
            tmp.push_back(0);
        }
        map.push_back(tmp);
    }
    
    for(int i = 0; i < a.size(); i++)
    {
        int x = a[i][0];
        int y = a[i][1];
        map[x][y] = 1;
    }

    // 정점 바꾸기 m 번
    answer = 99999;
    for(int i = 0; i <= m; i++)
    {
        vector<vector<int>> copyb = b;
        if(m == 0)
            chDot(copyb, 1,2,m);
        else
        {
            for(int k = 1; k <= a.size() + 1; k++)
            {
               for(int j = k+1; j <= a.size() + 1; j++)
                {
                   chDot(copyb,k,j,m);
                }
           }
        }
    }

    return answer;
}

int main()
{
    vector<vector<int>>a;
    vector<vector<int>>b;
    int m;

    a = {{1,2},{2,3}};
    b = {{1,3},{3,2}};
    m = 1;
    printf("%d",solution(a,b,m));
}