#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<int,int> pii;
#define fi first
#define se second
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 int t=1;
    cin>>t;
 while(t--){
 int n,m,i,j,k;
        cin>>n;
        pii a[n];
 for(i=0;i<n;i++){
            cin>>j;
            a[i].fi=j;
            a[i].se=i;
 }
        sort(a,a+n);
        k=1;
        m=1;
 for(i=1;i<n;i++){
 if(a[i].se>a[i-1].se) k++;
 else{
                m=max(m,k);
                k=1;
 }
 }
        m=max(m,k);
        cout<<n-m<<endl;
 
 }
 
 
 
}
