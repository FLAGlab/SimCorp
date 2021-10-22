#include<bits/stdc++.h>
using namespace std;
 
signed main() {
 // your code goes here
 long long t;cin>>t;
    string s;
 while(t--)
 {
        cin>>s;
 if(s.size()%2==0&&s.size()%3==0)
        cout<<"YES"<<endl;
 else cout<<"NO";
 }
 return 0;
}
