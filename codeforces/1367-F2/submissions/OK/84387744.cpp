#include<bits/stdc++.h>
#define int long long
#define ll 			long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<int,int>
#define vi          vector<int>
#define all(a) (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x) (int)x.size()
#define hell        1000000007
#define rep(i,a,b) for(int i=a;i<b;i++)
#define dep(i,a,b) for(int i=a;i>=b;i--)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
using namespace std;
 
#define N  100005
 
void solve()
{
 int n;
	cin>>n;
	vi a(n);
 map<int,vi> m;
	rep(i,0,n)
 {
		cin>>a[i];
		m[a[i]].pb(i);
 }
 int cur=0,r=-1,mx=0;
	vi prev;
 for(auto i:m)
 {
 if(i.S[0]>r)
			cur+=sz(i.S);
 else
 {
 auto lb=lower_bound(all(i.S),r);
			cur+=i.S.end()-lb;
			mx=max(mx,cur);
			lb=lower_bound(all(prev),i.S[0]);
			cur=lb-prev.begin()+sz(i.S);
 }
 for(int j=0;j<sz(i.S);j++)
 {
 int lb=lower_bound(all(prev),i.S[j])-prev.begin();
			mx=max(mx,lb+sz(i.S)-j);
 }
		prev=i.S;
		mx=max(mx,cur);
		r=i.S.back();
 }
	cout<<n-mx<<endl;
}
/*
1
10
0 4 3 3 1 5 4 0 4 3 
0 1 2 3 4 5 6 7 8 9
 
0 - 0 7
1 - 4
3 - 2 3 9
4 - 1 6 8
5 - 5
*/
signed main()
{
	std::ios::sync_with_stdio(false);
 int TESTS=1;
	cin>>TESTS;
 while(TESTS--)
 {
		solve();
 }
 return 0;
} 
