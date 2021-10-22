#include<bits/stdc++.h>
using namespace std;
 
signed main()
{ int t;
cin>>t;
while(t--){
    string s;
    cin>>s;
 int a=0,b=0,c=0;
 for(int i=0;i<s.size();i++){
 if(s[i]=='A') a++;
 else if(s[i]=='B') b++;
 else if (s[i]=='C') c++;
 }
 if(b==a+c) cout<<"yes";
 else cout<<"no";
}
 
 return 0;
}
