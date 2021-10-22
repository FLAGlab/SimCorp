#include<bits/stdc++.h>
 
using namespace std;
 
int n,maks,ansL,ansR,ansP;
struct poin{
 int len=0,l=0,r=0;
};
 
map<int,poin> in;
 
signed main(){
 
	cin>>n;
 for(int x=1;x<=n;x++){
 int a;cin>>a;
		in[a].len++;
 if(in[a].l!=0){
			in[a].r=x;
 }else{
			in[a].l=x;
			in[a].r=x;
 }
		maks=max(maks,in[a].len);
 }
 for(int x=1;x<=1000000;x++){
 if(in[x].len==maks){
 int panjang=in[x].r-in[x].l+1;
 if(ansP<panjang){
				ansL=in[x].l;
				ansR=in[x].r;
 }
 }
 }
	cout<<ansL<<" "<<ansR<<endl;
 
 
 
 
 return 0;
}
