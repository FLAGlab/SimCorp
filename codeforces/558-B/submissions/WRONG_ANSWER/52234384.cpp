#include<bits/stdc++.h>
using namespace std;
 
int main(){
 int n;
  cin>>n;
 
 int a[n], l[1000001]={0}, r[1000001]={0}, f[1000001]={0}, maxf=0, minl=2000000, k;
 
 for(int i=0;i<n;i++){
    cin>>a[i];
 if(!l[a[i]]) l[a[i]]=i+1;
 else r[a[i]]=i+1;
    f[a[i]]++;
 if(maxf<f[a[i]]) maxf=f[a[i]];
 }
 for(int i=0;i<n;i++){
 if(f[a[i]]!=maxf) continue;
 if(minl>r[a[i]]-l[a[i]]) {minl=r[a[i]]-l[a[i]]; k=a[i];}
 }
  cout<<k<<endl;
  cout<<l[a[k]]<<" "<<r[a[k]]<<endl; 
 return 0;
}
