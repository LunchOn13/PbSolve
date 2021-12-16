#include<iostream>
#include<string>
#include<vector>
#include<queue>
using namespace std;

int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   int Tc;
   cin >> Tc;
   while (Tc > 0) {
      int answer = 1;
      Tc--;
      int M, N;
      queue <string> professor;
      vector<queue<string>> vec;
      cin >> M >> N;
      for (int i = 0;i < N;i++) {
         string temp;
         cin >> temp;
         professor.push(temp);
      }

      for (int i = 0;i < M;i++) {
         int t;
         cin >> t;
         queue<string> student_temp;
         for (int j = 0;j < t;j++) {
            string temp;
            cin >> temp;
            student_temp.push(temp);
         }
         vec.push_back(student_temp);
      }

      int combo = 0;
      while (combo != N) {
         int done = 0;
         for (int i = 0;i < M;i++) {
            if (vec[i].front() == professor.front()) {
               combo++;
               done = 1;
               vec[i].pop();
               professor.pop();
               break;
            }
         }

         if (done == 0) {
            answer = 0;
            break;
         }
      }
      cout << answer << '\n';
   }
   return 0;
}