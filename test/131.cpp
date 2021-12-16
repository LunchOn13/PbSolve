#include <iostream>
#include <string>
#include <vector>
using namespace std;

// failure 함수랑 kmp 함수랑 외워야된다 이것만 외우면됨
int n, m;
char arr[3000][3000];
int fail[3000];

void failure(string s)
{
    int i = 1;
    int j = 0;
    while (i < s.length())
    {
        if (s[i] == s[j])
        {
            fail[i] = j + 1;
            i++;
            j++;
        }
        else if (j > 0)
            j = fail[j - 1];
        else
        {
            fail[i] = 0;
            i++;
        }
    }
}

bool kmp(string target, string word)
{
    int i = 0;
    int j = 0;

    while (i < target.length())
    {
        if (target[i] == word[j])
        {
            if (j == word.length() - 1)
                return true;
            i++;
            j++;
        }
        else if (j > 0)
            j = fail[j - 1];
        else
            i++;
    }
    return false;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    vector<string> words;
    for (int i = 0; i < m; i++)
    {
        string tmp;
        cin >> tmp;
        words.push_back(tmp);
    }

    // 왼쪽에서 오른쪽
    string first;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            first.push_back(arr[i][j]);
        }
        first.push_back('|');
    }
    // 위에서 아래로
    string second;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            second.push_back(arr[j][i]);
        }
        second.push_back('|');
    }

    // 대각선
    string third;
    for (int i = 0; i < n; i++)
    {
        int x = i;
        int y = 0;
        while (x < n && y < n)
        {
            third.push_back(arr[x][y]);
            x++;
            y++;
        }
        third.push_back('|');
    }
    for (int i = 1; i < n; i++)
    {
        int x = 0;
        int y = i;
        while (x < n && y < n)
        {
            third.push_back(arr[x][y]);
            x++;
            y++;
        }
        third.push_back('|');
    }

    for (int i = 0; i < words.size(); i++)
    {

        failure(words[i]);
        if (kmp(first, words[i]))
        {
            cout << "1"
                 << "\n";
            continue;
        }

        if (kmp(second, words[i]))
        {
            cout << "1"
                 << "\n";
            continue;
        }

        if (kmp(third, words[i]))
        {
            cout << "1"
                 << "\n";
            continue;
        }

        cout << "0"
             << "\n";
    }
}