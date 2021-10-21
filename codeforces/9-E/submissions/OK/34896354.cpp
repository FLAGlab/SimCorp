#include<algorithm>
#define For(i,__,___)for(int i=__;i<=___;++i)
#include<cctype>
#include<iostream>
using namespace std;
 
inline int read(){
 int num=0,flag=1;
 char c;
	c=cin.get();
 while((!isdigit(c))&&c!='-')
		c=cin.get();
 if (c=='-')flag=-1;else num+=c-48;
	c=cin.get();
 while(isdigit(c)){
		num=num*10+c-48;
		c=cin.get();
 }
 return num*flag;
}
 
inline void write(int x){
 if(x<0)cout.put('-'),x=-x;
 if(x>9)write(x/10);
	cout.put(x%10+48);
}
 
const int N=55;
int n,m,fa[N],d[N],cnt;
int getf(int x){
 return x==fa[x]?x:fa[x]=getf(fa[x]);
}
 
struct node{
 int x,y;
 bool operator<(const node &B)const{
 return x<B.x||x==B.x&&y<B.y;
 }
}ans[N];
 
int main(){
 int x,y;
	n=read(),m=read();
 For(i,1,n)fa[i]=i;
 For(i,1,m){
		x=read(),y=read();
 if(++d[x]>2||++d[y]>2)
 return puts("NO"),0;
		x=getf(x);y=getf(y);
 if(x!=y)fa[x]=y;
 }
 For(i,1,n)
 For(j,i+1,n)
 if(d[i]<=1&&d[j]<=1&&
 (x=getf(i))!=(y=getf(j))){
				ans[++cnt]=(node){i,j};
				fa[x]=y,++d[i],++d[j];
 }
 For(i,1,n)
 if(d[i]!=2)
 For(j,i+1,n)
 if(d[j]==1){
					ans[++cnt]=(node){i,j};
					fa[getf(i)]=getf(j);
 ++d[i],++d[j];
 }
 For(i,1,n)
 if(!d[i])
			ans[++cnt]=(node){i,i};
	getf(1);
 For(i,2,n)
 if(getf(i)!=fa[1])
 return puts("NO"),0;
	puts("YES");
	sort(ans+1,ans+cnt+1);
	write(cnt);
	puts("\n");
 For(i,1,cnt){
		write(ans[i].x);
		puts(" ");
		write(ans[i].y);
		puts("\n");
 }
 return 0;
}
