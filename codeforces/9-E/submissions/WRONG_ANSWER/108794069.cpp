#include<bits/stdc++.h>
using namespace std;
int n,m,mat[60],in[60];
vector<int>v[60];
int dfs(int x,int fa){
 for(auto y:v[x]){
 if(y==fa)continue;
 if(in[y]==1)return y;
		mat[y]=-1;
 return dfs(y,x);
 }
}
int main(){
	scanf("%d%d",&n,&m);
 for(int i=1,x,y;i<=m;i++)scanf("%d%d",&x,&y),v[x].push_back(y),v[y].push_back(x),in[x]++,in[y]++;
 for(int i=1;i<=n;i++)if(in[i]>2){puts("NO");return 0;}
 for(int i=1;i<=n;i++){
 if(!in[i]){mat[i]==i;continue;}
 if(in[i]==2||mat[i])continue;
 int j=dfs(i,0);
		mat[i]=j,mat[j]=i;
 }
 for(int i=1;i<=n;i++)if(!mat[i]){puts("NO");return 0;}
	puts("YES");
	printf("%d\n",n-m);
 for(int i=1;i<=n;i++){
 if(mat[i]==-1)continue;
 if(m==n-1){printf("%d %d\n",i,mat[i]);return 0;}
 for(int j=i+1;j<=n;j++)if(j!=mat[i]&&mat[j]!=-1){printf("%d %d\n",i,j);mat[mat[i]]=mat[j],mat[mat[j]]=mat[i],mat[i]=mat[j]=-1;break;}
 }
 return 0;
} 
