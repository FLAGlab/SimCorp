#include <bits/stdc++.h>
using namespace std;
 
int main(){
 int T;cin>>T;
 while(T--){
		string S;cin>>S;
 int a=0,b=0;
 for(int i=0;i<S.size();++i){
 if(S[i]=='B') ++b;
 else ++a;
 }
		printf("%s\n",a==b?"YES":"NO");
 }
 return 0;
}
