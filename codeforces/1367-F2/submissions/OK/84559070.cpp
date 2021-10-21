#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
 
 
void solve()
{
 int n;
    cin>>n;
 vector<int> V(n);
 for(int i=0;i<n;i++)
    cin>>V[i];
 
 vector<pair<int,int> > A(n);
 for(int i=0;i<n;i++)
    A[i]={V[i],-i};
 
    sort(A.begin(),A.end());
 
 set<int> s1,s2;
 int maxx=0,cnt=0;
 for(int i=0;i<n;i++)
 {
 if(A[i].first!=A[i-s1.size()].first)
 {
 for(auto x:s1)
            s2.insert(x);
            s1.clear();
 }
 while(!s2.empty() && *s2.begin()<A[i].second)
 {
            s2.erase(A[cnt].second);
            cnt++;
 }
        s1.insert(A[i].second);
        maxx=max(maxx,(int)(s1.size())+(int)(s2.size()));
 }
    cout<<n-maxx<<endl;
}
int main()
{
 int t;
    cin>>t;
 while(t--)
    solve();
 
}
