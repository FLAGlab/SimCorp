#include <bits/stdc++.h>
using namespace std;
 
vector < pair<int,int> >ans;
int father[60];
int degree[60];
int n,m;
int u[2550],v[2550];
void init(int n){for(int i=1;i<=n;++i) father[i]=i;}
int Find(int x){return father[x]==x?x:Find(father[x]);}
void unit(int x,int y){father[y]=Find(x);}
int main()
{
    scanf("%d%d",&n,&m);
    memset(degree,0,sizeof(degree));
    init(n);
 for(int i=1;i<=m;++i)
 {
        scanf("%d%d",&u[i],&v[i]);
        degree[u[i]]++;degree[v[i]]++;
        unit(u[i],v[i]);
 if(degree[u[i]]>2||degree[v[i]]>2)
 {
            printf("NO\n");
 return 0;
 }
 }
 for(int i=1;i<=n;++i)
 {
 for(int j=1;j<=i;++j)
 {
 if(degree[j]<2&&degree[i]<2&&Find(i)!=Find(j))
 {
                ans.push_back(make_pair(j,i));
                degree[i]++;
                degree[j]++;
                unit(j,i);
 }
 }
 }
 for(int i=1;i<=n;++i)
 {
 if(degree[i]<2)
 {
 for(int j=1;j<i;++j)
 {
 if(degree[j]<2)
 {
                    ans.push_back(make_pair(j,i));
                    degree[i]++;
                    degree[j]++;
                    unit(i,j);
 }
 }
 }
 }
 for(int i=1;i<=n;++i) if(degree[i]==0) ans.push_back(make_pair(i,i));
 for(int i=1;i<=n;++i) if(Find(i)!=Find(1)){printf("NO\n");return 0;}
    printf("YES\n");
    printf("%d\n",ans.size());
    sort(ans.begin(),ans.end());
 for(unsigned int i=0;i<ans.size();i++)
        printf("%d %d\n",ans[i].first,ans[i].second);
 return 0;
}
 
 
