#include<bits/stdc++.h>
using namespace std;
 
int main(){
int t;
cin>>t;
while(t--){
string s;
cin>>s;
int x=0,y=0,z=0;
for(int i=0;i<s.length();i++){
 if (s[i]=='A') x++;
 if (s[i]=='B') y++;
 if (s[i]=='C') z++;
}
if (y==x+z) cout<<"YES\n";
else cout<<"NO\n";
 
 
 
}
}
