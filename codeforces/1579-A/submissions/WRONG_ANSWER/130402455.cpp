#include <bits/stdc++.h>
using namespace std;
 
 
int main(){
 int t;
    cin>>t;
 while(t--){
        string s;
        cin>>s;
 map<char,int>m;
 for(auto x:s){
            m[x]++;
 }
 if(m['A']+m['C']==m['C'])
        cout<<"YES"<<endl;
 else
        cout<<"NO"<<endl;
 }
}
