#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll f[10005];
signed main()
{
 int n,w,b,x,i,j,k;
    cin>>n>>w>>b>>x;
    memset(f,0x80,sizeof(f));
 int c[1005],cost[1005];
 for(i=1;i<=n;i++)scanf("%d",&c[i]);
 for(i=1;i<=n;i++)scanf("%d",&cost[i]);
    f[0]=w;ll cnt=0,ans=0;
 for(i=1;i<=n;i++){
        cnt+=c[i];
 for(j=cnt;~j;j--){
 for(k=0;k<=c[i];k++){
 if(f[j-k]<0)continue;
                f[j]=max(f[j],min(f[j-k]+x,(ll)w+(ll)(j-k)*b)-cost[i]*k);
 //cnt=max(cnt,(ll)j+k);
 if(f[j]>=0)ans=max(ans,(ll)j);
 }
 }
 }
    cout<<ans<<endl;
 
 return 0;
}
