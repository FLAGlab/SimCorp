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
    f[0]=w;ll cnt=0;
 for(i=1;i<=n;i++){
 //cnt+=c[i];
 for(j=cnt;~j;j--){
 for(k=0;f[j]>=k*cost[i]&&k<=c[i];k++){
                f[j+k]=max(f[j+k],min(f[j]+x,(ll)w+j*b)-cost[i]*k);
                cnt=max(cnt,(ll)j+k);
 }
 }
 }
    cout<<cnt<<endl;
 
 return 0;
}
