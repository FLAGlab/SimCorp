#include<bits/stdc++.h>
using namespace std;
int a[111111]={0},b[111111][2];
signed main() 
{
 int n;
	cin>>n;
 for(int i=1;i<=n;i++)
 {
 int x;
		cin>>x;
 if(a[x]==0)
			b[x][0]=i;
		a[x]++;
		b[x][1]=i;
 }
 int ma=0,j;
 for(int i=0;i<111111;i++)
 {
 if(a[i]>=ma)
 {
			ma=a[i];
			j=i;
 }
 }
	cout<<b[j][0]<<" "<<b[j][1]<<endl;
}
