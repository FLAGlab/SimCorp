#include <bits/stdc++.h>
#define FLASH ios_base::sync_with_stdio(0);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";
 
 
using namespace std;
 
ll n;
ll x;
set<ll>others;
stack<ll>now;
 
ll ind=0;
vector<pair<ll,ll> >massiv;
 
int main(){
FLASH;
ll T;
cin>>T;
while(T--)
{
 cin>>n;
 ind=0;
 massiv.clear();
 for(ll i=0;i<n;i++)
 {
  ll x;
  cin>>x;
  massiv.pb(mp(x,-i));
 }
 sort(all(massiv));
 ll maxx=0;
 for(ll i=0;i<n;i++)
 {
 if(massiv[i].first!=massiv[i-(ll)now.size()].first)
 {
 while(!now.empty()){others.insert(now.top());now.pop();} 
 } 
 while(!others.empty() && *(others.begin())<massiv[i].second)
 {
	others.erase(massiv[ind].second);
	ind++; 
 }
  now.push(massiv[i].second);
  maxx=max(maxx,(ll)now.size()+(ll)others.size());
 }
 cout<<n-maxx<<endl;
 while(!now.empty())now.pop();
 others.clear();
}
return 0;
}
