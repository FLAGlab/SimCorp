#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+233;
int n=0;
int a[MAXN<<1]={0};
int b[MAXN<<1]={0};
signed main()
{
 int btn=0,btrt=0;
	scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
		scanf("%d",&a[i]);
		b[a[i]]++;
 if(b[a[i]]>btrt)
 {
			btrt=b[a[i]];
			btn=a[i];
 }
 }
 int seg[MAXN<<1]={0};
 for(int i=1;i<=n;i++)
 {
 if(a[i]==btn)
 {
			seg[i]=seg[i-1]+1;
 if(seg[i-1]==0)
 {
				printf("%d ",i);
 }
 if(seg[i]==btrt)
 {
				printf("%d",i);
 return 0;
 }
 } 
 else
 {
			seg[i]=seg[i-1]; 
 }
 }
}
//1≤ai≤1e6
