#include<bits/stdc++.h>
using namespace std;
#define pb push_back
long long p[10005],c[10005];
long long w,b,x,n,t;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>w>>b>>x;
 for(int i=0 ; i<n ; i++)
        cin>>c[i];
    cin>>t;
    fill(p,p+10001,-1);
    p[0]=w;
 long long k=1,tw;
    tw=w;
 while(tw-t>=0){
        tw-=t;
        p[k++]=tw;
 }
 int m=c[0];
 
 
 for(int i=0 ; i<=m ; i++){
 if(p[i]!=-1)
            p[i]=min(p[i]+x,w+i*b);
 }
 for(int i=1 ; i<n ; i++){
        cin>>t;
 long long mm=0;
 for(int j=m ; j>=0 ; j--){
 if(p[j]>=mm){
                mm=p[j];
                tw=p[j];
                k=1;
 while(tw-t>=0 && p[j+k]<tw-t && k<=c[i]){
                    tw-=t;
                    p[j+k++]=tw;
 }
 }
 }
        m+=c[i];
 for(int i=0 ; i<=m ; i++){
 if(p[i]!=-1)
                p[i]=min(p[i]+x,w+i*b);
 }
 /*
        for(int ii=0 ; ii<=m ; ii++){
            cout<<p[ii]<<"  ";
        }
        cout<<endl;
        */
 
 }
 for(int i=m ; i>=0 ; i--){
 if(p[i]!=-1){
            cout<<i;
 break;
 }
 }
    cout<<endl;
}
