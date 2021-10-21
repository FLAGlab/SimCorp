#include<bits/stdc++.h>
#define REP(i,n) for (int i = 1; i <= n; i++)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define ll long long int
#define ff first
#define ss second
#define ii pair<ll,ll>
#define vi vector<ll>
#define vii vector<ii>
#define inf 1000000000
#define endl '\n'
const double PI = 3.141592653589793238460;
typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;
 
using namespace std;
 
 
int main()
{
 int n;ll d;
	cin>>n>>d;
 
	vii v;
 
 
 for(int i=0;i<n;i++)
 {
        ll x,y;
        cin>>x;
        cin>>y;
        v.pb(mp(x,y));
 }
 
    sort(v.begin(),v.end());
 
    ll max=0,sum=0,min=0;
 for(int i=0;i<n;i++)
 {
        ll x=v[i].ff;
        ll y=v[i].ss;
 
 if(abs(x-min)<d)
        sum+=y;
 else
 {
            sum=y;
            min=x;
 }
 
 if(sum>max)
        max=sum;
 }
    cout<<max;
 
 return 0;
}
