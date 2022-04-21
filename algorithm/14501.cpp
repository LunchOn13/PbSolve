#include <stdio.h>

int max(int a, int b) {
	return a > b ? a : b;
}
int n, t, p, d[22];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &t, &p);
		d[i + 1] = max(d[i + 1], d[i]);
		d[i + t] = max(d[i + t], d[i] + p);
	}
	printf("%d", d[n]);
}

// #include <iostream>
// #include <vector>
// using namespace std;

// int n;

// struct day
// {
//     public:
//         day()
//         {}
//         int spend = 0;
//         int earn = 0;
//         bool visited = false;
// };


// vector<day> arr;

// int select(int start, int penalty)
// {
//     int max = 0;
//     int result = 0;
//     for(int i = start + penalty; i < n; i++)
//     {
//         for (int j = i; j < n; j++)
//         {
//             arr[j].visited = false;
//         }


//         if(arr[i].visited == false && arr[i].spend + i <= n)
//         {
//             result = select(i,arr[i].spend);
//             if(result > max)
//                 max = result;
//             arr[i].visited = true;
//         }
//     }

//     return arr[start].earn + max;
// }


// void solve()
// {
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         day tmp;
//         cin >> tmp.spend >> tmp.earn;
//         tmp.visited = false;
//         arr.push_back(tmp);
//     }

//     int max = 0;
//     for(int i = 0; i < n ;i++)
//     {
//         if(arr[i].spend + i > n)
//             continue;

//         int tmp = select(i,arr[i].spend);
//         if (max < tmp)
//             max = tmp;
//     }

//     cout << max;
// }

// int main()
// {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);

//     solve();
// }