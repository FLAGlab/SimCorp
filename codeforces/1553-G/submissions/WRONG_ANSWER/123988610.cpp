#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <unordered_map>
using namespace std;
const int N=3E5+5;
const int M=1E6+5;
struct data{
 int x,y,p;
}q[N];
int n,m,a[N],maxi,fa[M];
bool have[M],o[M];
vector <int> G[M],to[M];
unordered_map <int,bool> flag[M];
 
int get(int x)
{
 if (fa[x]==x) return x; else return fa[x]=get(fa[x]);
}
 
int work(int x,int y)
{
 if (x==y) return 0;
 if (flag[x][y]||flag[y][x]) return 1;
 return 2;
}
 
int main()
{
 #ifdef WXY_Z
    	freopen("1.in","r",stdin); 
 #endif
	cin>>n>>m;
 for (int i=1;i<=n;i++)
 {
		scanf("%d",&a[i]);
		have[a[i]]=1;
		maxi=max(maxi,a[i]+1);
 }
 for (int i=2;i<=maxi;i++) fa[i]=i;
 for (int i=2;i<=maxi;i++) if (!o[i])
 {
 for (int j=i;j<=maxi;j+=i)
 {
			o[j]=1;
			G[j].push_back(i);
 if (have[j]) fa[get(j)]=get(i);
 }
 }
 for (int i=1;i<=n;i++) to[get(a[i])].push_back(a[i]);
 for (int i=2;i<=maxi;i++)
 for (int x:to[i]) 
 for (int y:G[x+1]) flag[i][get(y)]=1;
 for (int i=1;i<=m;i++)
 {
 int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",work(get(a[x]),get(a[y])));
 }
}
 
