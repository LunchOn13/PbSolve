#include <iostream>
#include <vector>
#include <string>
using namespace std;

class bucket
{
public:
    int num = 0;
    long long wholeLength = 0;
    int p = 0;
    vector<int> child;
};

// 각 n번 디렉토리의 문자의 개수
long long len_of_word[50001] = {
    0,
};

// 각 디렉터리의 벡터 배열 저장
bucket directories[50001];

void loop(int iter, int wholeNum)
{
    if (iter == 1)
    {
        wholeNum = len_of_word[iter];
    }
    else
    {
        wholeNum = wholeNum + len_of_word[iter] + 1;
    }
    directories[iter].wholeLength = wholeNum;

    if (directories[iter].child.empty())
        return;

    for (unsigned int i = 0; i < directories[iter].child.size(); i++)
    {
        loop(directories[iter].child[i], wholeNum);
    }
}

void solving()
{
    // 디렉토리 갯수
    int n;
    cin >> n;

    // 초기화
    for (int i = 0; i < n+1; i++)
    {
        directories[i].num = 0;
        directories[i].child.clear();
        directories[i].p = 0;
        directories[i].wholeLength = 0;
        len_of_word[i] = 0;
    }

    // 초기 값
    directories[1].num = 1;

    // 디렉토리 구성
    for (int i = 1; i < n; i++)
    {
        int a, b;

        cin >> a >> b;

        directories[b].num = b;
        directories[b].p = a;
        directories[a].child.push_back(b);
    }

    // n번 디렉토리별 문자 개수 저장
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        len_of_word[i] = s.length();
    }

    loop(1,0);

    for(int i = 1; i < n+1; i++)
    {
        cout << directories[i].wholeLength << "\n";
    }
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
        solving();
    }
    return 0;
}