#include<iostream>
#include<vector>
using namespace std;
#define pii pair<int,int> 
const int N=60;
 
int n,m;
int f[N];
int d[N];
vector<pii> ans;
int cnt;
 
int find(int x)
{
 if(x==f[x]) return x;
 return f[x]=find(f[x]);
}
 
int main()
{
	cin>>n>>m;
 if(m>n)
 {
		puts("NO");
 return 0;
 }
 for(int i=0;i<=n;i++)
		f[i]=i;
 for(int i=0;i<m;i++)
 {
 int a,b;
		cin>>a>>b;
		d[a]++,d[b]++;
 if(d[a]>2||d[b]>2)
 {
			puts("NO");
 return 0;
 }
 
 int fa=find(a),fb=find(b);
		f[fa]=fb;
		cnt++;
 }
 
 for(int i=1;i<=n;i++)
 {
 for(int j=i;j<=n;j++)
 {
 int fa=find(i),fb=find(j);
 if(fa!=fb&&d[i]<2&&d[j]<2)
 {
				d[i]++,d[j]++;
				f[fa]=fb;
				ans.push_back({i,j});
				cnt++;
 }
 }
 }
 
 if(cnt==n-1)
 {
 int a=0,b=0;
 for(int i=1;i<=n;i++)
 {
 while(d[i]<2)
 {
				d[i]++;
 if(a==0) a=i;
 else b=i;
 }
 }
		ans.push_back({min(a,b),max(a,b)});
 }
 
 for(int i=1; i<=n; i++)
 {
 if(find(i)!=find(1))
 {
            cout<<"NO"<<endl;
 return 0;
 }
 }
 
	cout<<"YES"<<endl<<ans.size()<<endl;
 for(int i=0;i<ans.size();i++)
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
 return 0;
}
