#include<bits/stdc++.h>
#define ll long long int
using namespace std;
ll freq[100001];
signed main()
{
	ll n,i,j,k,x,y,l,r,max,size;
	cin>>n;
	ll a[n];
	ll left[100001],right[100001];
 for(i=0;i<100001;i++)
	  left[i]=right[i]=-1;
 for(i=0;i<n;i++)
 {
		cin>>a[i];
		freq[a[i]]++;
 if(left[a[i]]==-1)
		  left[a[i]]=i;
 }
 for(i=n-1;i>=0;i--)
 {
 if(right[a[i]]==-1)
		  right[a[i]]=i;
 }
	max=INT_MIN;
	size=INT_MAX;
 for(i=0;i<100001;i++)
 {
 if(freq[i]==max)
 {
 if(right[i]-left[i]<=size)
 {
				max=freq[i];
				l=left[i];
				r=right[i];
				size=r-l;
 }
 }
 else if(freq[i]>max)
 {
			max=freq[i];
			l=left[i];
			r=right[i];
			size=r-l;
 }
 }
	cout<<l+1<<" "<<r+1<<endl;
 return 0;
}
