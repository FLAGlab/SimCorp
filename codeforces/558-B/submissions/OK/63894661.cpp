#include<iostream>
using namespace std;
const int Maxv=1e6+10;
int n,z,y,l[Maxv],r[Maxv],v[Maxv],ans,len,m;
int main()
{
	cin>>n;
 for(int i=1;i<=n;i++){
		scanf("%d",&m);
		v[m]++;
 if(!l[m]) l[m]=i;
		r[m]=i;
		len=r[m]-l[m];
 if(v[m]>ans){
			ans=v[m];
			z=l[m];y=r[m];
 }
 else{
 if(v[m]==ans&&len<y-z){
				z=l[m];y=r[m];
 }
 }
 }
	cout<<z<<' '<<y<<endl;
}
