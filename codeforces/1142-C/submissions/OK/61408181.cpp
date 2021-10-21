#include<bits/stdc++.h>
using namespace std;
const int N=1e5+9;
#define ll long long
#define P pair<ll,ll>
P a[N];int n;
bool cmp(P p1,P p2){
 if(p1.first!=p2.first)return p1.first<p2.first;
 return p1.second>p2.second;
}
int q[N],hd,tl;
int main(){
 //freopen("tt.in","r",stdin),freopen("tt.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
 for(int i=1;i<=n;i++)cin>>a[i].first>>a[i].second,a[i].second=a[i].second-a[i].first*a[i].first;
    sort(a+1,a+n+1,cmp);
 int hd=0,tl=-1;
 for(int i=1;i<=n;i++){
 if(tl!=-1&&a[q[tl]].first==a[i].first)continue;
 while(tl>0&&(a[i].second-a[q[tl]].second)*(a[q[tl]].first-a[q[tl-1]].first)>=(a[i].first-a[q[tl]].first)*(a[q[tl]].second-a[q[tl-1]].second))tl--;
        q[++tl]=i;
 }
    cout<<tl<<endl;
 return 0;
}
