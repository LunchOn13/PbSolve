#include <iostream>
#include <string>
using namespace std;

char map[3000][3000];
int n;

string makeString1()
{
    string result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result.push_back(map[i][j]);
        }
        result.push_back('|');
    }

    return result;
}

string makeString2()
{
    string result;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result.push_back(map[j][i]);
        }
        result.push_back('|');
    }

    return result;
}

string makestr(int x, int y)
{
    string result;
    int x_ = x;
    int y_ = y;

    while (x_ < n && y_ < n)
    {
        result.push_back(map[x_][y_]);
        x_++;
        y_++;
    }
    result.push_back('|');

    return result;
}

string makeString3()
{
    string result;
    for (int i = 0; i < n; i++)
    {
        result += makestr(i, 0);
    }

    for (int i = 1; i < n; i++)
    {
        result += makestr(0, i);
    }

    return result;
}

void solving()
{
    int m;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        string target;
        cin >> target;

        string comp[3];
        comp[0] = makeString1();
        comp[1] = makeString2();
        comp[2] = makeString3();


        comp[0].find(target);

        if(makeString1().find(target) != string::npos || makeString2().find(target) !=string::npos || makeString3().find(target) != string::npos)
        {
            cout << "1\n";
            continue;
        }
        
        cout << "0\n";     
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solving();
}