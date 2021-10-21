#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[1234],a[1234];
ll find(ll u)
{
 if (p[u]==u) return u;
	p[u]=find(p[u]);
 return p[u];
}
void mer(ll x, ll y)
{
	p[find(x)]=find(y);
}
 
int main (){
    ll x, y , n , m , i , j ,ans =0 ;
	cin>>n>>m;
 if (m>n){
        cout<<"NO";
 return 0;
 }
 for (i=1;i<=n;i++) p[i]=i;
 for (i=1;i<=m;i++){
		cin>>x>>y;
		a[x]++;
		a[y]++;
 if (find(x)==find(y) && i!=n){
           cout<<"NO";
 return 0;
 }
		mer(x,y);
 }
 
 for (i=1;i<=n;i++)
 if (a[i]>2){
        cout<<"NO";
 return 0;
 }
	cout<<"YES"<<endl;
	cout<<n-m<<endl;
 for (i=1;i<=n;i++)
 while (a[i]<2)
 {
		ans=i+(n!=1);
 for (j=ans;j<=n;j++)
 if (a[j]<2 && (n<=2 || m+1==n || find(i)!=find(j)))
 {
		    cout<<i<<" "<<j<<endl;
		    m++; a[i]++; a[j]++;
            mer(i,j);
 break;
 }
 }
}
