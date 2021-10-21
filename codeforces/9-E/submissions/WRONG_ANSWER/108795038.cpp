#include <bits/stdc++.h>
 
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define LL long long
#define pii pair <int,int>
#define pb push_back
#define fi first
#define se second
#define mpr make_pair
 
using namespace std;
 
const LL MOD=1e9+7;
 
int n,m;
vector <pii> g[60],v,ans;
vector <int> pass;
bool vis[60],vise[2510];
 
void dfs(int pos,int stp,int rt)
{
  vis[pos]=true;
  pass.pb(pos);
  rep(i,g[pos].size())
 {
 if(vise[g[pos][i].se]) continue;
 if(g[pos][i].fi==rt)
 {
 if(stp==n-1) puts("YES\n0");
 else puts("NO");
      exit(0);
 }
    vise[g[pos][i].se]=true;
    dfs(g[pos][i].fi,stp+1,rt);
 }
}
 
pii getL()
{
 int mn=1e9,pos;
  pii ret;
  rep(i,v.size())
 {
 if(mn>v[i].fi)
 {
      pos=i;
      mn=v[i].fi;
      ret=v[i];
 }
 if(mn>v[i].se)
 {
      pos=i;
      mn=v[i].se;
      ret=mpr(v[i].se,v[i].fi);
 }
 }
  v.erase(v.begin()+pos);
 return ret;
}
 
int main()
{
  cin>>n>>m;
 int x,y;
  rep(i,m)
 {
    scanf("%d%d",&x,&y);
    g[x].pb(mpr(y,i));g[y].pb(mpr(x,i));
 }
  repn(i,n)
 {
 if(g[i].size()>2)
 {
      puts("NO");
 return 0;
 }
 }
  repn(i,n)
 {
 if(vis[i]) continue;
    pass.clear();
    dfs(i,0,i);
    v.pb(mpr(pass[0],pass.back()));
 }
  pii head=getL();
 int lst=head.fi;
 while(!v.empty())
 {
    pii tmp=getL();
    ans.pb(mpr(lst,tmp.fi));
    lst=tmp.se;
 }
  ans.pb(mpr(lst,head.se));
  puts("YES");
  cout<<ans.size()<<endl;
  rep(i,ans.size()) cout<<ans[i].fi<<' '<<ans[i].se<<endl;
 return 0;
}
 
