#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=55;
int n,m,flag,pre[maxn];
int d[maxn],cnt;
vector<pair<int,int> > ans;
int Find(int x){
 return x==pre[x]?x:pre[x]=Find(pre[x]);
}
int main(){
    scanf("%d%d",&n,&m);
 for(int i=1;i<=n;i++)pre[i]=i;
 for(int i=0;i<m;i++){
 int u,v;
        scanf("%d%d",&u,&v);
        d[u]++;d[v]++;
        pre[Find(u)]=Find(v);
 }
 for(int i=1;i<=n;i++){
 if(d[i]>2){
            puts("NO");return 0;
 }
 }
 for(int i=1;i<=n;i++){
 for(int j=i;j<=n;j++){
 if(Find(i)!=Find(j)&&d[i]<2&&d[j]<2){
                pre[Find(i)]=Find(j);
                d[i]++;
                d[j]++;
                ans.push_back(make_pair(i,j));
                cnt++;
 }
 }
 }
 if(m+ans.size()==n-1){
        ans.push_back(make_pair(0,0));
        cnt++;
 for(int i=1;i<=n;i++){
 while(d[i]<2){
                d[i]++;
 if(ans[cnt-1].first==0)ans[cnt-1].first=i;
 else{
                    ans[cnt-1].second=i;
 }
 }
 }
 }
 for(int i=1;i<=n;i++){
 if(Find(i)!=Find(1)){
            puts("NO");return 0;
 }
 }
    puts("YES");
    printf("%d\n",cnt);
 for(int i=0;i<cnt;i++){
        printf("%d %d\n",ans[i].first,ans[i].second);
 }
 return 0;
}
/*
4 3
2 1
2 3
2 4
*/
