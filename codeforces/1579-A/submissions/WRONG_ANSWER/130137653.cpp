#include<bits/stdc++.h>
using namespace std;
 
signed main() {
 // your code goes here
 long long t;cin>>t;
    string s;
 while(t--)
 {
        cin>>s;
 if(s[0]=='B'||s[0]=='C')
        cout<<"YES"<<endl;
 else if(s[0]=='A'&&s[1]=='B'&&s[2]=='C')
        cout<<"NO"<<endl;
 }
 return 0;
}
