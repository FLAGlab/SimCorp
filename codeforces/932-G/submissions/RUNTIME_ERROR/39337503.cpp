#include <bits/stdc++.h>
#define MOD 1000000007
#define pb push_back
#define bw(i,r,l) for (int i=r-1;i>=l;i--)
#define fw(i,l,r) for (int i=l;i<r;i++)
using namespace std;
const int N=1000001;
string temp,s; int dp[N],n;
void plusy(int &x,int y) {x+=y; x%=MOD;}
struct palintree {
 struct node {int nxt[26],len,sufflink,l,r,diff,slink;};
	node t[N]; int curnode,sz=0,ans[N];
 void fill(int pos) {memset(t[pos].nxt,-1,sizeof(t[pos].nxt));}
 void init() {
		node r1,r2;
		r1.len=-1; r1.sufflink=0;
		r2.len=0; r2.sufflink=0;
		t[0]=r1; t[1]=r2; sz=1; curnode=0;
		fill(0); fill(1);
 }
 void add(int pos) {
 int cur=curnode;
 while (true) {
 int curlen=t[cur].len;
 if (pos-curlen>0&&s[pos]==s[pos-curlen-1]) break;
			cur=t[cur].sufflink;
 }
 if (t[cur].nxt[s[pos]-'a']!=-1) {curnode=t[cur].nxt[s[pos]-'a']; return;}
		sz++; fill(sz);
		t[cur].nxt[s[pos]-'a']=sz;
		t[sz].len=t[cur].len+2;
		t[sz].r=pos;
		t[sz].l=pos-t[sz].len+1;
		cur=t[cur].sufflink;
		curnode=sz;
 if (t[sz].len==1) {
			t[sz].sufflink=1;
			t[sz].diff=t[sz].len-t[t[sz].sufflink].len;
 if (t[sz].diff==t[t[sz].sufflink].diff) t[sz].slink=t[t[sz].sufflink].slink;
 else t[sz].slink=t[sz].sufflink;
 return;
 }
 while (true) {
 int curlen=t[cur].len;
 if (pos-curlen>0&&s[pos]==s[pos-curlen-1]) break;
			cur=t[cur].sufflink;
 }
		t[sz].sufflink=t[cur].nxt[s[pos]-'a'];
		t[sz].diff=t[sz].len-t[t[sz].sufflink].len;
 if (t[sz].diff==t[t[sz].sufflink].diff) t[sz].slink=t[t[sz].sufflink].slink;
 else t[sz].slink=t[sz].sufflink;
 }
 int getans(int pos) {
 //Starts running from curnode due to the fact of repeating palindromes.
 for (int v=curnode;t[v].len>0;v=t[v].slink) {
			ans[v]=dp[pos-t[t[v].slink].len-t[v].diff];
 if (t[v].diff==t[t[v].sufflink].diff) plusy(ans[v],ans[t[v].sufflink]);
			plusy(dp[pos],ans[v]);
 }
 }
} t;
signed main() {
 //freopen("932.inp","r",stdin);
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin>>temp; n=temp.length();
 /*
	Naive algorithm: Call DP[i]: How many ways to split up to character i and ones from n - i - 1
	to n - 1 into palindromic substrings.
	Now, we calculate which starts would be appropriate. Run a simple loop of j from 0 to i, it's
	correspondent is n - j - 1. Then check if j -> i = n - i - 1 -> n - j - 1. O(N ^ 2)
	Our strings: s[j]...s[j + k]...s[i] = s[n - i - 1]...s[n - i - 1 + k]...s[n - j - 1].
	Since these 2 strings are equal, merge them to create a Palindromic string: At each letter of
	the first one add a letter of the second one in reverse order. So we have
	s[j]s[n - j - 1]...s[i]s[n - i - 1], this is Palindromic and have even length.
	Now we have a new task: Given a string s, count the number of ways to divide it into
	palindromic strings of even - length.
	*/
	fw (i,0,n/2) {s+=temp[i]; s+=temp[n-i-1];}
	t.init(); dp[0]=1;
	fw (i,1,n+1) {
		t.add(i-1); t.getans(i);
 if (i&1) dp[i]=0;
 //Note: We still run getans if i is odd since we still needs the ans variables allocated to it.
 }
	cout<<dp[n];
}
