#include<bits/stdc++.h>
using namespace std;
long long c[1111],ct[1111],f[1111];
signed main()
{
 long long n,w,b,x;
    scanf("%d%d%d%d",&n,&w,&b,&x);
 long long sum=0;
 for(long long i=1;i<=n;i++)
        scanf("%d",c+i),sum+=c[i];
 for(long long i=1;i<=n;i++)
        scanf("%d",ct+i);
    memset(f,-1,sizeof(f));
    f[0]=w;
 for(long long i=1;i<=n;i++)
 {
 for(long long k=sum;k>=0;k--)
 {
 if(f[k]==-1)continue;
 for(long long j=1;j<=c[i];j++)
 {
 if(j+k<=sum&&f[k]-(ct[i])*j>=0&&f[k]>=ct[i])
                    f[j+k]=max(f[j+k],f[k]-(ct[i]-b)*j);
 if(f[j+k]>w)f[j+k]=w;
 }
 
 }
 for(long long k=0;k<=sum;k++)
 {
 if(f[k]==-1)continue;
            f[k]+=x;
 if(f[k]>w)f[k]=w;
 }
 }
 long long ans=0;
 for(long long i=sum;i>=0;i--)
 if(f[i]!=-1)
 {
        ans=i;
 break;
 }
    cout<<ans<<endl;
 return 0;
}
