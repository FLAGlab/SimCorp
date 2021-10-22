#include<bits/stdc++.h>
using namespace std;
 
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define int long long
 
const int N=1e5+5;
 
int n, f=0, diff;
int a[N];
map<int, int> m;
vector<int> v[N];
set<int>s;
 
int32_t main()
{
	IOS;
	cin>>n;
	diff=n;
 for(int i=1;i<=n;i++)
 {
		cin>>a[i];
		s.insert(a[i]);
		m[a[i]]++;
		f=max(f, m[a[i]]);
		v[a[i]].push_back(i);
 }
 int l=1, r=n;
 for(auto it=s.begin();it!=s.end();it++)
 {
 if(v[*it].size()==f)
 {
 int curdiff=v[*it].back() - v[*it][0];
 if(curdiff<diff)
 {
				diff=curdiff;
				l=v[*it][0];
				r=v[*it].back();
 }
 }
 }
	cout<<l<<" "<<r;
 return 0;
}
