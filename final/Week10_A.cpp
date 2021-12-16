#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

int answer;
bool able[10001];

void BFS(int start, string end) {
	queue<pair<int, int>> q;
	pair<int, int> first = { start, answer };
	q.push(first);

	while (!q.empty()) {
		int cur = q.front().first;
		int curAnswer = q.front().second;
		able[cur] = false;
		q.pop();

		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				int next = cur + 1;
				int nextAnswer = curAnswer + 1;

				if (next > 9999 || !able[next])
					continue;

				string check = to_string(next);

				if (check.length() != 4) {
					if (check.length() == 1)
						check = "000" + check;
					else if (check.length() == 2)
						check = "00" + check;
					else
						check = "0" + check;
				}

				if (check == end) {
					cout << nextAnswer << '\n';
					return;
				}

				able[next] = false;
				q.push({ next, nextAnswer });
			}
			else if (i == 1) {
				int next = cur - 1;
				int nextAnswer = curAnswer + 1;

				if (next < 0 || !able[next])
					continue;

				string check = to_string(next);

				if (check.length() != 4) {
					if (check.length() == 1)
						check = "000" + check;
					else if (check.length() == 2)
						check = "00" + check;
					else
						check = "0" + check;
				}

				if (check == end) {
					cout << nextAnswer << '\n';
					return;
				}

				able[next] = false;
				q.push({ next, nextAnswer });
			}
			else {
				string next = to_string(cur);
				int nextAnswer = curAnswer + 1;

				if (next.length() != 4) {
					if (next.length() == 1)
						next = "000" + next;
					else if (next.length() == 2)
						next = "00" + next;
					else
						next = "0" + next;	
				}

				string tmp = next;
				reverse(next.begin(), next.end());

				if (tmp == next)
					continue;

				if (next == end) {
					cout << nextAnswer << '\n';
					return;
				}

				int index;
				for (int i = 0; i < 4; i++) {
					if (next[i] != '0') {
						index = i;
						break;
					}
				}
				next = next.substr(index, next.length());
				int save = stoi(next);

				if (!able[save])
					continue;

				able[save] = false;
				q.push({ save, nextAnswer });
			}
		}
	}
}

void solve() {
	memset(able, true, sizeof(bool) * 10001);
	int start;
	string end;
	cin >> start >> end;

	if (end.length() != 4) {
		if (end.length() == 1)
			end = "000" + end;
		else if (end.length() == 2)
			end = "00" + end;
		else
			end = "0" + end;
	}

	answer = 0;
	BFS(start, end);
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