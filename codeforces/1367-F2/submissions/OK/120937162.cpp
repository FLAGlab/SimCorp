#include<bits/stdc++.h>
using namespace std;
#define pa pair<int,int>
const int N=2e5+5;
set<int>s;
int st[N],top;
pa a[N];
int main()
{
 int t;
    scanf("%d",&t);
 while(t--){
 int n,x;
        scanf("%d",&n);
 for(int i=1;i<=n;i++)
            scanf("%d",&x),a[i]={x,-i};
        sort(a+1,a+1+n);
 int ans=0,l=1;
 for(int i=1;i<=n;i++){
 if(a[i].first!=a[i-top].first)
 while(top)
                    s.insert(st[top--]);
 while(!s.empty()&&*s.begin()<a[i].second)
                s.erase(s.find(a[l++].second));
            st[++top]=a[i].second;
            ans=max(ans,top+(int)s.size());
 }
        printf("%d\n",n-ans);
        s.clear(),top=0;
 }
 return 0;
}
