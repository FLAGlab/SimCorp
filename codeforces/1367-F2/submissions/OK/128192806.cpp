#include <bits/stdc++.h>
using namespace std;
 
#define int long long
 
int Q,n,a[200005],p[200005],f[200005][3],apr[200005],l[200005],r[200005];
 
void lsh_()
{
 vector<int> v;
 for(int i=1;i<=n;i++)
		v.push_back(a[i]);
	sort(v.begin(),v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
 for(int i=1;i<=n;i++)
		a[i] = lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
}
 
signed main()
{
	cin>>Q;
 while(Q--)
 {
		cin>>n;
 for(int i=1;i<=n;cin>>a[i++]);
		lsh_();
 for(int i=0;i<=n+1;i++)
			apr[i] = p[i] = f[i][0] = f[i][1] = f[i][2] = l[i] = r[i] = 0;
 for(int i=n;i>=1;i--)
			l[a[i]] = i, apr[a[i]]++;
 for(int i=1;i<=n;i++)
			r[a[i]] = i;
 for(int i=1;i<=n;i++)
 {
			f[i][0] = f[p[a[i]]][0]+1;
			f[i][2] = max(f[p[a[i]]][2]+1,max(f[p[a[i]-1]][0],f[p[a[i]-1]][1])+1);
 if(i==r[a[i]])
				f[i][1] = f[l[a[i]]][2]+apr[a[i]]-1;
			p[a[i]] = i;
 }
 int ans=0;
 for(int i=1;i<=n;i++)
			ans = max(ans,max(f[i][0],max(f[i][1],f[i][2])));
//		for(int i=1;i<=n;i++)cout<<f[i][0]<<' '<<f[i][1]<<' '<<f[i][2]<<endl;
		cout<<n-ans<<endl;
 }
 
 return 0;
}
