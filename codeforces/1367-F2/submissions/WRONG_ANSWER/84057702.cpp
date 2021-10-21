#include<bits/stdc++.h>
using namespace std;
 
int main()
{
 int t;
	cin>>t;
 while(t--)
 {
 int n;
		cin>>n;
 
 vector<pair<int,int> > v(n);
 
 int a;
 for(int i=0;i<n;i++)
 {
			cin>>a;
			v[i]={a,i};
 }
		sort(v.begin(),v.end());
 
 int DP[n]={0};
 
		DP[v[0].second]=1;
 for(int i=1;i<n;i++)
 {
 int ind=v[i].second;
 
 if(ind==0)
 {
				DP[ind]=1;
 continue;
 }
 if(v[i-1].second<v[i].second)
 {
				DP[ind]=DP[v[i-1].second]+1;
 }
 else
 {
				DP[ind]=1;
 }
 }
 int ma=0;
 for(int i=0;i<n;i++)
 {
			ma=max(ma,DP[i]);
 }
		cout<<n-ma<<endl;
 }
 return 0;
}
