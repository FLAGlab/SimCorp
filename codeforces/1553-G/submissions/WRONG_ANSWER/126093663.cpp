#include<bits/stdc++.h>
#define foir(i,l,r) for (register int i=l;i<=r;++i)
#define fopr(i,l,r) for (register int i=l;i>=r;--i)
#define maxn 150010
using namespace std;
 
inline int read()
{
 int x=0;char c=getchar();
 while (!isdigit(c)) c=getchar();
 while (isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
 return x;
}
 
int f[maxn];
int find(int x) { return (f[x]==x)?x:f[x]=find(f[x]); }
 
int n,q;
int a[maxn];
int p[maxn];
 
map<int,int> av[maxn];
 
inline void solve(int x)
{
 int k=a[x];
	foir(i,2,k)
 {
 if (k%i!=0) continue;
 while (k%i==0)
			k/=i;
//		cout<<x<<" "<<i<<endl;
 if (!p[i])
			p[i]=x;
 else
			f[find(x)]=find(p[i]);
 }
}
 
signed main()
{
	n=read();
	q=read();
	foir(i,1,n)
 {
		f[i]=i;
		a[i]=read();
 }
	foir(i,1,n)
		solve(i);
//	foir(i,1,n)
//		cout<<find(i)<<endl;
//	foir(i,1,10)
//		cout<<p[i]<<" ";
//	cout<<endl;
	foir(i,1,n)
 {
 int k=a[i]+1;
		foir(j,2,k)
 {
 while (k%j==0)
				k/=j;
			av[find(i)][find(p[j])]=1;
 }
 }
//	cout<<"giao\n";
	foir(i,1,q)
 {
 int u=read(),v=read();
 if (find(u)==find(v))
			cout<<"0\n";
 else if (av[find(u)][find(v)])
			cout<<"1\n";
 else
			cout<<"2\n";
 }
 return 0;
}
