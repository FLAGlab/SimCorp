#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp>
#define ll long long
#define pb push_back
#define vi vector<long long>
#include <ext/pb_ds/assoc_container.hpp> // Common file  
#include <ext/pb_ds/tree_policy.hpp> 
#include <functional> // for less   
using namespace __gnu_pbds; 
using namespace std; 
typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> set1;
ll mod=1000000007;
ll large=1e18;
ll neg=-1e18;
ll N=500000;
ll mod1=998244353;
struct pii
{
   ll x;
   ll y;
};
struct edge
{
   ll from;
   ll to;
   ll w;
   ll id;
};
ll find(ll a,ll p[])
{
 //cout<<"find "<<a<<endl;
 if(a==p[a])
 return a;
 else return p[a]=find(p[a],p);
 
}
void join(ll a,ll b,ll p[],ll sz[])
{
   a=find(a,p);
   b=find(b,p);
 if(a!=b)
 {
 if(sz[a]<sz[b])
      swap(a,b);
 //    cout<<" a "<<sz[a]<<" b "<<sz[b]<<endl;
      sz[a]=sz[a]+sz[b];
 //   cout<<sz[a]<<" haha "<<endl;
      p[b]=a;
 }
}
ll power(ll a,ll b,ll mod)
{
   ll res=1;
 while(b>0)
 {
 if(b&1)
      res=(res*a)%mod;
      b=b/2;
      a=(a*a)%mod;
 }
 return res;
}
ll inverse(ll x, ll p)
{
 return power(x,p-2,p);
}
ll hash1(ll x,ll y)
{
 return x+y+x*y;
}
/*ll f[200000]={0};
 
void ini()
{
   f[0]=1;
   for(ll i=1;i<=200000;i++)
   f[i]=(i*f[i-1])%mod;
}*/
void build(ll tree[],ll v,ll l,ll r,ll dp[])
{
 if(l==r)
      tree[v]=dp[l];
 else
 {
      ll m=(l+r)/2;
      build(tree,2*v,l,m,dp);
      build(tree,2*v+1,m+1,r,dp);
      tree[v]=max(tree[2*v],tree[2*v+1]);
 }
}
ll query(ll tree[],ll v,ll l,ll r,ll tl,ll tr)
{
 if(l==tl && tr==r)
 {
 //  cout<<"max of "<<tl<<" "<<tr<<" "<<tree[v]<<endl;
 return tree[v];
 }
 else
 {
      ll m=(l+r)/2;
 if(tr<=m)
 {
         ll z1= query(tree,2*v,l,m,tl,tr);
 //    cout<<"max of "<<tl<<" "<<tr<<" "<<z1<<endl;
 return z1;
 }
 else if(tl>m)
 {
         ll z2= query(tree,2*v+1,m+1,r,tl,tr);
 //   cout<<"max of "<<tl<<" "<<tr<<" "<<z2<<endl;
 return z2;
 }
 else 
 {
         ll z=query(tree,2*v,l,m,tl,m);
         ll z1=query(tree,2*v+1,m+1,r,m+1,tr);
 //  cout<<"max of "<<tl<<" "<<tr<<" "<<max(z1,z)<<endl;
 return max(z1,z);
 }
 
 
 }
}
void update(ll tree[],ll v,ll l,ll r,ll pos,ll element)
{
 if(l==r && l==pos)
   tree[v]=element;
 else
 {
      ll m=(l+r)/2;
 if(pos<=m)
      update(tree,2*v,l,m,pos,element);
 else
      update(tree,2*v+1,m+1,r,pos,element);
      tree[v]=max(tree[2*v],tree[2*v+1]);
 }
}
 
