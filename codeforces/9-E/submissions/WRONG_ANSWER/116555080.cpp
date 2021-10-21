#include<bits/stdc++.h>
using namespace std;
int P[51],degree[51]={0};
 
int find_parent(int x)
{
 if(x!=P[x])
	   x=find_parent(P[x]);
 return x;
}
 
int join(int u,int v)
{
 int k=find_parent(u);
    P[v]=k;
}
 
int main()
{
 
 
 #ifndef ONLINE_JUDGE
    freopen("in.txt","r",stdin);
    freopen("ou.txt","w",stdout);
 #endif
 int n,m;
	cin>>n>>m;
 
 for(int i=1;i<=n;i++)
 {
	    P[i]=i;
 }
 
 int u,v;
 int loop=0;
 for(int i=0;i<m;i++)
 {
        cin>>u>>v;
 if(loop>1 || ++degree[u]>2 || ++degree[v]>2)
 {
            cout<<"NO"<<endl;
 return 0;
 }
 if(find_parent(u)==find_parent(v))loop++;
 
        join(u,v);
 }
 if(loop==1)
 {
 if(m==n)
 {
	        cout<<"YES"<<endl;
	        cout<<"0"<<endl;
 }
 else
 {
	     cout<<"NO"<<endl;
 }
 }
	cout<<"YES"<<endl;
	cout<<n-m<<endl;
 
 for(int j=1;j<n;j++)
 {
 for(int k=j+1;k<=n;k++)
 {
 if(degree[j]==2)break;
 if(degree[k]==2)continue;
 if(find_parent(k)==find_parent(j))continue;
	        cout<<j<<" "<<k<<endl;
	        join(j,k);
	        degree[j]++;
	        degree[k]++;
 }
 }
 
 for(int j=1;j<=n;j++)
 {
 if(degree[j]==2)continue;
 if(degree[j]==0)
 {
             cout<<j<<" "<<j<<endl;
 return 0;
 }
 for(int k=j+1;k<=n;k++)
 {
 if(degree[k]==2)continue;
            cout<<j<<" "<<k<<endl;
 return 0;
 }
 }
}
