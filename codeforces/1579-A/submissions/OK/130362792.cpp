#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int t;
	cin >> t;
 while (t--) {
		string s;
		cin >> s;
 int cnt = 0;
 for (int i = 0; i < s.size(); i++)
 if (s[i] == 'B')
				cnt++;
		cout << (cnt * 2 == s.size() ? "yes\n" : "no\n");
 }
 return 0;
}
