#include <iostream>
#include <cstring>
using namespace std;

void solve() {
	int n, m;
	cin >> n >> m;
	int** matrix = new int*[n + 1];
	for (int i = 0; i < n + 1; i++) {
		matrix[i] = new int[n + 1];
		memset(matrix[i], 0, sizeof(int) * (n + 1));
	}

	for (int i = 0; i < m; i++) {
		int num, heavy;
		cin >> num >> heavy;
		matrix[num][heavy] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n; k++) {
				if (matrix[j][i] && matrix[i][k])
					matrix[j][k] = 1;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int count = 0;
		for (int j = 1; j <= n; j++) {
			if (matrix[i][j] == 1)
				count++;
		}
		cout << count << " ";
	}
	cout << '\n';
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