#include <iostream>
using namespace std;
 
int main() {
 int t;
  cin>>t;
 while(t--){
    string s;
    cin>>s;
 int a, b=0;
 for(int i=0; i<s.length(); i++){
 if(s[i]=='B'){
        a++;
 } else{
        b++;
 }
 }
 if(a!=b){
      cout<<"NO"<<endl;
 } else{
      cout<<"YES"<<endl;
 }
 }
 return 0;
}
