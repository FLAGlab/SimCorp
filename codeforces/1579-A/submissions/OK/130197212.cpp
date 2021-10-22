#include<bits/stdc++.h>
using namespace std;
signed main(){
 int t;
  cin>>t;
 while(t--){
    string a;
    cin>>a;
 int vet[3]={0};
 for(int i=0;i<(int)a.size();i++)vet[a[i]-'A']++;
 if(vet[1]==vet[0]+vet[2])cout<<"YES\n";
 else cout<<"NO\n";
 }
}
