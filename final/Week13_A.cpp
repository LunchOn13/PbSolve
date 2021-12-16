#include <iostream>
#include <string>
using namespace std;

int n, m;
int fail[3001];
string matrix[3001];

bool isOk(int y, int x) {
	return y > -1 && y < n && x > -1 && x < n;
}

void failure(string s) {
	fail[0] = 0;
	int i = 1;
	int j = 0;

	while (i < s.length()) {
		if (s[i] == s[j]) {
			fail[i] = j + 1;
			i++;
			j++;
		}
		else if (j > 0)
			j = fail[j - 1];
		else {
			fail[i] = 0;
			i++;
		}
	}
}

bool KMP(string check, string word) {
	int i = 0;
	int j = 0;

	while (i < check.length()) {
		if (check[i] == word[j]) {
			if (j == word.length() - 1)
				return true;

			i++;
			j++;
		}
		else if (j > 0)
			j = fail[j - 1];
		else
			i++;
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string check = "";
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> matrix[i];
		check += matrix[i];
		check += ";";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			check += matrix[j][i];
		}
		check += ";";
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isOk(j, i + j))
				break;

			check += matrix[j][i + j];
		}
		check += ";";
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!isOk(i + j, j))
				break;

			check += matrix[i + j][j];
		}
		check += ";";
	}

	for (int i = 0; i < m; i++) {
		string word;
		cin >> word;

		failure(word);

		if (KMP(check, word))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
		
	return 0;
}

// 2차원 격자판을 상-하 좌-우 좌상단-우하단으로 읽어 하나의 문자열으로 만든다.
// padding 문자를 중간중간 삽입해서 한줄의 긴 문자열로 만든다. --> 여기서 KMP
// 문자열이 불일치 할 때 탐색을 시작했던 텍스트 위치의 다음부터가 아닌, 미리 계산했던 정보를 이용하여 몇 칸은 건너뛴 후 탐색
// 패턴의 각 위치에서 접두사와 접미사가 일치하는 최대 길이