#include <iostream>
#include <vector>
using namespace std;

int n, m;

int map[51][51];

int adjx[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1};
int adjy[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1};

vector<pair<int, int>> cloud;
int d, s;

bool cb(int x, int y)
{
    if( x <= 0 || y <= 0 || x > n || y > n)
        return false;
    return true;
}

pair<int, int> move(pair<int, int> p)
{
    int x = p.first;
    int y = p.second;
    int movx = adjx[d] * s;
    int movy = adjy[d] * s;

    x += movx;
    y += movy;

    while(!cb(x,y)){
    if (x <= 0)
        x = n + x;
    else if (x > n)
        x = x - n;

    if (y <= 0)
        y = n + y;
    else if (y > n)
        y = y - n;
    }

    return make_pair(x,y);
}

void solving()
{
    cin >> d >> s;

    int clsize = cloud.size();

    for(int i = 0; i < clsize; i++)
    {
        cloud[i] = move(cloud[i]);
        map[cloud[i].first][cloud[i].second]++;
    }

    for(int i = 0; i < clsize; i++)
    {
        int cnt = 0;
        int x = cloud[i].first;
        int y = cloud[i].second;

        int tx, ty;

        int dirc = 2;
        for(int i = 0; i < 4;i++)
        {
            tx = x + adjx[dirc];
            ty = y + adjy[dirc];

            if(cb(tx,ty))
            {
                if(map[tx][ty] > 0)
                    cnt++;
            }
            dirc+=2;
        }
        map[x][y]+=cnt;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(map[i][j] >= 2)
            {
                bool check = true;
                for(int k = 0; k < clsize; k++)
                {
                    if(cloud[k].first == i && cloud[k].second == j)
                    {
                        check = false;
                        break;
                    }
                }
                if(check)
                {
                    cloud.push_back(make_pair(i,j));
                    map[i][j]-=2;
                }
            }
        }
    }

    for(int i =0; i < clsize; i++)
    {
        cloud.erase(cloud.begin());
    }

}

int main()
{

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> map[i][j];
        }
    }

    cloud.push_back(make_pair(n, 1));
    cloud.push_back(make_pair(n, 2));
    cloud.push_back(make_pair(n - 1, 1));
    cloud.push_back(make_pair(n - 1, 2));

    for (int i = 0; i < m; i++)
    {
        solving();
    }

    int result = 0;
    for(int i = 1; i <=n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            result+=map[i][j];
        }
    }
    cout << result;
}