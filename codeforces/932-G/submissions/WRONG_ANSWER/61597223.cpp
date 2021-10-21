#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include<map>
#define INF 0x3f3f3f3f
#define ll long long
const ll maxn=1e6+5;
const ll mod=1e9+5;
using namespace std;
char str[maxn],s[maxn];
ll n,cnt,f[maxn],g[maxn];
struct node
{
    ll fail,len,last,po;
    ll son[25];
} t[maxn];
void build()
{
    cnt=1;
    t[0].fail=1;
    t[0].len=0;
    t[1].fail=0;
    t[1].len=-1;
    ll now=1;
 for(ll i=1; i<=n; i++)
 {
 while(s[i]!=s[i-t[now].len-1])
            now=t[now].fail;
 if(!t[now].son[s[i]-'a'])
 {
            cnt++;
            ll re=t[now].fail;
 while(s[i]!=s[i-t[re].len-1])
                re=t[re].fail;
            t[cnt].fail=t[re].son[s[i]-'a'];
            t[now].son[s[i]-'a']=cnt;
            t[cnt].len=t[now].len+2;
            t[cnt].po=t[cnt].len-t[t[cnt].fail].len;
 if(t[cnt].po==t[t[cnt].fail].po)
                t[cnt].last=t[t[cnt].fail].last;
 else
                t[cnt].last=cnt;
 }
        now=t[now].son[s[i]-'a'];
 for(ll j=now; j>0; j=t[t[j].last].fail)
 {
            g[j]=f[i-t[t[j].last].len];
 if(t[j].last!=j)
                g[j]=(g[j]+g[t[j].fail])%mod;
 if(i%2==0)
                f[i]=(f[i]+g[j])%mod;
 }
 }
}
int main()
{
    scanf("%s",str);
    n=strlen(str);
 int num=0;
 for(int i=1; i<=n; i+=2)
        s[i]=str[num++];
    num=n-1;
 for(int i=2; i<=n; i+=2)
        s[i]=str[num--];
    f[0]=1;
    build();
    printf("%lld\n",f[n]);
}
 
 
