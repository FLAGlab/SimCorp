#include<bits/stdc++.h>
 
using namespace std;
 
signed main() {
 int t;
  cin >> t;
 while (t--) {
    string s;
    cin >> s;
 int c[0xFF] = {};
 for (char cc : s) c[cc]++;
    cout << (c['A'] + c['C'] == c['B'] ? "YES" : "NO") << endl;
 }
}
