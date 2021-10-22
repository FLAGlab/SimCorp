#include<bits/stdc++.h>
//In the name of Allah
 
 
using namespace std;
 
#define int long long
#define ll long long
#define ld long double
#define pb push_back
#define pf push_front
#define F first
#define S second
#define TL ios::sync_with_stdio(0); cin.tie(0);cout.tie(0);
const int MX=1e3+100,INF=1e18,INF2=-1e18,D=1e9+7;
pair<int,int> ans[MX];
int cost[MX],c[MX];
 
int32_t main(){
    TL
 int n,w,b,x;
    cin>>n>>w>>b>>x;
 for(int i=0; i<n; i++){
        cin>>c[i];
 }
 for(int i=0; i<n; i++){
        cin>>cost[i];
 }
    ans[0].F=w/cost[0];
    ans[0].S=w%cost[0];
 for(int i=1; i<n; i++){
        ans[i].F=w/cost[i];
        ans[i].S=w%cost[i];
 for(int j=0; j<i; j++){
 int k=min(w+(ans[i].F*b),ans[i].S+((i-j)*x));
 int p=min(c[i],k/cost[i]),m=k-(p*cost[i]);
 if(ans[i].F<ans[j].F+p){
                ans[i].F=ans[j].F+p;
                ans[i].S=m;
 }
 else{
 if(ans[i].F==ans[j].F+p&&m>ans[i].S){
                    ans[i].S=m;
 }
 }
 }
 }
    cout<<ans[n-1].F;
 return 0;
}
