#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct RoomInfo {
	int score;
	int distance;
}; // 점수, 거리 저장받을 구조체

bool cmp(RoomInfo r1, RoomInfo r2) {
	return r1.score > r2.score;
} // vector의 정렬에 사용할 함수, 점수의 내림차순으로 정렬되도록 설정해준다.
 
void solve() {
	vector<RoomInfo> v; 
	int answer = 1; // 출력 개수, 무조건 1부터 시작한다.
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		RoomInfo r;
		cin >> r.score >> r.distance;
		v.push_back(r);
	}
	sort(v.begin(), v.end(), cmp); // 점수에 대한 내림차순으로 입력

	int minDist = v[0].distance; // 가장 높은 점수의 거리값을 최솟값으로 저장
	for (int i = 1; i < n; i++) { // 점수가 두번째로 높은 요소부터 돈다.
		if (v[i].distance < minDist) { // 요소의 거리가 현재 저장된 거리보다 작다면,
			answer++; // 답 하나 증가
			minDist = v[i].distance; // 거리 최솟값 갱신
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