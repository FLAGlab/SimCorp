#include<iostream>
using namespace std;
int t,sl[3];
string s;
int main(){
    cin>>t;
 while(t--){
        cin>>s;
 for(auto i:s) sl[i-'A']++;
 if(sl[0]+sl[2]==sl[1]) cout<<"YES\n";
 else cout<<"NO\n";
        sl[0]=sl[1]=sl[2]=0;
 }
 return 0;
}
