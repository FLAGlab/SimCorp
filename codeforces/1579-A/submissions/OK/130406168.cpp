#include<bits/stdc++.h>
 
using namespace std;
 
signed main() {
 int X;
    cin >> X;
 while (X--) {
        string s;
        cin >> s;
        cout << (count(s.begin(), s.end(), 'B') * 2 == s.size() ?
 "YES\n" : "NO\n");
 }
}
 
