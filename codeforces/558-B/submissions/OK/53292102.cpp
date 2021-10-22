#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,A[1000000],L[1000000],x,y,maks;
 
signed main(){
  cin>>n;
 for(int i=1;i<=n;i++){
    cin>>m;
    A[m]++;
 if(A[m]==1){
      L[m]=i;
 }
 if(A[m]>maks){
      maks=A[m];
      x=L[m];
      y=i;
 } else if(A[m]==maks){
 if(y-x>i-L[m]){
        x=L[m];
        y=i;
 }
 }
 }
  cout<<x<<" "<<y<<"\n";
 return 0;
}
