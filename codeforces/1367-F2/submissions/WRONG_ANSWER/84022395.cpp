#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=2e5+5;
 
 
int32_t main()
{
	IOS;
 int t;cin >> t;
 while(t--)
 {
 int n;
		cin>>n;
 int a[n+1]={0},ans[n+1]={0},b[n+1]={0};
 
 map<int,int>chk;
 
 for(int i=1;i<=n;i++)
 {
				cin >> b[i];
				chk[b[i]]++;
 }
 int k=1;
 for(auto r:chk)
 {
 int y=r.first;
 for(int u=1;u<=n;u++)
 {
 if(b[u]==y)
 {a[u]=k;break;}
 }
			k++;
 }
 int  fans=1;
 for(int i=1;i<=n;i++)
 {
 int cur=a[i];
			ans[cur]=max(ans[cur], ans[cur-1]+1);
			fans=max(fans, ans[cur]);
 }
		cout<<n-fans<<endl;
 }
 return 0;
}
