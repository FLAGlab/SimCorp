#include<bits/stdc++.h>
using namespace std;
char str[1000];
signed main(){
 int t;
	cin>>t;
 while(t--){
 int x=0,y=0;
		cin>>str;
 int l=strlen(str);
 for(int i=0;i<l;i++){
 if(str[i]=='B') x++;
 else y++;
 }
		cout<<x<<' '<<y;
 if(x==y){
			printf("YES\n");
 }else{
			printf("NO\n");
 }
 } 
 return 0;
} 
