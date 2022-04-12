#include <string>
#include <vector>
#include <set>

using namespace std;


vector<string> solution(vector<string> goods)
{
    vector<string> answer;

    vector<set<string>> tt;

    // goods 한개마다
    for (int i = 0; i < goods.size(); i++)
    {
        // set에다가 넣을 대상
        string tmp = goods[i];
        set<string> ns;
        tt.push_back(ns);
        for (int j = 0; j < tmp.length(); j++)
        {
            // 각 부분집합 넣기
            string pushing;
            // 부분집합 n개 지정
            for (int k = 1; k <= tmp.length(); k++)
            {
                // 시작 위치 지정
                for (int t = 0; t + k <= tmp.length(); t++)
                {
                    tt[i].insert(goods[i].substr(t, k));
                }
            }
        }
    }

    for (int i = 0; i < goods.size(); i++)
    {
        string answerString ="";
        set<string> tmpAnswer;
        for (int len = 1; len <= goods[i].length(); len++)
        {
            bool fanswer = true;
            string str;
            for (int k = 0; k + len <= goods[i].length(); k++)
            {
                fanswer = true;
                str = goods[i].substr(k, len);
                for(int l = 0; l < goods.size(); l++)
                {
                    if(l == i)
                        continue;
                    
                    if(tt[l].find(str) != tt[l].end())
                    {
                        fanswer = false;
                        continue;
                    }
                }
                if(fanswer)
                {
                    tmpAnswer.insert(str);
                }
            }
            if(tmpAnswer.size() != 0)
            {
                string tmp ="";
                for(auto z: tmpAnswer)
                    tmp += z + " ";
                if(tmp.back() == ' ')
                    tmp.pop_back();
                answer.push_back(tmp);
                break;
            }
        }
        if( answer.size() != i + 1)
        {
            answer.push_back("None");
        }
    }
    return answer;
}

int main()
{
    vector<string> goods;
    goods.push_back("abcdeabcd");
    goods.push_back("cdabe");
    goods.push_back("abce");
    goods.push_back("bcdeab");
    solution(goods);
}