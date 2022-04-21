#include <iostream>
using namespace std;

int n;
int ar[11];
int sum, sub, mul, divi;

int maxResult = INT32_MIN;
int minResult = INT32_MAX;

void dfs(int cnt, int sum_ar)
{
	if (cnt == n)
	{
		maxResult = max(maxResult, sum_ar);
		minResult = min(minResult, sum_ar);
	}   

	else
	{
		if (sum > 0)
		{
			sum--;
			dfs(cnt + 1, sum_ar + ar[cnt]);
            sum++;
		}

		if (sub > 0)
		{
			sub--;
			dfs(cnt + 1, sum_ar - ar[cnt]);
            sub++;
		}

		if (mul > 0)
		{
            mul--;
			dfs(cnt + 1, sum_ar * ar[cnt]);
			mul++;
		}

		if (divi > 0)
		{
            divi--;
			dfs(cnt + 1, sum_ar / ar[cnt]);
			divi++;
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> ar[i];

	cin >> sum >> sub >> mul >> divi;

	dfs(1, ar[0]);

	cout << maxResult << '\n' << minResult;

	return 0;
}