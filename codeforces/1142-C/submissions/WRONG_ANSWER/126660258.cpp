#include <bits/stdc++.h>
using namespace std;
struct nod{
 int x, y;
}p[1000007];
long long cross(nod a, nod b){
 return 1LL * a.x * b.y - 1LL * a.y * b.x;
}
int a[1000007], b[1000007], n, d[1000007];
int r;
bool cmp(nod a,nod b){
 if (a.x == b.x) return a.y > b.y;
 return a.x > b.x;
}
nod sub(nod x, nod y){
	nod ans;
	ans.x = x.x - y.x;
	ans.y = x.y - y.y;
 return ans;
}
int main(){
	cin >> n;
 for (int i = 0; i < n; i++){
 int x, y;
		scanf("%d %d",&x, &y);
		p[i].x = x;
		p[i].y = y - 1LL * x * x;
 }
	sort(p, p + n, cmp);
	r = 0;
	d[0] = 0;
 for (int i = 1; i < n; i++){
 if (p[i].x == p[i - 1].x) continue;
 while (r >= 1 && cross(sub(p[d[r - 1]], p[d[r]]), sub(p[i], p[d[r]])) >= 0) r--;
		d[++r] = i;
 }
	printf("%d\n", r);
}
 
