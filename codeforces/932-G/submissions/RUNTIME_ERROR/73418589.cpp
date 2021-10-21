#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
inline void Add(int &a,int b)
{a+=b;a>=MOD?a-=MOD:1;}
inline void Sub(int a,int b)
{a-=b;a<0?a+=MOD:1;}
const int Q=1<<17;
char ss[Q],s[Q];
struct dt{
 int st,d,num;
 int sm;
};
vector<dt> g,mem,u;
ll ID(int st,int d,int num)
{return 20000000000LL*st+100005LL*d+num;}
map<ll,int> rem;
int f[Q];
int G(int st,int d,int num)
{
 if(num==1)return f[st-1];
	ll dd=ID(st,d,num);
 if(rem[dd])return rem[dd];
 return (rem[dd]=G(st,d,num-1)+f[st+(num-1)*d-1]);
}
void Upd(dt h)
{rem[ID(h.st,h.d,h.num)]=h.sm;}
void Get(dt &h)
{h.sm=G(h.st,h.d,h.num);}
int main()
{
	scanf("%s",ss+1);
 int nn=strlen(ss+1),n=0;
 for(int i=1,j=nn;i<j;i++,j--)
		s[++n]=ss[i],s[++n]=ss[j];
	s[0]='#',s[n+1]='&';
	f[0]=1;
 for(int i=1;i<=n;i++){
		mem.clear();
 for(dt h:g)
 if(s[i]==s[h.st-1]){
 if(s[i]!=s[h.st+h.d-1])mem.push_back((dt){h.st-1,-1,1,f[h.st-2]});
 else --h.st,Get(h),mem.push_back(h);
 }
 else{
 if(h.num==1)continue;
 Sub(h.sm,f[h.st-1]);
				h.st+=h.d,--h.num;
 Upd(h);
 if(s[i]==s[h.st-1])--h.st,Get(h),mem.push_back(h);
 }
 if(s[i]==s[i-1])mem.push_back((dt){i-1,-1,1,f[i-2]});
		mem.push_back((dt){i,-1,1,f[i-1]});
 for(int j=0;j<(int)mem.size()-1;j++)
 if(mem[j].num==1)mem[j].d=mem[j+1].st-mem[j].st;
		u.clear();
 for(int j=0;j<(int)mem.size();j++)
 if(mem[j].num==1)u.push_back(mem[j]);
 else{
				dt h=mem[j];
 int mr=h.st+(h.num-1)*h.d;
 if(h.d!=mem[j+1].st-mr){
 Sub(h.sm,f[mr-1]);
 --h.num;
 Upd(h);
					u.push_back(h);
					u.push_back((dt){mr,mem[j+1].st-mr,1,f[mr-1]});
 }
 else u.push_back(h);
 }
		g.clear();
 int tp=-1;
 for(int j=0;j<(int)u.size();j++)
 if(tp<0||g[tp].d!=u[j].d)g.push_back(u[j]),++tp;
 else Add(g[tp].sm,u[j].sm),g[tp].num+=u[j].num,Upd(g[tp]);
 if((i&1)^1)
 for(dt h:g)
 Add(f[i],h.sm);
 if(rem.size()>1e7)exit(233);
 }
	printf("%d\n",f[n]);
 return 0;
}
