#include<bits/stdc++.h>
using namespace std;
#define int long long
int n;
signed main(){
	cin>>n;
 while(n--){
 int cnt[3]={0};
		string s;
		cin>>s;
 for(int i=0;i<s.length();i++)
			cnt[s[i]-'A']++;
 if(cnt[0]+cnt[2]==cnt[1]) cout<<"YES\n";
 else cout<<"NO\n";
 }
}
