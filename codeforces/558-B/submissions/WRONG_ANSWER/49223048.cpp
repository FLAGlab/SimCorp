#include <bits/stdc++.h>
using namespace std;
 
#define  ll long long
 
int main(int argc, char const *argv[])
{
 int n;
	cin>>n;
	ll*arr = new ll[n];
 unordered_map<ll,int>h;
 int x = 0;
	ll elem;
 int w,y;
 for (int i = 0; i < n; ++i)
 {
		cin>>arr[i];
		h[arr[i]]+=1;
 if(h[arr[i]]>x){
			x = h[arr[i]];
			elem = arr[i];
 }
 }
 int ofbit = 0;
 for(int i=0;i<n;i++){
 if(arr[i]==elem){
 if(!ofbit){
				w = i;
			ofbit = 1;
 }
 else{
				y = i;
 }
 
 }
 }
	cout<<w+1<<" "<<y+1;
 return 0;
}
