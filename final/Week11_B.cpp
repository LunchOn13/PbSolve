#include <iostream>
using namespace std;

char paper[1025][1025];
struct PaperInfo {
	int redNum = 0;
	int redSum = 0;
	int blueNum = 0;
	int blueSum = 0;
};

PaperInfo DAQ(int y, int x, int size) {
	PaperInfo tmp;

	if (size == 1) {
		if (paper[y][x] == 'R') {
			tmp.redNum = 1;
			tmp.redSum = 1;
		}
		else {
			tmp.blueNum = 1;
			tmp.blueSum = 1;
		}

		return tmp;
	}

	PaperInfo status[4];
	status[0] = DAQ(y, x, size / 2);
	status[1] = DAQ(y + size / 2, x, size / 2);
	status[2] = DAQ(y, x + size / 2, size / 2);
	status[3] = DAQ(y + size / 2, x + size / 2, size / 2);

	for (int i = 0; i < 4; i++) {
		tmp.redNum += status[i].redNum;
		tmp.redSum += status[i].redSum;
		tmp.blueNum += status[i].blueNum;
		tmp.blueSum += status[i].blueSum;
	}

	if (tmp.redNum == 0)
		tmp.blueNum = 1;
	if (tmp.blueNum == 0)
		tmp.redNum = 1;

	return tmp;
}

void solve() {
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> paper[i][j];
		}
	}

	PaperInfo answer = DAQ(0, 0, n);
	cout << answer.redNum << " " << answer.redSum << " " << answer.blueNum << " " << answer.blueSum << '\n';
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