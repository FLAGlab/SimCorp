#include<bits/stdc++.h>
using namespace std;
int n,m;
int fa[55],e[55][55];//fa用于判断环，e表示有没有边 
int deg[55];//表示度数 
pair<int,int> ans[55];//用ans表示连起来的边，pair储存更方便
int findfather(int x){//找爸爸（雾）
 return fa[x]==x?x:fa[x]=findfather(fa[x]);
}
int main(){
	ios::sync_with_stdio(false);//优化加速 
	cin>>n>>m;
 if(n<m){
		cout<<"NO"<<endl;//如果m比n大显然不行 
 return 0;
 }
 for(int i=1;i<=n;i++) fa[i]=i;//更新父节点
 
 for(int i=1;i<=m;i++){
 int a,b;
		cin>>a>>b;
		e[a][b]=e[b][a]=1;
		deg[a]++;
		deg[b]++;
 if(deg[a]>2||deg[b]>2){
			cout<<"NO"<<endl;//输入的时候就判断 
 //如果度超过了2，肯定不能成一个大环
 return 0;
 }
		fa[findfather(a)]=fa[findfather(b)];
 }
 int num=0;
 for(int i=1;i<=n;i++){
 for(int j=i;j<=n;j++){
 if(findfather(i)!=findfather(j)&&deg[i]<2&&deg[j]<2){
				num++;//注意num
				ans[num]=make_pair(i,j);
				deg[i]++;
				deg[j]++;
				fa[findfather(i)]=findfather(j);
 }
 } 
 }
 if(m+num==n-1){//最后一个点可能没有和第一个点连起来 
		num++;
 for(int i=1;i<=n;i++){
 while(deg[i]<2) { //这里要写while 如果只有俩个点 会被hack掉 
				deg[i]++;
 if(!ans[num].first) ans[num].first=i;
 else ans[num].second=i;
 }
 }
 }
 for(int i=1;i<=n;i++){
 if(findfather(i)!=findfather(1)){
			cout<<"NO"<<endl;
 return 0;
 }
 } 
	cout<<"YES"<<endl<<num<<endl;
 for(int i=1;i<=num;i++){
		cout<<ans[i].first<<" "<<ans[i].second<<endl;
 }
 return 0;
}
