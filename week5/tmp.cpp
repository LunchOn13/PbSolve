#include<iostream>
#include<algorithm>
using namespace std;
int N, M;
int house[1000001];

bool binary_search(int idx) {
   int temp = 1;
   int prev = house[0];
   for (int i = 1;i < N;i++) {
      if (house[i] - prev >= idx) {
         prev = house[i];
         temp++;
      }
   }

   if (temp >= M) {
      return true;
   }
   
   return false;
}

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);

   cin >> N >> M;
   for (int i = 0;i < N;i++) {
      cin >> house[i];
   }

   sort(house, house + N);
   int mini = 1;
   int maxi = house[N - 1] - house[0];
   int answer = 0;
   while (mini <= maxi) {
      int mid = (mini + maxi) / 2;
      if (binary_search(mid)) {
         answer = max(answer, mid);
         mini = mid + 1;
      }
      else {
         maxi = mid - 1;
      }
   }
   cout << answer << '\n';
   return 0;
}