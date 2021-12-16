#include <iostream>
#include <set>
using namespace std;

int message[500001];
int result[500001];

void solve() {
	set<int> s;
	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
		cin >> message[i];

	for (int i = 1; i <= m; i++) {
		s.insert(message[m - i]);
		result[m - i] = n - s.size();
	}

	for (int i = 0; i < m; i++)
		cout << result[i] << '\n';
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