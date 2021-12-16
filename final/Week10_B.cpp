#include <iostream>
#include <algorithm>
using namespace std;

int matryo[501];
int dp[501];

void solve() {
	int answer = -1;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int length = 0;
		cin >> matryo[i];
		
		for (int j = 0; j < i; j++) {
			if (matryo[i] > matryo[j])
				length = max(length, dp[j]);
		}

		dp[i] = length + 1;
		answer = max(answer, dp[i]);
	}

	cout << answer << '\n';
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