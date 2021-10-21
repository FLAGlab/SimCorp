#include<bits/stdc++.h>
using namespace std;
 
int n,m;
int a[51],par[51];
 
int find(int x){
 if(par[x] == x) return x;
 return par[x] = find(par[x]);
}
 
void mer(int a,int b){
 
	par[find(a)] = find(b);
 
}
 
int main(){
 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
 
	cin>>n>>m;
 
 if(m > n){
		cout<<"NO";
 return 0;
 }
 
	memset(a,0,sizeof a);
 for(int i=0; i<n+1;i++){
		par[i] = i;
 }
 
 for(int i=1; i<=m; i++){
 int c,b;
		cin>>c>>b;
 
		a[c]++;
		a[b]++;
 
 if(a[c] > 2 || a[b] > 2 || (find(c) == find(b) && i!=n)){
			cout<<"NO";
 return 0;
 }
 
		mer(c,b);
 }
 
	cout<<"YES"<<endl<<n-m<<endl;
 
 for(int i=1; i<=n;i++){
 
 while(a[i] < 2){
 
 int j = i + (n!=1);
 for(;j<=n;j++){
 
 if( a[j] < 2 && ( m+1==n || n<=2 || find(i) != find(j) ) ){
					cout<<i<<" "<<j<<endl;
					a[i]++;
					a[j]++;
					m++;
 
					mer(i,j);
 break;
 }
 }
 }
 }
 
}
