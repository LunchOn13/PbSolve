#include<iostream>
#include <algorithm>
using namespace std;

int n;
pair<int,int> arr[100000];

int main()
{
    cin >> n;

    int a , b;
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr[i] = make_pair(b,a);
    }

    sort(arr, arr+n);

    int start = arr[0].second;
    int end = arr[0].first;
    int cnt = 1;
    for(int i = 1; i < n; i++)
    {
        int tStart = arr[i].second;
        int tEnd = arr[i].first;
        
        if(end <= tStart)
        {
            end = tEnd;
            start = tStart;
            cnt++;
        }
    }

    cout << cnt;
}