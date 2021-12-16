#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

int solving()
{
    // 친구 수
    int n;
    cin >> n;

    // 단어 수
    int m;
    cin >> m;

    // 문장
    queue<string> hashed_sentence;

    // 교수님 문장 처리
    string tmp;
    for (int i = 0; i < m; i++)
    {
        cin >> tmp;
        hashed_sentence.push(tmp);
    }

    // 학생들 단어 처리
    vector<queue<string>> student;

    for (int i = 0; i < n; i++)
    {
        int ttmp;
        cin >> ttmp;

        queue<string> words;
        for (int j = 0; j < ttmp; j++)
        {
            cin >> tmp;
            words.push(tmp);
        }
        student.push_back(words);
    }

    // 비교하기
    for (int i = 0; i < m; i++)
    {
        string target = hashed_sentence.front();

        bool check = false;
        for (int j = 0; j < n; j++)
        {
            if (student[j].front() == target)
            {
                student[j].pop();
                hashed_sentence.pop();
                check = true;
                break;
            }
        }
        if (check == false)
            return 0;
    }

    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cout << solving() << "\n";
    }
}