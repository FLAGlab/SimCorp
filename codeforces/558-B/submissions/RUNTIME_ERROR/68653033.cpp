#include<bits/stdc++.h>
using namespace std;
int co[100001],pos[100001];
signed main()
{
 long long n,x,max=0,begin=0,end=10000001;
    cin>>n;
 for(int i=1;i<=n;i++)
 {
        cin>>x;
 if(pos[x]==0) {
            pos[x]=i;
 }
            co[x]++;
 if(co[x]>max||co[x]==max&&i-pos[x]<end-begin){max=co[x];begin=pos[x];end=i;}
 
 }
    cout<<begin<<" "<<end;
 return 0;
}
