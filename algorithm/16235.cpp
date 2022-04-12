#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int n, m, k;
int map[11][11]; // 5
int dirt[11][11];
int demap[11][11];

const int adjx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
const int adjy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};

struct tree
{
    int x, y, z;

    bool operator<(const tree a) const{
        return this->z > a.z;
    }
};

deque<tree> q;

void summer();
void fall();
void winter();

void spring()
{
    deque<tree> tmpq;
    int size = q.size();
    for (int i = size-1; i >=0; i--)
    {
        int x = q[i].x;
        int y = q[i].y;
        if (map[x][y] - q[i].z < 0)
        {
            demap[x][y] += (int)(q[i].z/2);
            continue;
        }
        map[x][y] -= q[i].z;
        q[i].z++;
        tmpq.push_front(q[i]);

    }
    q=tmpq;
    fall();
}


bool cb(int x, int y )
{
    if( x <= 0 || y <= 0 || x > n || y > n)
        return false;
    return true;
}

void fall()
{
    int size = q.size();
    for (int i = 0; i < size; i++)
    {
        // 번식
        if (q[i].z % 5 == 0)
        {
            int x = q[i].x;
            int y = q[i].y;
            for(int j = 0; j < 8; j++)
            {
                int tmpx = x + adjx[j];
                int tmpy = y + adjy[j];
                if(cb(tmpx, tmpy))
                {
                    tree nt;
                    nt.x = tmpx;
                    nt.y = tmpy;
                    nt.z = 1;
                    q.push_back(nt);
                }
            }
        }
    }

    winter();
}

void winter()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            map[i][j] = map[i][j]+ dirt[i][j] + demap[i][j];
            demap[i][j] = 0;
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++){
            map[i][j] = 5;
            cin >> dirt[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        tree tmp;
        tmp.x = x;
        tmp.y = y;
        tmp.z = z;
        q.push_back(tmp);
    }

    sort(q.begin(), q.end());

    for(int i = 0; i < k; i++)
    {
        spring();
    }

    cout << q.size();
}