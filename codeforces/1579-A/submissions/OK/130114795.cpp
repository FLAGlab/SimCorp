#include<bits/stdc++.h>
 
using namespace std;
 
int n;
string str;
int cnt;
 
signed main() {
	cin>>n;
 while(n--) {
		cnt = 0;
		cin>>str;
 for (char c:str) {
 if(c=='B') cnt++;
 if (c=='A'||c=='C') cnt--;
 }
 if (cnt==0) printf("YES\n");
 else printf("NO\n");
 }
 return 0;
}
