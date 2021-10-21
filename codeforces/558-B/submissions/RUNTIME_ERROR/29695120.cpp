#include <bits/stdc++.h>
using namespace std;
int n,y=1;
int A[100005],maxx=INT_MIN,q,minn=INT_MAX,at,visit[100005],topac,x,yat;
map <int,int> mp,tp;
int main()
{
	scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
 //minn=INT_MAX;
		scanf("%d",&A[i]);
		mp[A[i]]++;
 if(mp[A[i]]>maxx)
 {
			maxx=mp[A[i]];
 }
 }
 ////
 for(int i=1;i<=n;i++)
 {
 if(visit[A[i]]==0)
 {
 if(mp[A[i]]==maxx)
 {
 for(int j=n;j>=1;j--)
 {
 if(A[j]==A[i])
 {
						topac=j-i;
 if(topac<minn)
 {
							minn=topac;
							x=i;
							yat=j;
 }
 break;
 }
 }
 }
			visit[A[i]]=1;
 }
 }
 ////
	printf("%d %d",x,yat);
 return 0;
}
