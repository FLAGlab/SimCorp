#include <bits/stdc++.h>
#define MAXN 300005
#define MAXM 26
#define MOD 1000000007
using namespace std;
inline int read(){
 int x=0,f=1;
 char ch=getchar();
 while(ch<'0'||ch>'9'){
 if(ch=='-') f=-1;
		ch=getchar();
 }
 while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
 }
 return x*f;
}
char s[MAXN];
namespace PalindromicAutoMaton{
 int trie[MAXN][MAXM],len[MAXN],fail[MAXN],cnt[MAXN];
 int d[MAXN],top[MAXN];//公差相等的链的公差，和顶端
 int tot,last;
 int now;
 void Build(){
		tot=1;
		len[0]=0;
		fail[0]=1;
		len[1]=-1;
		fail[1]=0;
		last=0;
		now=0;//现在的长度
 }
 int New(int l){
		tot++;
		memset(trie[tot],0,sizeof(trie[tot]));
		len[tot]=l,fail[tot]=0;
 return tot;
 }
 int GetFail(int x){
 while (s[now-len[x]-1]!=s[now]) x=fail[x];
 return x;
 }
 void Add(int ch){
		now++;
 int cur=GetFail(last);
 if (!trie[cur][ch]){
 int nd=New(len[cur]+2);//长度为len[cur]+2
			fail[nd]=trie[GetFail(fail[cur])][ch];//其实就是要维护fail[nd]
 // chain[nd]=chain[fail[nd]]+1;
			d[nd]=len[nd]-len[fail[nd]];
			top[nd]=(d[nd]==d[fail[nd]]?top[fail[nd]]:fail[nd]);
 //如果处于链的下面，再接上一个
 //如果处于链的顶端，那么新建
			trie[cur][ch]=nd;
 }
		cnt[trie[cur][ch]]++;
		last=trie[cur][ch];
 }
}
using namespace PalindromicAutoMaton;
char t[MAXN];
int sum[MAXN];//每个点到链顶的信息
int dp[MAXN];//答案
int main(){
	scanf("%s",t+1);
 int n=strlen(t+1);
 int ptr=0;
 for (int i=1,j=n;i<=j;i++,j--){
		s[++ptr]=t[i];
		s[++ptr]=t[j];
 }
 Build();
	dp[0]=1;
 for (int i=1;i<=n;++i){
 Add(s[i]-'a');
 for (int p=last;p>1;p=top[p]){//每次都跳到这条链的顶端，是log(n)的
			sum[p]=dp[i-len[top[p]]-d[p]];//这条链顶端以上的答案
 if (d[p]==d[fail[p]]){//一条链上
 (sum[p]+=sum[fail[p]])%=MOD;//加上这条链的贡献
 }
 if (i%2==0) (dp[i]+=sum[p])%=MOD;//注意只有偶数才转移
 }
 }
	printf("%d\n",dp[n]);
 return 0;
}
