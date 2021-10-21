#include<bits/stdc++.h>
#define lint long long
using namespace std;
#define MAXN 10000
map<pair<int,pair<lint,lint>>,lint> m;
 
lint c[MAXN], cost[MAXN];
lint x, w,b;
int n;
lint pd(lint tenho, lint w, lint arv){
 if(m.count({arv,{tenho,w}})!=0) 
 return m[{arv,{tenho,w}}];
	lint val = 0;
 for(int i=0;i<c[arv];i++){
 if(tenho - cost[arv]*i > 0){
			lint novo = 
			pd(min(w+i*b,tenho-i*cost[arv]+x),w+i*b,arv+1)+i;
 if(novo > val) val =novo;
 }
 }
 return m[{arv,{tenho,w}}] = val;
 
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin>>n>>w>>b>>x;
 for(int i=0;i<n;i++)cin>>c[i];
 for(int i=0;i<n;i++)cin>>cost[i];
 
	cout<<pd(w,w,0)+1<<"\n";
 return 0; 
}
 
 
