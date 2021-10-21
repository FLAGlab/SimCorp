#include <bits/stdc++.h>
using namespace std;
static const int MAXN=50;
int fa[MAXN+10],deg[MAXN+10];
int n,m;
bool flag;
int find(int x)
{
 return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
    cin>>n>>m;
 for(int i=1;i<=n;i++) fa[i]=i;
 for(int i=1;i<=m;i++)
 {
 int u,v;
        cin>>u>>v;
        deg[u]++,deg[v]++;
 if(find(u)==find(v)) flag=true;
        fa[fa[u]]=fa[v];
 }
 bool flag1=true;
 for(int i=1;i<=n;i++) if(deg[i]!=2) flag1=false;
 for(int i=2;i<=n;i++) if(find(i)!=find(1)) flag1=false;
 if(flag1)
 {
        cout<<"YES"<<endl<<0<<endl;
 return 0;
 }
 bool flag2=false;
 for(int i=1;i<=n;i++) if(deg[i]>2) flag2=true;
 if(flag2 || m>=n || flag)
 {
        cout<<"NO"<<endl;
 return 0;
 }
    cout<<"YES"<<endl<<n-m<<endl;
 for(int i=1;i<=n;i++)
 for(int j=1;j<=n;j++)
 if(deg[i]<2 && deg[j]<2 && find(i)!=find(j))
 {
                fa[fa[i]]=fa[j];
                deg[i]++,deg[j]++;
                cout<<i<<" "<<j<<endl;
 }
 for(int i=1;i<=n;i++)
 if(deg[i]<2)
 {
            cout<<i<<" ";
 break;
 }
 for(int i=n;i>=1;i--)
 if(deg[i]<2)
 {
            cout<<i<<endl;;
 break;
 }
 return 0;
}
 
