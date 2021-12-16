#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;

    cin >> t;

    for (int i = 0; i < t; i++)
    {
        string s;
        cin >> s;

        int k;
        cin >> k;

        // k번째 줄까지 j번 한다
        for (int j = 0; j < k; j++)
        {
            //j번째 줄에서 끝까지 한다
            int tt = 0;
            // tt 번째 글자 출력
            while (true)
            {
                if (tt * k >= s.length())
                    break;
                if (tt % 2 == 0)
                {
                    if(tt * k + j >= s.length())
                        break;
                    cout << s[tt * k + j];
                }
                else
                {
                    
                    if((tt + 1) * k - 1 - j >= s.length())
                        break;
                    cout << s[(tt + 1) * k - 1 - j];
                }
                tt++;
            }
        }
        cout << "\n";
    }
}