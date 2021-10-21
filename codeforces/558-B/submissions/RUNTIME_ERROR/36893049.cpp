#include <bits/stdc++.h>
using namespace std;
 
int x[100010],r[100010],l[100010],ansl,ansr,maks,n,a;
bool p;
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin>>n;
	maks=-1;
 for(int i=1;i<=n;i++){
		cin>>a;
		x[a]++;
 if(x[a]==1){
			l[a]=i;
 }
		r[a]=i;
 if(x[a]>maks){
			ansl=l[a];
			ansr=r[a];
			maks=x[a];
 }
 else if(x[a]==maks){
 if(r[a]-l[a]<=ansr-ansl){
				ansl=l[a];
				ansr=r[a];
 }
 }
 }
	cout<<ansl<<" "<<ansr<<endl;
 
 return 0;
}
