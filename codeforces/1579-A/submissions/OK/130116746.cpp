#include<bits/stdc++.h>

using namespace std;
signed main(){
 int n=0;
	cin>>n;
 while(n--){
		string op;
		cin>>op;
 int ar[150]={0};
 for(int i=0;i<op.size();i++){
			ar[op[i]]++;
 }
 if(ar[65]+ar[67]==ar[66]){
			printf("YES\n");
 }else printf("NO\n");
 } 
 return 0;
} 
