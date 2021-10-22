#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
    cin>>t;
 while(t--){
 char s[50];
    cin>>s;
 int l = strlen(s);
    sort(s,s+l);
    cout<<s;
 }
 return 0;
}
