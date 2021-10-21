#include <iostream>
#include <algorithm>
using namespace std;
int n,a[100005],b[1000006],mx,f;
main(){
    cin>>n;
 for(int i=0;i<n;++i){
        cin>>a[i];
 ++b[a[i]];
 if(b[a[i]]>b[mx]){
            mx=a[i];
 }
 }
 for(int i=0;i<n;++i){
 if(!f&&a[i]==mx){
            cout<<i+1<<" ";
            f=i+1;
 }else if(a[i]==mx){
            f=i;
 }
 }
    cout<<f+1;
}
