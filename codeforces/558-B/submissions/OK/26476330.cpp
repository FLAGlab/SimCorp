#include <bits/stdc++.h>
#define LL long long
using namespace std;
int f[1000050],s[1000050],e[1000050];
int main()
{
 int n,x,mx=-1,a,b,d=1e9; cin>>n;
    memset(s,-1,sizeof(s));
 for(int i=0;i<n;i++)
 {
        cin>>x;
 if(s[x]==-1)s[x]=i+1;
        e[x]=i+1;
        f[x]++;
        mx=max(mx,f[x]);
 }
 for(int i=0;i<1e6+10;i++)
 {
 if(f[i]!=mx)continue;
 if(e[i]-s[i]<d)d=e[i]-s[i],a=s[i],b=e[i];
 }
    cout<<a<<" "<<b;
return 0;
}
