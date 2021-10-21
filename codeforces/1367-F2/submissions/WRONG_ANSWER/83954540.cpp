#include "bits/stdc++.h"
using namespace std;
 
int main(){
 
 int t;
     cin>>t;
 
 while(t--)
 {
 int n;
          cin>>n;
 
 int ar[3]={0};
 
 for(int i=0;i<n;i++) 
 {
 long long a;
               cin>>a;
 if(a%2!=i%2) ar[i%2]++;
 
 
 }
 
 if(ar[0]!=ar[1]) cout<<-1<<endl;
 
 else cout<<ar[0]<<endl;
 
 }
 return 0;
}
