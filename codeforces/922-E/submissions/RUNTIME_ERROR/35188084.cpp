#include <iostream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <cmath>
#include <functional>
#include <utility>
#include <vector>
using namespace std;
const int N=123456;
struct node
{
 int no;
 int w;
 int c;
};
vector<node> v[N+1];
int costBirds[N];
int noBirds[N];
int n,w,x,b;
int main()
{
 // freopen("in.txt","r",stdin);
 // freopen("out.txt","w",stdout);
	scanf("%d%d%d%d",&n,&w,&b,&x);
 for(int i=1;i<=n;i++)
		scanf("%d",noBirds+i);
 for(int i=1;i<=n;i++)
		scanf("%d",costBirds+i);
	v[1].push_back({0,w,w});
 for(int i=1;i<=noBirds[1];i++)
 {
 if(v[1][i-1].w-costBirds[1]*i>=0)
			v[1].push_back({i,v[1][i-1].w-costBirds[i]*i,v[1][i-1].c+i*b});
 else 
			v[1].push_back(v[1][i-1]);
 
 }
 for(int i=2;i<=n;i++)
 {
 int maxx=0;
 int maxn=0;
 for(int k=0;k<v[i-1].size();k++)
 {
 if(v[i-1][k].no >= maxx)
 {
				maxx=v[i-1][k].no;
				maxn=k;
 }
 }
		node t=v[i-1][maxn];
 {
 int ww=w;
 int tn=min(ww/costBirds[i],noBirds[i]);
			node temp = {tn,ww-costBirds[i]*tn,ww+tn*b};
 if(temp.no > t.no)
 {
				t=temp;
 }
 }
 for(int j=0;j<=noBirds[i];j++)
 {
			node temp=t;
 for(int k=0;k<v[i-1].size();k++)
 {
 int ww=v[i-1][k].w+x;
 if(ww > v[i-1][k].c)
					ww=v[i-1][k].c;
 if(ww-costBirds[i]*j>=0)
 {
 if(v[i-1][k].no+j >= temp.no)
 {
						temp = {v[i-1][k].no+j,ww-costBirds[i]*j,
							    v[i-1][k].c+j*b};
 }
 }
 
 }
 
			v[i].push_back(temp);
 }
 }
 int maxx=0;
 for(int i=0;i<v[n].size();i++)
 {
		maxx=max(v[n][i].no,maxx);
 }
	printf("%d\n", maxx);
 
}
