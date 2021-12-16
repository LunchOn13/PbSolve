#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct Point {
	int x;
	int y;

	bool operator<(const Point p) const {
		if (sqrt(pow(this->x, 2) + pow(this->y, 2)) != sqrt(pow(p.x, 2) + pow(p.y, 2)))
			return sqrt(pow(this->x, 2) + pow(this->y, 2)) < sqrt(pow(p.x, 2) + pow(p.y, 2));
		else {
			if (this->x != p.x)
				return this->x < p.x;
			else
				return this->y < p.y;
		}
	}
};

void solve() {
	priority_queue<Point> pq;
	int m, n, k;
	cin >> m >> n >> k;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		pq.push(Point{ x, y });

		if (pq.size() > k)
			pq.pop();
	}

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		pq.push(Point{ x, y });
		pq.pop();
		cout << pq.top().x << " " << pq.top().y << '\n';
	}
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