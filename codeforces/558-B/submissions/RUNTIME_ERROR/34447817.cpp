#include<bits/stdc++.h>
using namespace std;
#define ll long long
pair<int,int> a[100003];
int f[3][100005];
signed main()
{
 int n;
	cin>>n;
 int b[n+1];
 int min=n;
 int r;
 int max=0;
 int h=0,s=0;
 for(int i=0;i<n;i++)
 {
		cin>>r;
 if(f[0][r]==0)
 {
			f[0][r]=1;
			f[1][r]=i+1;
 }
 else if(f[0][r]!=0)
 {
			f[2][r]=i+1;
			f[0][r]++;
 }
 if(f[0][r]>=max)
 {
			max=f[0][r];
 }
 }
 for(int i=0;i<n;i++)
 {
 if(f[0][i]==max)
 {
 int t=f[2][i]-f[1][i];
 if(t>0&&t<min)
 {
				min=t;
				h=f[1][i];
				s=f[2][i];
 }
 }
 }
	cout<<h<<" "<<s;
 
 return 0;
}
