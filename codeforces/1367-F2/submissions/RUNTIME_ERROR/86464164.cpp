//CODE BY DAKSH
#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define pii         pair<ll,ll>
#define vi          vector<ll>
#define vii         vector<pii>
#define mi          map<ll,ll>
#define mii         map<pii,ll>
#define all(a) (a).begin(),(a).end()
#define F           first
#define S           second
#define mus         multiset<ll>
#define itr         :: iterator
#define pi          3.141592653589793238462
#define setp        fixed << setprecision(6) <<
#define RU(v)       v.resize(distance(v.begin(), unique(all(v))))
using namespace std;
void solve()
{
    ll i,j,k,l,n,m,ans=0;
    string s;
    cin>>n;
    pii a[n];
 vector < vi > b;
    vi c;
 for(i=0;i<n;i++){cin>>a[i].F;a[i].S=i;}
    sort(a,a+n);
 for(i=0;i<n;)
 {   vi z;
 for(j=i;j<n&&a[j].F==a[i].F;j++)
 {
            z.pb(a[j].S);
 }
        sort(all(z));
        b.pb(z);
        i=j;
 }
    c.pb(0);
    ans=b[0].size();
 for(i=1;i<b.size();i++)
 {
 auto it=lower_bound(all(b[i-1]),b[i][0])-b[i-1].begin();
 if(it==b[i-1].size())c[i]=c[i-1];
 else c[i]=0;
        c[i]+=it;
        ans=max(ans,c[i]+1);
 for(j=1;j<b[i].size();j++)
 {
 auto it=lower_bound(all(b[i-1]),b[i][j])-b[i-1].begin();
 if(it==b[i-1].size())it+=c[i-1];
            ans=max(ans,b[i].size()-j+it);
 }
 }
    cout<<n-ans<<"\n";
}
signed main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
 long long int t=1;
    cin>>t;
 while(t--)
 {
        solve();
 }
 return 0;
}
