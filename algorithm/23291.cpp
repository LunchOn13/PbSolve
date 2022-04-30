#include <iostream>
#include <queue>
using namespace std;

int n, k;

queue<int> theBase;

int roll[11][11];
int divide[11][11];

/*
롤링
n = 1 부터
2번씩 돌면서 놓고
n++ 된다

*/
int direction = 0;

void adjust()
{
}

// to floor 에서 쓴다.
int startx[4] = {0,10,10,0};
int endx[4] = {10,0,0,10};
int starty[4] = {0,10,0,10};
int endy[4] = { 10, 0,10,0};

int seex[4] = {1,-1, -1,1};
int seey[4] = {1,-1,1,-1};


int adjx[4] = {1, 0, -1, 0};
int adjy[4] = {0, 1, 0, -1};

bool isBound(int x, int y)
{
    if(x < 0 || y < 0 || x>11 || y > 11)
        return false;   
    return true;
}

void toFloor()
{
    int x, y;
    bool find = false;
    for(x = startx[direction]; x != endx[direction]; x += seex[direction])
    {
        for(y = starty[direction]; y != endy[direction]; y+= seey[direction])
        {
            if(roll[x][y] != 0)
            {
                find = true;
                break;
            }
        }
        if(find)
            break;
    }

    int tmpx = x;
    int tmpy = y;
    int tax[4] = {0,-1,0,1};
    int tay[4] = {1,0,-1,0};
    for(int i = 0; i < n; i++)
    {
        theBase.push(roll[tmpx][tmpy]);
        tmpx += tax[direction];
        tmpy += tay[direction];

        if(!isBound(tmpx, tmpy) || roll[tmpx][tmpy] == 0)
        {
            x+=adjx[direction];
            y+=adjy[direction];
            tmpx = x;
            tmpy = y;
        }
    }

    for(int i = 0; i < theBase.size(); i++)
    {
        int target = theBase.front();
        theBase.pop();
        cout << target << " ";
        theBase.push(target);
    }
    cout << "\n";
}

void half()
{
}


void divideFish()
{


    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; j < 11; j++)
        {
            if(isBound(i,j) && roll[i][j] != 0)
            {
                




            }
        }
    }
}




void turn()
{
    direction++;
    if (direction == 4)
        direction = 0;
}

void unTurn()
{
    direction--;
    if(direction == -1)
        direction = 3;
}

void rolling()
{
    int x = 5;
    int y = 5;
    int len = 1;
    int count = 2;

    while (!theBase.empty())
    {
        if (theBase.size() < len)
            break;

        if (count-- == 0)
        {
            len++;
            count = 2;
            continue;
        }

        for (int i = 0; i < len; i++)
        {
            roll[x][y] = theBase.front();
            theBase.pop();
            x += adjx[direction];
            y += adjy[direction];
            if (i == len - 1)
                turn();
        }

        cout << "-------------------\n";
        for (int i = 0; i < 11; i++)
        {
            for (int j = 0; j < 11; j++)
            {
                cout << roll[i][j] << " ";
            }
            cout << "\n";
        }
    }
    unTurn();
    while (!theBase.empty())
    {
        roll[x][y] = theBase.front();
        theBase.pop();
        x += adjx[direction];
        y += adjy[direction];
    }
    cout << "-------------------\n";
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            cout << roll[i][j] << " ";
        }
        cout << "\n";
    }
}

void addFish()
{
    int min = 200000;
    for(int i = 0; i < theBase.size(); i++)
    {
        int target = theBase.front();
        theBase.pop();
        min = min > target? target : min;
        theBase.push(target);
    }

    for(int i = 0; i < theBase.size(); i++)
    {
        int target = theBase.front();
        theBase.pop();
        target = min == target ? target+1 : target;
        theBase.push(target);
    }

}

void theTask()
{
    for (int i = 0; i < 11; i++)
    {
        for (int j = 0; j < 11; j++)
        {
            roll[i][j] = 0;
        }
    }

    addFish();
    rolling();
    toFloor();
}

int main()
{
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        theBase.push(tmp);
    }
    theTask();
}