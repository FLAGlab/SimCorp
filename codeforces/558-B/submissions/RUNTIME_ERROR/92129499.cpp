#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005],d[100005];
int n;
int x=1000005;
signed main(){
    cin>>n;
 for(int i=1;i<=n;i++)
    	cin>>a[i];
 for(int i=1;i<=n;i++)
 {
		b[a[i]]++;
 if(c[a[i]])
    		d[a[i]]=i;
 else
 {
    		c[a[i]]=i;
    		d[a[i]]=i;
 }
 }
 int maxx=0;
 for(int i=0;i<=x;i++)
    maxx=max(maxx,b[i]);
 int ans=x;
 int pos1;
 int pos2;
 for(int i=0;i<=x;i++)
 {
 if(b[i]==maxx)
 {
 if(ans>d[i]-c[i])
 {
          ans=d[i]-c[i];
          pos1=c[i];
          pos2=d[i];
 }
 }
 }
    cout<<pos1<<" "<<pos2<<endl;
 
}
 
