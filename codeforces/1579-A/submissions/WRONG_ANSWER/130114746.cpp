#include<bits/stdc++.h>
using namespace std;
int main(){
 int t;
    cin>>t;
 while(t--){
    string s;
    cin>>s;
 int n=s.size();
 int b=0;
 for(int i=0;i<n;i++){
 if(s[i]=='B')
        b++;
 }
 if(n%2!=0||b!=(n/2))
    cout<<"No"<<endl;
 else
    cout<<"No"<<endl;
 
 }
}
