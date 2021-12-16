#include <iostream>
#include <algorithm>
using namespace std;

int triangle[101][101]; // �ﰢ�� �Է¹��� �迭
int dp[101][101]; // dp ����� �迭

void solve() {
	int answer = 2000000000; // �ּڰ� �����ϱ� ���� ū �� �Ҵ�
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> triangle[i][j]; // �ﰢ�� �迭 �Է�
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0) // �� ���� ������ ������ �ٷ� �� ���ҿ͸� ���� �� �ִ�.
				dp[i][0] = dp[i - 1][0] + triangle[i][0];
			else if (j == i) // �� ������ ���� �� ������ ���� �� ���ҿ͸� ���� �� �ִ�.
				dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
			else if (j != i) // �� ���� ��쿡�� �ٷ� �� ���ҿ� ���� �� ���� ��, ���� ���� ��� ���Ѵ�.
				dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
		}
	}

	for (int i = 0; i < n; i++) 
		answer = min(answer, dp[n - 1][i]); // ������ �� ���� ���� �ּڰ� ã��

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