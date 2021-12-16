#include <iostream>
#include <algorithm>
using namespace std;

int triangle[101][101]; // 삼각형 입력받을 배열
int dp[101][101]; // dp 계산할 배열

void solve() {
	int answer = 2000000000; // 최솟값 저장하기 위해 큰 값 할당
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j]; // 삼각형 배열 입력
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) // 맨 왼쪽 원소일 때에는 바로 위 원소와만 더할 수 있다.
				dp[i][0] = dp[i - 1][0] + triangle[i][0];
			else if (j == i) // 맨 오른쪽 원소 일 때에는 왼쪽 위 원소와만 더할 수 있다.
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else if (j != i) // 그 외의 경우에는 바로 위 원소와 왼쪽 위 원소 중, 작은 값을 골라서 더한다.
				dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 0; i < n; i++) 
		answer = min(answer, dp[n - 1][i]); // 마지막 행 원소 중의 최솟값 찾기

	cout << answer << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	while (T--)
		solve();

	return 0;
}