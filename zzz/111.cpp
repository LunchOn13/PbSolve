#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int score[24];
int needAlphabet[24][26];
int restAlphabet[8388609][26];
int answer;
int m;
int getScore[8388609];

// 이건 통째로 외워야 할듯 싶다
void solve() {
	getScore[0] = 0;

	for (int i = 0; i < m; i++) {
		int status = 1 << i;

		for (int j = 0; j < status; j++) {
			bool flag = false;

			for (int k = 0; k < 26; k++) {
				if (restAlphabet[j][k] < needAlphabet[i][k]) {
					flag = true;
				}
			}

			if (flag)
				continue;

			for (int k = 0; k < 26; k++)
				restAlphabet[j + status][k] = restAlphabet[j][k] - needAlphabet[i][k];

			getScore[j + status] = getScore[j] + score[i];
			answer = max(answer, getScore[j + status]);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 0; i < 26; i++)
		cin >> restAlphabet[0][i];

	cin >> m;

	for (int i = 0; i < m; i++) {
		string word;
		cin >> word >> score[i];

		for (int j = 0; j < word.length(); j++)
			needAlphabet[i][word[j] - 'a']++;
	}

	solve();
	cout << answer << '\n';

	return 0;
}
