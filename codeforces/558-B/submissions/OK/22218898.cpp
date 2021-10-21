#include<iostream>
#include<cstdio>
using namespace std;
int t[1000000+20];
int s[1000000+20];
int e[1000000+20];
int main(){
 int n,a;
	cin>>n;
 for(int i=1;i<=n;i++){
		cin>>a;
		t[a]++;
 if(s[a]==0){
			s[a]=i;
 }
		e[a]=i;
 }
 int max=t[1];
 int sa=s[1];
 int ea=e[1];
 for(int i=2;i<=1000000;i++){
 if((t[i]>max) || (t[i]==max && e[i]-s[i]<ea-sa)){
			max=t[i];
			sa=s[i];
			ea=e[i];
 }
 }
	cout<<sa<<"  "<<ea;
}
 
