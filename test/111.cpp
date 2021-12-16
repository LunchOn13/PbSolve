#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int score[23];
int need[23][26];
int rest[10000000][26];
int answer;
int m;
int getscore[10000000];

int main()
{
    // 문제에서 제시되는 가장 처음 알파벳 최대 갯수들
    for (int i = 0; i < 26; i++)
    {
        cin >> rest[0][i];
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s >> score[i];
        // 각 단어마다 필요한 알파벳의 갯수와 점수
        for (int j = 0; j < s.length(); j++)
        {
            need[i][s[j] - 'a']++;
        }
    }

    // 처음 score는 무조건 0
    getscore[0] = 0;

    for (int i = 0; i < m; i++)
    {
        // 단어 하나씩 추가해가면서 모든 경우의 수를 찾아본다
        // 단어 하나마다 기존것에 곱하기 2 된거나 마찬가지
        int status = 1 << i;

        // 그 모든 경우의 수를 따라가면서~
        for (int j = 0; j < status; j++)
        {
            // flag를 세우고
            bool flag = false;

            // 해당 경우의 수 ( 이미 뒤에서 만들어서 준거임)에서의 남은 알파벳 개수가
            // 현재 추가한 단어의 필요 알파벳 수보다 작으면
            // flat를 true로 한다 true는 즉 해당 단어를 추가하지 못하는 경우의 수 라는 것
            // 제외된다는 것
            for (int k = 0; k < 26; k++)
            {
                if (rest[j][k] < need[i][k])
                {
                    flag = true;
                    break;
                }
            }

            // 제외 되는 경우임
            if (flag)
                continue;

            // 이번턴에 추가한 단어가 들어갈 수 있는 단어라면
            // 다음거를 추가를 하는것이다
            // j + status의 상태를 만들어서 추가해주고 점수와 답을 업데이트한다.
            for (int k = 0; k < 26; k++)
                rest[j + status][k] = rest[j][k] - need[i][k];
            getscore[j + status] = getscore[j] + score[i];
            answer = max(answer, getscore[j + status]);
        }
    }

    cout << answer << '\n';
}