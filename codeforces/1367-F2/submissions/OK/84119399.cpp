#include<bits/stdc++.h>
using namespace std;
struct node{
 int z,w,pre,l,last;
}a[200011];
bool cmp(node a,node b)
{
 if(a.z==b.z)
 return a.w<b.w; 
 return a.z<b.z;
}
bool cmp1(node a,node b)
{
 return a.w<b.w;
}
int T,n,dp1[200011],dp2[200011],dp3[200011],maxx;
map<int,int> num,pos,lef;
int main()
{
	cin>>T;
 while(T--)
 {
		lef.clear();
		pos.clear(); 
	maxx=0;
	num.clear();
 //memset(a,0,sizeof(a));
 //memset(dp1,0,sizeof(dp1));
 //memset(dp2,0,sizeof(dp2));
//	memset(dp3,0,sizeof(dp3));
	cin>>n;
 for(int i=1;i<=n;i++)
 {	dp1[i] = dp2[i]= dp3[i] = 0, a[i].l=0,a[i].last=0,a[i].pre=0,a[i].w=0,a[i].z=0;
		cin>>a[i].z;
		a[i].z++;
		num[a[i].z]++;
		a[i].w=i;
 
 }
	sort(a+1,a+n+1,cmp);
 for(int i=1;i<=n;i++)
 {
 if(a[i].z==a[i-1].z)
		a[i].pre=a[i-1].w,a[i].l=a[i-1].l;
 else a[i].pre=a[i].w,a[i].l=a[i-1].w;
 if(a[i].z!=a[i+1].z)
		a[i].last=1;
 if(lef[a[i].z]==0)
		lef[a[i].z]=a[i].w,pos[a[i].z]=a[i].w; 
 }
	sort(a+1,a+n+1,cmp1);
 for(int i=1;i<=n;i++)
 {
		dp1[i]=dp1[a[i].pre]+1;
		dp2[i]=max(dp2[pos[a[i].z]]+1,max(dp1[pos[a[a[i].l].z]]+1,dp3[pos[a[a[i].l].z]]+1));
 if(a[i].last==1)
 {
			dp3[i]=dp2[lef[a[i].z]]+num[a[i].z]-1;
 }
		pos[a[i].z]=i;
		maxx=max(max(maxx,dp1[i]),max(dp2[i],dp3[i]));
 //cout<<dp1[i]<<" "<<dp2[i]<<" "<<dp3[i]<<" "<<a[i].z<<endl;
 }
	cout<<n-maxx<<endl;
 }
} 
