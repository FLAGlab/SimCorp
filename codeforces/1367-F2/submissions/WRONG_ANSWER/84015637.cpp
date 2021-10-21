#include<bits/stdc++.h>
#define int long long
#define FLASH cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
#define FILEIO freopen("/home/aman/Desktop/Kachda/input.txt", "r", stdin); //freopen("/home/aman/Desktop/Kachda/output.txt", "w", stdout);
using namespace std;
 
int n;
pair<int, int>a[30001];
void solv(){
	cin>>n;
 for(int i = 1; i <= n; i++){
		cin>>a[i].first;
		a[i].second = i;
 }
	sort(a + 1, a + n + 1);
 
 int curlen = 0, maxlen = 0;
 for(int i = 1; i <= n; i++){
 if(a[i].second < a[i - 1].second){
			curlen = 1;
 }
 else curlen++;
		maxlen = max(maxlen,  curlen);
 }
 int ans = n - maxlen;
	cout<<ans<<'\n';
}
 
signed main()
{
 #ifndef ONLINE_JUDGE
	FILEIO
 #endif
	FLASH
 
 int t;
	cin>>t;
 
 while(t--) solv();
}
