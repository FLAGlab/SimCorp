#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define  ll long long int
int arr[100002];
int main() {
 int t;
  cin>>t;
 while(t--){
      string s;
      cin>>s;
 map<char,int>mp;
 for(auto c:s){
          mp[c]++;
 }
 if((mp['B']%mp['A'])==mp['C']  or (mp['B']%mp['C'])==mp['A'] ){
          cout<<"YES"<<"\n";
 }
 else{
           cout<<"NO"<<"\n";
 }
 }
 return 0;
}
