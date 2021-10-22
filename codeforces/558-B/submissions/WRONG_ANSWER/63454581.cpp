#include<bits/stdc++.h>
 
using namespace std;
map<int,int>A;
int w[1000000];
signed main()
{
 int n,ll=0,k,t,p;
 
	cin>>n;
 
 for(int i=0;i<n;i++)
 {
		cin>>k;
		A[k]++;
 
 if(A[k]==1)
			w[k]=i+1;
 
 else if(1<A[k])
 {
			ll=A[k];
			t=w[k];
			p=i+1;
 }
 
 }
 
	cout<<t<<" "<<p;
}
