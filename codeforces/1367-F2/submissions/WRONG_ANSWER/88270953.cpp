#include <bits/stdc++.h>
using namespace std;
 
 
using VI = vector<int>;
 
 
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
 
 int t;
  cin >> t;
 while (t--) {
 int n;
    cin >> n;
    VI V(n);
 set<int> S;
 for (int i = 0; i < n; ++i) {
 int x;
      cin >> x;
      V[i] = x;
      S.insert(x);
 }
 
    VI D(S.begin(), S.end());
 for (int& x : V) x = lower_bound(D.begin(), D.end(), x) - D.begin();
 
 int m = D.size();
    VI primer(m + 1, n);
 for (int i = n - 1; i >= 0; --i) primer[V[i]] = i;
 
 int res = 0;
    VI seguits(n + 1);
    VI saltant(n + 1); // nomes el primer, potser
    VI pos(m + 1, n);
 for (int i = n - 1; i >= 0; --i) {
 int x = V[i];
      seguits[i] = 1;
 if (pos[x] < n) seguits[i] = 1 + seguits[pos[x]];
 else if (primer[x+1] > i) seguits[i] = 1 + seguits[pos[x+1]];
      saltant[i] = max(seguits[i], 1 + saltant[pos[x]]);
 if (primer[x+1] > i or pos[x] == n) saltant[i] = max(saltant[i], 1 + seguits[pos[x+1]]);
      res = max(res, saltant[i]);
      pos[x] = i;
 }
    cout << n - res << endl;
 }
}
