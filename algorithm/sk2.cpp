#include <string>
#include <vector>
#include <cmath>

using namespace std;


// 12시 기준으로
// 반시계 방향
int ucadx[4] = {-1, 0, 1, 0};
int ucady[4] = { 0, -1, 0, 1};

// 시계방향
int cadx[4]= { -1,0,1,0};
int cady[4] = {0,1,0,-1};

struct dot{
    dot() {};
    int x;
    int y;

    int nowDirection;
};

bool cb(vector<vector<int>>answer, int x, int y, int n)
{
    if(x > n || y > n || x <0 || y < 0)
        return false;

    if(answer[x][y] != 0)
        return false;
    
    return true;
}

vector<vector<int>> solution(int n, bool clockwise) {

    vector<vector<int>> answer;
    for(int i = 0; i < n; i++)
    {
        vector<int> tmp;
        answer.push_back(tmp);
        for(int j = 0; j < n; j++)
        {
            answer[i].push_back(0);
        }
    }

    dot d[4];
    d[0].x = 0;
    d[0].y = 0;
    d[1].x = 0;
    d[1].y = n-1;
    d[2].x = n-1;
    d[2].y = 0;
    d[3].x = n-1;
    d[3].y = n-1;

    if(clockwise)
    {
        d[0].nowDirection = 1;
        d[1].nowDirection = 2;
        d[2].nowDirection = 0;
        d[3].nowDirection = 3;
    }
    else
    {
        d[0].nowDirection = 2;
        d[1].nowDirection = 1;
        d[2].nowDirection = 3;
        d[3].nowDirection = 0;
    }
    
    
    for(int j = 0; j < 4; j++)
    {
        answer[d[j].x][d[j].y] = 1;
    }
    
    int limit = ceil((float)n*n/4);
    for(int i = 2; i <= limit; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            int tmpx;
            int tmpy;
            if(clockwise)
            {
                tmpx = d[j].x + cadx[d[j].nowDirection];
                tmpy = d[j].y + cady[d[j].nowDirection];
            }
            else
            {
                tmpx = d[j].x + ucadx[d[j].nowDirection];
                tmpy = d[j].y + ucady[d[j].nowDirection];
            }

            if (!cb(answer,tmpx, tmpy,n))
            {
                d[j].nowDirection++;
                if(d[j].nowDirection >= 4)
                    d[j].nowDirection = 0;
                
                if (clockwise)
                {
                    tmpx = d[j].x + cadx[d[j].nowDirection];
                    tmpy = d[j].y + cady[d[j].nowDirection];
                }
                else
                {
                    tmpx = d[j].x + ucadx[d[j].nowDirection];
                    tmpy = d[j].y + ucady[d[j].nowDirection];
                }
            }

            answer[tmpx][tmpy] = i;
            d[j].x = tmpx;
            d[j].y = tmpy;
        }
    }
    
    return answer;
}

int main()
{
    solution(6,false);
}