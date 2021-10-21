#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<map>
#include<list>
#include<queue>
#include<utility>
#include<sstream>
#include<cstdlib>
#include<cctype>
#include<math.h>
#include<set>
#include<stack>
#include<fstream>
#include<numeric>
#include<string>
#include<vector>
#include<iterator>
#define mp make_pair
#define pii pair<int,int>
#define tii pair<int,pii>
#define fs first
#define sc second
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
struct node{
 int len,suff,in[29],diff,smart;
};
#define mx 1005000
node tree[mx];
int ptr=2,curnode=1;
string  str;
char g[mx],g2[mx];
int rev[mx];
int dp[mx][2],dplink[mx][2];
pii ds=mp(mx,mx);
void makepal(int indx)
{
 int temp=curnode;
 while(1){
 int len=tree[temp].len;
 if(indx-len>=1&&str[indx]==str[indx-1-len])break;
        temp=tree[temp].suff;
 }
 if(tree[temp].in[str[indx]-'a']){
        curnode=tree[temp].in[str[indx]-'a'];
        rev[indx]=curnode;
 return ;
 }
    tree[temp].in[str[indx]-'a']=++ptr;
 // dplink[ptr]=mp(mx,ds);
    tree[ptr].len=tree[temp].len+2;
//    tree[ptr].st=indx-tree[ptr].len+1;
 //  tree[ptr].en=indx;
    curnode=ptr;
    rev[indx]=curnode;
    temp=tree[temp].suff;
 if(tree[ptr].len==1){
        tree[ptr].suff=2;
 //tree[ptr].diff=1;
 //  tree[ptr].smart=0;
 return ;
 }
 while(1){
 int len=tree[temp].len;
 if(indx-len>=1&&str[indx]==str[indx-1-len])break;
        temp=tree[temp].suff;
 }
 int s=tree[curnode].suff=tree[temp].in[str[indx]-'a'];
 //  tree[curnode].diff=tree[curnode].len-tree[s].len;
 // if(tree[curnode].diff!=tree[s].diff)tree[curnode].smart=s;
 // else tree[curnode].smart=tree[s].smart;
}
int vis[mx][2];
int dp_func2(int v,int b)
{
 if(v==2)return v;
 if(vis[v][b]!=-1)return vis[v][b];
 if(b==0&&tree[v].len%2==0)return vis[v][b]=v;
 return vis[v][b]=dp_func2(tree[v].suff,0);
}
int sz(int v)
{
 return tree[v].len;
}
#define mod 1000000007
int main()
{
     tree[1].diff=0;
    tree[1].len=-1;
    tree[1].suff=1;
    tree[2].diff=0;
    tree[2].suff=1;
    tree[2].len=0;
    scanf("%s",g);
 int n=strlen(g);
    str+='0';
 
 for(int i=0,j=n-1;i<=j;i++,j--)
 {
        str+=g[i];
        str+=g[j];
 }
 //  cout<<str<<endl;
 for(int i=1;i<str.size();i++)
 {
 //   my[str[i]-97].pb(i);
         makepal(i);
 //  dp[i]=mp(mx,ds);
 }
    memset(vis,-1,sizeof vis);
 for(int i=3;i<=ptr;i++)
 {
 int s=dp_func2(i,1);
        tree[i].suff=s;
 int curnode=i;
        tree[curnode].diff=tree[curnode].len-tree[s].len;
 if(tree[curnode].diff!=tree[s].diff)tree[curnode].smart=s;
 else tree[curnode].smart=tree[s].smart;
 }
    dp[0][0]=1;
    dp[0][1]=0;
 //  cout<<str<<endl;
 for(int i=1;i<str.size();i++)
 {
 if(i&1)continue;
 // if(i!=4)continue;
 int last=dp_func2(rev[i],0);
 for(;tree[last].len>0;last=tree[last].smart){
 int s=tree[last].smart;
 int f=tree[last].suff;
         dplink[last][0]=dplink[last][1]=0;
         dplink[last][0]=(dplink[last][0]+dp[i-(sz(s)+tree[last].diff)][1])%mod;
          dplink[last][1]+=dp[i-(sz(s)+tree[last].diff)][0];
          dplink[last][1]%=mod;
 //  if(i==4)cout<<dplink[last][1]<<endl;
 //  cout<<dp[i-(sz(s)+tree[last].diff)][0]<<" "<<dplink[last][1]<<endl;
 // if(i==4)cout<<dp[last][1]<<" "<<tree[last].len<<" "<<tree[last].smart<<" "<<tree[last].diff<<" "<<(i-(sz(s)+tree[last].diff))<<" "<<dp[0][0]<<endl;
 if(tree[last].diff==tree[tree[last].suff].diff){
               dplink[last][0]=(dplink[last][0]+dplink[f][0])%mod;
                dplink[last][1]=(dplink[last][1]+dplink[f][1])%mod;
 }
 //     if(i==4)cout<<dplink[last][1]<<endl;
            dp[i][0]+=dplink[last][0];
            dp[i][0]%=mod;
               dp[i][1]+=dplink[last][1];
                 dp[i][1]%=mod;
 // if(i==4)cout<<dp[i][1]<<endl;
 }
 //   if(i==4)cout<<dp[i][1]<<endl;
 }
     cout<<dp[str.size()-1][0]<<endl;
}
