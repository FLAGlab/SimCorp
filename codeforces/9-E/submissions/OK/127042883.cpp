#include<bits/stdc++.h>
using namespace std;
int n,m;
int f[55];
int d[55];//表示度数
pair<int,int> ans[55];//用ans表示连起来的边，pair储存更方便
 
int find(int x) //找爸爸（雾）
{
 return f[x]==x?x:f[x]=find(f[x]);
}
 
int main()
{
    cin>>n>>m;
 if(n<m)
 {
        cout<<"NO"<<endl;
 return 0;
 }
 for(int i=1; i<=n; i++)
		f[i]=i;
 
 for(int i=1; i<=m; i++)
 {
 int a,b;
        cin>>a>>b;
        d[a]++;
        d[b]++;
 if(d[a]>2||d[b]>2)
 {
            cout<<"NO"<<endl;//输入的时候就判断
 //如果度超过了2，肯定不能成一个大环
 return 0;
 }
        f[find(a)]=f[find(b)];
 }
 int num=0;
 for(int i=1; i<=n; i++)
 {
 for(int j=i; j<=n; j++)
 {
 if(find(i)!=find(j)&&d[i]<2&&d[j]<2)
 {
                num++;//注意num
                ans[num]=make_pair(i,j);
                d[i]++;
                d[j]++;
                f[find(i)]=find(j);
 }
 }
 }
 if(m+num==n-1) //最后一个点可能没有和第一个点连起来
 {
        num++;
 for(int i=1; i<=n; i++)
 {
 while(d[i]<2) //这里要写while 如果只有俩个点 会被hack掉
 {
                d[i]++;
 if(!ans[num].first) ans[num].first=i;
 else ans[num].second=i;
 }
 }
 }
 for(int i=1; i<=n; i++)
 {
 if(find(i)!=find(1))
 {
            cout<<"NO"<<endl;
 return 0;
 }
 }
    cout<<"YES"<<endl<<num<<endl;
 for(int i=1; i<=num; i++)
 {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
 }
 return 0;
}
