#include <iostream>

using namespace std;

int arr[5050];
int result[5050];

int leftdown(int index, int targetrow)
{
    return index + targetrow - 1;
}

int rightdown(int index, int targetrow)
{
    return index + targetrow;
}

void solving()
{
    int n ;
    cin >> n;

    int max = n * (n + 1) / 2;

    for(int i = 0; i < max; i++)
    {
        cin >> arr[i];
        result[i] = 0;
    }

    int targetrow = 2;
    result[0] = arr[0];

    for(int i = 0; i < max-n; i++)
    {   
        int leftTarget = leftdown(i,targetrow);
        int rightTarget = rightdown(i,targetrow);

        int left = result[i] + arr[leftTarget];
        if(result[leftTarget] == 0 || left < result[leftTarget])
            result[leftTarget] = left;

        int right = result[i] + arr[rightTarget];
        if(result[rightTarget] == 0  || right < result[rightTarget])
            result[rightTarget] = right;

        int caclrow = targetrow * (targetrow - 1) /2;
        if(caclrow == i+1)
            targetrow++;
    }
    int min = -1;
    for(int i = max-n; i < max; i++)
    {
        if( min == -1)
            min = result[i];
        else if(min > result[i])
            min = result [i];
    }
    cout << min << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    for(int i = 0 ; i < t; i++)
    {
        solving();
    }
}
