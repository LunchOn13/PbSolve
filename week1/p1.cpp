#include <iostream>
#include <string>
#include <vector>
using namespace std;


void solving()
{
    string s;
    cin >> s;
    int k ;
    cin >> k;
    int size = s.length();

    vector<string> container;
    for(int i =0; i< k; i++)
    {
        string tmp = "";
        container.push_back(tmp);
    }

    // k 가 string 길이보다 길때 예외 처리해야함
    for(int i = 0; i < size; i++)
    {
        char tmp = s[i];
        // 0~3
        if((i/k) % 2 == 0)
            container[i%k].push_back(tmp);
        else
            container[k-1-(i%k)].push_back(tmp);
    }

    for(int i = 0; i < k; i++)
    {
        cout << container[i];
    }
    cout << "\n";

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
    {
        solving();
    }
}