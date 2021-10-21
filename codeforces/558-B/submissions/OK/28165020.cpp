#include <bits/stdc++.h>
 
using namespace std;
 
int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
 int n;
  cin >> n;
 vector<int> a(n), L(1000001, 1e9), R(1000001), C(1000001);
 for (int i = 1; i <= n; i++) {
 int t;
    cin >> t;
    C[t]++;
    L[t] = min(L[t], i);
    R[t] = max(R[t], i);
 }
 int p = 0;
 for (int i = 1; i <= 1000000; i++) {
 if (C[i] > C[p] || C[i] == C[p] && R[i] - L[i] < R[p] - L[p]) {
      p = i;
 }
 }
  cout << L[p] << " " << R[p] << endl;
 return 0;
}
