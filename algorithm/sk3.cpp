#include <string>
#include <vector>

using namespace std;

vector<vector<int>> arr[300000];

long long solution(int n, vector<vector<int>> edges) {
    long long answer = 0;

    for(int i = 0; i < n; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        arr[x].push_back(y);
    }

    return answer;
}


int main()
{
    int n = 5;
    int arr[4][2] = {{0,1},{0,2},{1,3},{1,4}};
}