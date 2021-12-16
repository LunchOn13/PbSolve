#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct alpha
{
    alpha()
    {
        for (int i = 0; i < 23; i++)
        {
            check[i] = false;
        }
    }
    int arr[26];
    int alph[26];
    bool check[23];
    int score;
    int num;
};

alpha words[23];

void solving()
{
    alpha main;

    for (int i = 0; i < 26; i++)
    {
        cin >> main.arr[i];
    }

    int m;
    cin >> m;

    int result = 0;

    // 모든 단어 한번씩 계산
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;

        words[i].num = i;
        for (int j = 0; j < 26; j++)
        {
            words[i].arr[j] = main.arr[j];
            words[i].alph[j] = 0;
        }

        for (int j = 0; j < s.length(); j++)
        {
            words[i].arr[(s[j] - 'a')]--;
            words[i].alph[(s[j] - 'a')]++;
        }
        cin >> words[i].score;

        result = max(words[i].score, result);

        words[i].check[i] = true;
    }

    queue<alpha> q;
    for (int i = 0; i < m-1; i++)
    {
        q.push(words[i]);
    }

    while (!q.empty())
    {
        // 큐를 벡터로 바꾸고 지들끼리 한번 비벼야됨
        alpha tmp = q.front();
        q.pop();

        for (int i = 0; i < m; i++)
        {
            // 같거나 이미 한건 넘어간다
            if (tmp.check[i] == true)
                continue;

            bool isEnough = true;
            int tmparr[26];
            for (int j = 0; j < 26; j++)
            {
                int calc = tmp.arr[j] - words[i].alph[j];
                if (calc < 0)
                {
                    isEnough = false;
                    break;
                }
                tmparr[j] = calc;
            }

            if (isEnough)
            {
                for (int j = 0; j < 26; j++)
                {
                    tmp.arr[j] = tmparr[j];
                }

                tmp.score += words[i].score;
                tmp.check[i] = true;
                result = max(tmp.score, result);
                q.push(tmp);
            }
        }
    }

    cout << result << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    solving();
}