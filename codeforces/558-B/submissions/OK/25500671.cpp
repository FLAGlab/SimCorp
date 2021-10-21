#include<bits/stdc++.h>
using namespace std;
int n,arr[1000007][3],mxp,mnb=1000000000,l,r;
 
int main(){
	cin>>n;
 for(int i=1;i<=n;i++){
 int a;cin>>a;
		arr[a][0]++;
		mxp=max(arr[a][0],mxp);
 if(arr[a][1]==0)arr[a][1]=10000000;
		arr[a][1]=min(arr[a][1],i);
		arr[a][2]=max(arr[a][2],i);
 }
 for(int i=0;i<1000005;i++){
 if(arr[i][0]==mxp){
 if(mnb>arr[i][2]-arr[i][1]+1){
				mnb=arr[i][2]-arr[i][1]+1;
				l=arr[i][2];
				r=arr[i][1];
 }
 }
 }
	cout<<r<<" "<<l<<endl;
}
