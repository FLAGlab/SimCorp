#include<bits/stdc++.h>
using namespace std;
signed main() {
 int t;
	cin >> t;
 while(t--) {
		string s;
		cin >> s;
 int a = 0, b = 0, c = 0;
 for(char C : s) {
 if(C == 'A') a++;
 else if(C == 'B') b++;
 else c++;
 }
 if(b == (a + c)) cout << "YES\n";
 else cout << "NO\n";
 }
 return 0;
}
