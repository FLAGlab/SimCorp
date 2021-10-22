#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+23;
int n=0;
int a[MAXN]={0};
signed main()
{
 map<int, int> tb; 
 int btn=0,btrt=0;
	scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
		scanf("%d",&a[i]);
		tb[a[i]]++;
 if(tb[a[i]]>btrt)
 {
			btrt=tb[a[i]];
			btn=a[i];
 }
 }
 for(int i=1;i<=n;i++)
 {
 if(a[i]==btn)
 {
			printf("%d ",i);
 break;
 }
 }
 for(int i=n;i>=1;i--)
 {
 if(a[i]==btn)
 {
			printf("%d",i);
 break;
 }
 }
}
//1≤ai≤1e6
