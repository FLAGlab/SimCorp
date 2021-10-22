#include<bits/stdc++.h>
using namespace std;
 
signed main(){
 int t;
     string s;
    cin>>t;
 while(t--){
    cin>>s;
 int c=0;
 for(int i =0 ;i<s.size();i++){
 if(s[i]=='A' || s[i]=='B')
        c++;
 else
        c--;
 }
 if(c) cout<<"NO"<<endl;
 else cout<<"YES"<<endl;
 }
}
