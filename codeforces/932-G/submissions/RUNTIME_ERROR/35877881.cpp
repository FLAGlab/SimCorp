#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<map>
 
namespace QiShiBuShiTaoLuTi2333
{
 const int N=100100,INF=1000000007,MOD=1000000007;
 
 inline void inc(int a,int &b){b=(a+b)%MOD;}
 
 struct node
 {
 int pos,delta,k;
 int lastpos(){return pos+delta*(k-1);}
 
		node(int a=0,int b=0,int c=0):pos(a),delta(b),k(c){}
 bool operator < (const node &A) const {return pos<A.pos;}
 };
 
 typedef std::vector<node>::iterator vit;
 
	std::map<int,int> w[N];
	std::vector<node> G[N];
 
 char s[N],t[N];
 int n;
 
 void calc(int p)
 {
		std::vector<node> G0,G1;
 for(auto A:G[p-1])
 {
			node B=A;B.pos--;
 if(t[A.pos-1]==t[p])G0.push_back(B);
 }
 
 for(int i=0;i<(int)G0.size();i++)
 {
 if(!i)
 {
				G1.push_back(node(G0[i].pos,INF,1));
 if(G0[i].k>1)G1.push_back(node(G0[i].pos+G0[i].delta,G0[i].delta,G0[i].k-1));
 }
 else if(G0[i].pos-G0[i-1].lastpos()!=G0[i].delta)
 {
				G1.push_back(node(G0[i].pos,G0[i].pos-G0[i-1].lastpos(),1));
 if(G0[i].k>1)G1.push_back(node(G0[i].pos+G0[i].delta,G0[i].delta,G0[i].k-1));
 }
 else G1.push_back(G0[i]);
 }
 
 if(p>1 && t[p]==t[p-1])
 {
 if(G1.empty())G1.push_back(node(p-1,INF,1));
 else G1.push_back(node(p-1,p-1-G1[G1.size()-1].lastpos(),1));
 }
 
 if(G1.empty())G1.push_back(node(p,INF,1));
 else G1.push_back(node(p,p-G1[G1.size()-1].lastpos(),1));
 
 int tot=0;
		G[p].push_back(G1[0]);
 for(int i=1;i<(int)G1.size();i++)
 {
 if(G[p][tot].delta==G1[i].delta)G[p][tot].k+=G1[i].k;
 else G[p].push_back(G1[i]),tot++;
 }
 }
 
 int f[N];
 
 void initialize()
 {
		scanf("%s",s+1);
		n=strlen(s+1); 
 for(int i=1;i<=n/2;i++)
			t[i*2-1]=s[i];
 for(int i=1;i<=n/2;i++)
			t[i*2]=s[n-i+1];
 }
 
 void solve()
 {
		initialize();
		f[0]=1;
 
 for(int i=1;i<=n;i++)
 {
			calc(i);
 
 for(auto A:G[i])
 {
//				printf("%d , %d , %d\n",A.pos,A.delta==INF?-1:A.delta,A.k);
 
 int x=A.delta,u=A.lastpos();
				inc(f[u-1],w[i][x]);
 
 if(A.k>1)inc(w[i-x][x],w[i][x]);
 }
 
 if(i&1)continue;
 
 for(auto A:w[i])inc(A.second,f[i]);
 
//			printf("f[%d] = %d\n",i,f[i]);
//			printf("--------------\n");
 }
 
		printf("%d\n",f[n]);
 }
}
 
int main()
{
//	freopen("shit.in","r",stdin);
//	freopen("shit.out","w",stdout);
 QiShiBuShiTaoLuTi2333::solve();
 return 0;
}
