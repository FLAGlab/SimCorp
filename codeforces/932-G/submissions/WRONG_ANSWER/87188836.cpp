#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <cmath>
#include <cctype>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll inff = 0x3f3f3f3f3f3f3f3f;
#define FOR(i,a,b) for(int i(a);i<=(b);++i)
#define FOL(i,a,b) for(int i(a);i>=(b);--i)
#define REW(a,b) memset(a,b,sizeof(a))
#define inf int(0x3f3f3f3f)
#define si(a) scanf("%d",&a)
#define sl(a) scanf("%lld",&a)
#define sd(a) scanf("%lf",&a)
#define ss(a) scanf("%s",a)
#define mod ll(1e9+7)
#define pb push_back
#define eps 1e-6
#define lc d<<1
#define rc d<<1|1
#define Pll pair<ll,ll>
#define P pair<int,int>
#define pi acos(-1)
const int N=1e6+8;
char s[N],t[N];
ll g[N],dp[N];
struct PAM{
 struct node{
 int len,fail,son[26],siz,dis,slink;
 void init(int _len=0){
            memset(son,0,sizeof(son));
            fail=siz=0;
            len=_len;
 }
 }tr[N];
 char s[N];
 int num,last;
 void init()
 {
        last=0;num=1;
        tr[0].init();
        tr[1].init(-1);
        tr[0].fail=1;
 }
 int getfail(int x,int n)
 {
 while(s[n-tr[x].len-1]!=s[n]) x=tr[x].fail;
 return x;
 }
 void extend(int x,int n)
 {
 int cur=getfail(last,n);
 int now=tr[cur].son[x];
 if(!now)
 {
            now=++num;
            tr[now].init();
            tr[now].len=tr[cur].len+2;
            tr[now].fail=tr[getfail(tr[cur].fail,n)].son[x];
            tr[now].dis=tr[now].len-tr[tr[now].fail].len;
 if(tr[now].dis==tr[tr[now].fail].dis) tr[now].slink=tr[tr[now].fail].slink;
 else tr[now].slink=tr[now].fail;
            tr[cur].son[x]=now;
 }
        tr[now].siz++;
        last=now;
 }
}A;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ss(s);
 int len=0;
 for(int l=0,r=strlen(s)-1;l<r;l++,r--) t[len++]=s[l],t[len++]=s[r];
    strcpy(A.s,t),A.init();
    dp[0]=1;
    FOR(i,1,len)
 {
        A.extend(t[i-1]-'i',i-1);
 //cout<<i<<"   ds  "<<A.tr[2].dis<<endl;
 for(int x=A.last;x>1;x=A.tr[x].slink)
 {
 
            g[x]=dp[i-A.tr[A.tr[x].slink].len-A.tr[x].dis];
 //if(i==4) cout<<x<<" "<<A.tr[x].dis<<endl;
 if(A.tr[x].dis==A.tr[A.tr[x].fail].dis) g[x]+=g[A.tr[x].fail],g[x]%=mod;
 if(!(i&1)) dp[i]+=g[x],dp[i]%=mod;
 }
 }
    cout<<dp[len]<<endl;
 return 0;
}
