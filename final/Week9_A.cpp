#include <iostream>
#include <cmath>
using namespace std;

long long x, n, m;

pair<long long, long long> geoSeries(long long _x, long long _n) {
	if (_n == 1)
		return { _x % m, _x % m };

	pair<long long, long long> half = geoSeries(_x, floor(_n / 2));
	long long exp = half.first;
	long long sum = half.second;

	if (_n % 2 == 0)
		return { (exp * exp) % m, ((1 + exp) * sum) % m };
	else
		return { (_x * exp * exp) % m, (_x + _x * (1 + exp) * sum) % m };
}

void solve() {
	cin >> x >> n >> m;
	
	pair<long long, long long> answer = geoSeries(x, n);

	cout << answer.second << '\n';
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

// X^N = X^N/2 * X^N/2 or X * X^(N-1)/2 * X^(N-1)/2 이용(divide and conquer)
// X + X^2 + X^3 + ... + X^N 구하기 -> 반씩 나눠서 구한다.