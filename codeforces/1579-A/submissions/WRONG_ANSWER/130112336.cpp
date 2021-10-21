#include <bits/stdc++.h>
using namespace std;
int main(){
 int n;
	cin>>n;
 for(int t=0;t<n;t++){
 int i=0,counta=0,countb=0;
 char ch,str[60];
		cin>>str;
 for(int i=0;i<strlen(str);i++){
 if(str[i]=='B')
				countb++;
 else
				counta++;
 }
 if(counta==countb)
			cout<<"YES";
 else
			cout<<"NO";
 
 }
} 
