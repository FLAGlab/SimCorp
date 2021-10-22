#include<bits/stdc++.h>
#define maxn 1000500
using namespace std;
bool pd[maxn+1];
int p[maxn],acc=0,fa[maxn];
int n,q,a[maxn],b[maxn];
int get(int x){
 if(x==fa[x]) return x;
 else return fa[x] = get(fa[x]);
}
int merge(int x,int y){
	x = get(x);
	y = get(y);
	fa[x] = y;
}
map<int,int> MAP[maxn];
signed main(){
	memset(pd,false,sizeof(pd));
 for(int i=2;i<=maxn;i++){
 if(!pd[i])	p[++acc] = i;
 for(int j=1;j<=acc;j++){
 if(p[j] * i > maxn) break;
			pd[p[j] * i] = true;
 if(i%p[j]==0) break;
 }
 }
 for(int i=1;i<maxn;i++)	fa[i] = i;
	cin >> n >> q;
 for(int i=1;i<=n;i++) cin >> a[i],b[a[i]]=i;
 for(int i=1;i<=acc;i++){
 int bc=0;
 for(int j=1;j<=maxn;j++){
 if(p[i]*j>1000000) break;
 if(b[p[i]*j]){
 if(bc!=0) merge(bc,b[p[i]*j]);
				bc = b[p[i]*j];
 } 
 }
 }
 for(int i=1;i<=n;i++){
 int A = a[i],B = a[i]+1;
		A = get(A);
 int j=1;
 while(B > 1){
 while(B%p[j]==0){
				B /= p[j];
 int C = get(p[j]);
 if(MAP[A].find(C)==MAP[A].end()) MAP[A][C] = 1;
 }
			j++;
 }
 }
 int s,t;
 for(int i=1;i <= q;i++){
		cin >> s >> t;
 if(get(s)==get(t)){
			cout<<0<<endl;
 continue;
 }
		s = get(s),t = get(t);
 if(MAP[s].find(t)==MAP[s].end() || MAP[t].find(s)!=MAP[t].end()){
			cout<<1<<endl;
 continue;
 }
		cout<<2<<endl;
 }
 return 0;
}
 
 
 
 
 
 
 
 
 
