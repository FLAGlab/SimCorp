#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
    cin>>t;
 while(t--){
        string s;
        cin>>s;
        cout<<(count(s.begin(),s.end(),'B')*2==s.size()?"YES\n":"NO\n");
 }
}
