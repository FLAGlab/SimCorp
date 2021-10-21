#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define N 200005
using namespace std;
int T,n;
int la[N],fi[N];
struct pl{int num,pos;}s[N];
bool cmp(const pl &A,const pl &B){return A.num<B.num||A.num==B.num&&A.pos>B.pos;}
int main()
{
	scanf("%d",&T);
 while(T--){
		scanf("%d",&n);
 for(int i=1;i<=n;i++) s[i].pos=i,scanf("%d",&s[i].num);
		sort(s+1,s+1+n,cmp);int ans=0;s[0].num=-1;
 for(int i=1;i<=n;i++){
 if(s[i].num!=s[i-1].num) fi[i]=i,la[i]=fi[i-1];
 else fi[i]=fi[i-1],la[i]=la[i-1];
 }
 int li=1;
 for(int i=1;i<=n;i++){
 if(s[i].pos<s[la[i]].pos){
 while(s[li].num<s[la[i]].num) li++;
 while(s[li].num==s[la[i]].num&&s[li].pos>s[i].pos) li++;
 }
			ans=max(ans,i-li+1);
 }
		ans=n-ans;printf("%d\n",ans);
 }
 return 0;
}
