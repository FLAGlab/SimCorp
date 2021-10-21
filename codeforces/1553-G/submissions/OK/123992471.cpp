#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
const int N=3E5+5;
const int M=1E6+5;
int n,m,a[N],maxi,fa[M];
bool have[M],o[M];
vector <int> G[M],to[M],G2[M];
unordered_map <int,bool> flag[M];
vector <int> q;
 
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
    	freopen("1.in","r",stdin);  freopen("1.out","w",stdout); 
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
 for (int i=1;i<=n;i++) 
 {
		q.clear();
 for (int y:G[a[i]+1]) //if (!flag[get(a[i])][get(y)])
 {
			flag[get(a[i])][get(y)]=1;
			q.push_back(get(y));
 }
 for (int x:q)
 for (int y:q) 
 {
				flag[x][y]=1;
 }
 }
 for (int i=1;i<=m;i++)
 {
 int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",work(get(a[x]),get(a[y])));
 }
}
 
