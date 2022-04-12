#include<iostream>

using namespace std;
    int n, k;

int arr[10];


void solving()
{
    int tmpk = k;

    int cnt = 0;
    while(true)
    {
        for(int i = n-1; i >= 0; i--)
        {
            if(arr[i] <= tmpk)
            {
                tmpk-=arr[i];
                cnt++;
                break;
            }
        }

        if(tmpk == 0)
            break;
    }

    cout << cnt;
}


int main()
{
    cin >> n >> k;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    solving();
}