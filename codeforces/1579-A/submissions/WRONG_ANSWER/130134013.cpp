#include <iostream>
using namespace std;
 
int main() {
 // your code goes here
 long long t;cin>>t;
    string s;
 while(t--)
 {
        cin>>s;
 if(s.size()%6==0)
        cout<<"YES"<<endl;
 else cout<<"NO"<<endl;
 }
 return 0;
}
