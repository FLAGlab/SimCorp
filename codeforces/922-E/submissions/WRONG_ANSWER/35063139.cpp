#include<bits/stdc++.h>
 
using namespace std;
 
long long n,w,b,x;
long long niz[1001],c[1001],d[1001];
 
signed main(){
 //w->Pocetna mana
 //b->Koliko se povecava kapacitet kad se uzme ptica
 //x->Mana koju povrati kad predje na sledeci index
	memset(d,-1,sizeof(d));
	cin>>n>>w>>b>>x;
 for (int i=0;i<n;i++)
		cin>>niz[i];
 for (int i=0;i<n;i++)
		cin>>c[i];
	d[0]=w;
 for (int i=0;i<n;i++){
 for (int j=0;j<niz[i];j++)
 for (int k=1000;k>=1;k--)
 if (d[k-1]!=-1)
					d[k]=max(d[k],d[k-1]-c[i]);
 for (int k=1000;k>=1;k--)
 if (d[k]!=-1)
				d[k]=min(d[k]+x,b*k+w);
 } 
 for (int i=1000;i>=0;i--)
 if (d[i]!=-1){
			cout<<i;
 return 0;
 }
 return 0;
}
