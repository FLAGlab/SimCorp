#include <bits/stdc++.h>
using namespace std;
 
int main() {
 int T;
	cin >> T;
 while(T--){
		string s;
		cin >> s;
 int a[3]={0};
 for(int i = 0; i<s.length(); i++) a[s[i]-'A']++;
		cout << (a[0]+a[2]==a[1] ? "YES" : "NO") << '\n';
 }
 return 0;
}
