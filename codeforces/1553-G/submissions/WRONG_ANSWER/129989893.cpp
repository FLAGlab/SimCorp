#include<bits/stdc++.h>
using namespace std;
int f0[5000005],f1[5000005];
int zys(int *glc,int a){
//	cout<<"|	a="<<a<<endl;
 if(glc[a]==a){
 return a;
 }
	glc[a]=zys(glc,glc[a]);
 return glc[a];
}
int prime[2000005],a[1000005];
bool mark[2000005];
//#define P for(int wba=0;wba<(n<<1);wba++){cout<<f0[wba]<<" ";}cout<<endl;
signed main(){
 int n,q,i,j,A,B,sum=0;
	cin>>n>>q;
 for(i=0;i<=2000000;i++){
		f0[i]=f1[i]=i;
 }
	prime[0]=2;
 for(i=2;i<=1234567;i++){
 if(!mark[i]){
			prime[sum++]=i;
 }
 for(j=0;j<sum&&i*prime[j]<=1234567;j++){
			mark[i*prime[j]]=1;
 if(i%prime[j]==0){
 break;
 }
 }
 }
 for(i=0;i<n;i++){
		scanf("%d",a+i);
//		cout<<"i="<<i<<",a="<<a[i]<<endl;
 for(j=0;prime[j]<=a[i]+1;j++){
//			cout<<"|	j="<<j<<",prime="<<prime[j]<<endl;
 if(!(a[i]%prime[j])){
//				cout<<"|	[0]连接"<<i<<"和"<<(n<<1)+j<<endl;
				f0[zys(f0,i)]=f0[zys(f0,(n<<1)+j)];
				f1[zys(f1,i)]=f1[zys(f1,(n<<1)+j)];
 }
 if(!((a[i]+1)%prime[j])){
//				cout<<"|	[1]连接"<<i+n<<"和"<<((n<<1)+j)<<endl;
				f1[zys(f1,i+n)]=f1[zys(f1,(n<<1)+j)];
 }
 }
 }
 for(i=0;i<q;i++){
		scanf("%d %d",&A,&B);
		A--;
		B--;
 if(a[A]==a[B]||zys(f0,A)==zys(f0,B)){
			cout<<0<<endl;
 }else if(zys(f1,A+n)==zys(f1,B)||zys(f1,A)==zys(f1,B+n)){
			cout<<1<<endl;
 }else{
			cout<<2<<endl;
 }
 }
 return 0;
}
/*
2 1
5 77
1 2
ans:2
*/
