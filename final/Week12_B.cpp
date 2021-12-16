#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct RoomInfo {
	int score;
	int distance;
}; // ����, �Ÿ� ������� ����ü

bool cmp(RoomInfo r1, RoomInfo r2) {
	return r1.score > r2.score;
} // vector�� ���Ŀ� ����� �Լ�, ������ ������������ ���ĵǵ��� �������ش�.
 
void solve() {
	vector<RoomInfo> v; 
	int answer = 1; // ��� ����, ������ 1���� �����Ѵ�.
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		RoomInfo r;
		cin >> r.score >> r.distance;
		v.push_back(r);
	}
	sort(v.begin(), v.end(), cmp); // ������ ���� ������������ �Է�

	int minDist = v[0].distance; // ���� ���� ������ �Ÿ����� �ּڰ����� ����
	for (int i = 1; i < n; i++) { // ������ �ι�°�� ���� ��Һ��� ����.
		if (v[i].distance < minDist) { // ����� �Ÿ��� ���� ����� �Ÿ����� �۴ٸ�,
			answer++; // �� �ϳ� ����
			minDist = v[i].distance; // �Ÿ� �ּڰ� ����
		}
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