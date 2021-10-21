#include<bits/stdc++.h>
using namespace std;
 
int main(){
 long int n,i=0,max=0,count=0,max_num;
	cin>>n;
 long int a[n+2],b[n+2];
 while(i<n){
	cin>>a[i];b[i]=a[i];i++;
 }
	sort(a,a+n);
	i=0;
 while(i<n){
 if(a[i]==a[i+1])count++;
 else {
 if(count>max){
				max=count+1;
				max_num=a[i];
 }
 }
		i++;
 }
 long int l,r;i=0;int f=0;
 while(i<n){
 if(max_num==b[i]&&!f){
			l=i+1;f=1;
 }
 else if(max_num==b[i]&&f)r=i+1;
		i++;
 }
	cout<<l<<" "<<r<<"\n";
}