/*ll ncr(ll n,ll r)
{
   ll res=1;
   ll k=f[n];
   ll v=inverse(f[n-r],mod);
   ll u=inverse(f[r],mod);
   ll x=(u*v)%mod;
   k=(k*x)%mod;
   return k;
}*/
ll max_n=1e6+100;
ll hash2(ll x,ll y,ll W)
{
 return (x-1)*W+y;
}
pii rev(ll u,ll W)
{
   pii ans;
 if(u%W==0)
 {
      ans.y=W;
      ans.x=(u-W)/W+1;
 }
 return ans;
 
}
ll MAX_N=200000;
string tobin(ll a,ll sz)
{
   string s;
   ll r=0;
 while(a>0)
 {
 if(a%2==0)
      s.pb('0');
 else
      s.pb('1');
      a/=2;
      r++;
 }
 while(r<sz)
 {
      s.pb('0');
      r++;
 }
   reverse(s.begin(),s.end());
 return s;
}
ll tolong(string s)
{
   ll sz=s.size();
   ll ans=0;
 for(ll i=0;i<sz;i++)
 {
 if(s.at(i)=='1')
      ans+=(ll)pow(2,sz-i-1);
 
 }
 return ans;
}
ll lower(vector<ll> &x,ll val)
{
 //  cout<<"enter lower with "<<val<<endl;
   ll end=x.size()-1;
   ll start=0;
   ll ans=-1;
 if(end==-1)
 return 0;
 else if(val < x.at(0))
 return ans=0;
 else if( val > x.at(end))
 return ans=end+1;
 else
 {
      ll tt=1;
 while(tt)
 {
         ll mid=end+start;
         mid=mid/2;
 if(val > x.at(mid) && val < x.at(mid+1))
 {
            ans=mid+1;
            tt=0;
 break;
 }
 else if( val > x.at(mid))
 {
            start=mid+1;
 }
 else
 {
            end=mid;
 }
 }
 return ans;
 }
}
ll upper(vector<ll> &x,ll val)
{
 // cout<<"enter upper with "<<val<<endl;
 
   ll end=x.size()-1;
   ll beg=0;
   ll ans=-1;
 // cout<<"val "<<beg<<" "<<end<<endl;
   ll z=x.size();
 /*  for(ll i=0;i<z;i++)
   cout<<x.at(i)<<" ";
   cout<<endl;*/
 if(end==-1)
 return 0;
 else if( val > x.at(end))
 return 0;
 else if( val < x.at(beg))
 return ans=z;
 else
 {
      ll tt=1;
 //  cout<<"here "<<endl;
      ll m=0;
 while(tt)
 {
         ll mid=(beg+end)/2;
         m++;
 /* if(m==5)
         exit(0);
        cout<<"beg "<<beg<<" "<<end<<endl;*/
 if(end-beg<2)
 {
 //  cout<<"enter "<<endl;
 for(ll i=beg;i<=end;i++)
 {
 //  cout<<x.at(i)<<" "<<x.at(i+1)<<endl;
 if(val > x.at(i) && val <x.at(i+1))
 {
                 ans=z-(i+1);
                 tt=0;
 break;
 }
 }
 
 }
 
 else if(val > x.at(mid-1) &&  val < x.at(mid))
 {
            ans=z-mid;
            tt=0;
 break;
 }
 else if( val > x.at(mid) )
 {
            beg=mid;
 }
 else
 {
            end=mid;
 }
 }
 return ans;
 }
}
int main()
{
 
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
 ll t;
 cin>>t;
 while(t--)
 {
    ll n;
    cin>>n;
    ll a[n];
    ll b[n];
 for(ll i=0;i<n;i++){
       cin>>a[i];
       b[i]=a[i];
 }
    sort(b,b+n);
 map<ll,ll> h;
    h[b[0]]=1;
    ll cnt1=1;
 for(ll i=1;i<n;i++)
 {
 if(h.count(b[i])==0){
          cnt1++;
          h[b[i]]=cnt1;
 }
 else
       h[b[i]]=cnt1;
 }
 for(ll i=0;i<n;i++)
 {
       ll x=b[i];
       b[i]=h[b[i]];
       a[i]=h[a[i]];
 }
 /*  for(ll i=0;i<n;i++)
    cout<<a[i]<<" ";
    cout<<endl;
    for(ll j=0;j<n;j++)
    cout<<b[j]<<" ";
    cout<<endl;*/
 vector<ll> list[n+2];
 for(ll i=0;i<n;i++)
 list[a[i]].pb(i);
 /* for(ll i=1;i<=b[n-1];i++)
    {
       ll ss=list[i].size();
       cout<<i<<" : ";
       for(ll j=0;j<ss;j++)
       cout<<list[i].at(j)<<" ";
       cout<<endl;
    }*/
    ll p[n+2];
 for(ll i=0;i<=n+1;i++)
    p[i]=i;
   ll z=b[n-1];
 for(ll i=1;i<=z-1;i++)
 {
      ll k=list[i].size();
      ll k1=list[i+1].size();
 if(k!=0 && k1!=0)
 {
 
         ll u=list[i].at(k-1);
         ll v=list[i+1].at(0);
 //  cout<<i<<" last "<<u<<" "<<i+1<<" first "<<v<<endl;
 if(u<v)
         p[i+1]=p[i];
 }
 }
 /* cout<<"done "<<endl;
   for(ll i=1;i<=z;i++)
   cout<<p[i]<<" ";
   cout<<endl;*/
   ll cnt[z+1]={0};
 for(ll i=0;i<n;i++)
   cnt[a[i]]++;
   ll cum[z+1]={0};
 for(ll i=1;i<=z;i++)
   cum[i]=cum[i-1]+cnt[i];
 /*cout<<"cnt "<<endl;
   for(ll i=1;i<=z;i++)
   cout<<cnt[i]<<" ";
   cout<<endl;
   cout<<"cum "<<endl;
   for(ll i=1;i<=z;i++)
   cout<<cum[i]<<" ";
   cout<<endl;*/
   ll ans=0;
   ll i=1;
 while(i<=z)
 {
 
      ll start=i;
      ll beg=start;
      ll end=i;
      ll j=i;
 while(p[j]==p[i])
 {
         end=j;
         j++;
 }
      ll c=cum[end]-cum[beg-1];
 //   cout<<"start "<<start<<" end "<<end<<endl;
 // cout<<"c with middle "<<c<<endl;
      ll pos1=list[beg].at(0);
      ll d=lower(list[beg-1],pos1);
      ll v=list[end].size();
      ll pos2=list[end].at(v-1);
      ll d1=upper(list[end+1],pos2);
 //    cout<<"d is "<<d<<" d1 is "<<d1<<endl;
      c=c+d+d1;
 //  cout<<"final c "<<c<<endl;
      ans=max(ans,c);
      i=j;
 }
//   cout<<"ans till now "<<ans<<endl;
 for(ll i=1;i<=z-1;i++)
 {
      ll m=list[i].size();
      ll ld=0;
 for(ll j=0;j<m;j++)
 {
         ll f=list[i].at(j);
 //       cout<<i<<"at "<<f<<endl;
         ll v1=j+1;
         ll m1=upper(list[i+1],f);
 //     cout<<"m1 "<<m1<<endl;
         v1+=m1;
         ld=max(ld,v1);
 //   cout<<"joining "<<i<<" "<<i+1<<" with starting "<<i+1<<" starting after "<<f<<" resulting in "<<v1<<endl;
 }
      ans=max(ld,ans);
 }
 //cout<<"ans till now2 "<<ans<<endl;
 for(ll i=1;i<=z;i++)
   ans=max(ans,cnt[i]);
   cout<<n-ans<<endl;
 }
 return 0;
}
