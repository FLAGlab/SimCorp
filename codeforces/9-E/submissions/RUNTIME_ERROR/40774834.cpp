#include <bits/stdc++.h>
using namespace std;
#define SIZE 4000 + 1
long long  i,j,k,l,r,m,s,t,n,h,a[112136],b[123456],z,c[168456],d[17456],za[1234];
vector <long long> p[400],q;
long long  xx,yy, x,y;
long long find (long long xx){
 while (xx!= c[xx])
        xx=c[xx];
 return xx;
}
int main() {
    cin >> n>>m;
 if (n < m){
        cout << "NO";
 return 0;
 }
 if (n == 1){
        cout <<"YES\n0";
 return 0;
 }
 for (i = 1; i <= n; i ++){
        c[i] = i;
        d[i] = 1;
 }
 for (i = 0; i <m; i ++){
        cin >>x>>y;
 if (x == y) {
            cout <<"NO";
 return 0;
 }
        a[x] ++;
        a[y] ++;
 if (d[x]<d[y])
            swap (x,y);
        d[x] += d[y];
        c[y] = x;
 }
 for (i = 1; i<= n; i ++){
 if (a[i] >2){
            cout <<"NO";
 return 0;
 } 
 if (a[i] == 0){
            q.push_back(i);
            q.push_back(i);
            l++;
 }
 }
 for (i = 1; i <= n; i ++){
 if (za[i] == 0){
            t =0;
 for (j = 1; j<= n; j ++){
 if (find (j) == i){
                    za[j] = 1;
 if (a[j] == 1){
 //cout <<j<<' ';
                        q.push_back(j);
 }
 if (a[j] == 2) 
                        t++;
 }
 }
 
 if (d[find(i)] == t && t < n){
                cout <<"NO";
 return 0;
 }
 if (d[i] == t && t == n){
                    cout << "YES\n0";
 return 0;
 }
 }
 }
    cout <<"YES\n"<<n-m<<'\n';
    q.push_back(q[0]);
 for (i = 1; i <q.size(); i+=2)
        cout << min(q[i],q[i+1])<<' '<<max(q[i],q[i+1])<<endl;
 return 0;
} 
