#include<bits/stdc++.h>
#define pb push_back
#define bug(x,y) cout<<"x = "<<x<<" y = "<<y<<endl;
#define yo cout<<"ok i reached here\n";
using namespace std;
const int mod = 1e9+7,siz = 1e6+5;
int t,n,m,k,a[siz],l[siz],r[siz],b[siz],dp[siz][3];
int last[siz];
int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
 
    cin>>t;
 while(t--)
 {
        cin>>n;
 for(int i = 1;i<=n;i++) cin>>a[i],b[i] = a[i];
 for(int i = 1;i<=n;i++)
 {
 for(int j = 0;j<3;j++) dp[i][j] = 0;
 }
        sort(b+1,b+1+n);
 map<int,int>mark,cnt; int c = 0;
 for(int i = 1;i<=n;i++) if(mark[b[i]] == 0) mark[b[i]] = ++c;
 for(int i = 1;i<=n;i++) a[i] = mark[a[i]];
 for(int i = 1;i<=n;i++) l[i] = n+5,r[i] = 0,last[i] = 0;
 for(int i=1;i<=n;i++)
 {
            l[a[i]]=min(l[a[i]],i);
            r[a[i]]=max(r[a[i]],i);
            cnt[a[i]]++;
 }
 int ans = 0;
 for(int i = 1;i<=n;i++)
 {
 int z = a[i];
            dp[i][0] = dp[last[z]][0]+1;
            dp[i][1] = max({1+dp[last[z]][1],1+dp[last[z-1]][0],1+dp[last[z-1]][2]});
 if(i == r[z]) dp[i][2] = dp[l[z]][1]+cnt[z]-1;
            ans = max({ans,dp[i][0],dp[i][1]});
            last[z] = i;
 }
        cout<<n-ans<<endl;
 }
}
