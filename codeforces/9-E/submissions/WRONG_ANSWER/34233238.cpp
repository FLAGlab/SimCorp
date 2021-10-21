#include <algorithm>
#include <assert.h>
#include <bitset>
#include <cctype>
#include <cstring>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
 
typedef long double LD;
typedef long long LL;
typedef pair<LD,LD> PD;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VII;
typedef vector<string> VS;
 
#define VAR(v,n) __typeof(n) v=(n)
#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define FORD(i,a,b) for(int i=(a); i>=(b); i--)
#define FORE(i,c) for(VAR(i,(c).begin()); i!=(c).end(); i++)
 
#define ALL(x) x.begin(),x.end()
#define CLR(A,v) memset((A),v,sizeof((A)))
#define FI first
#define MP make_pair
#define PB push_back
#define SE second
#define SIZE(x) ((int)(x).size())
 
const int n_mx=55;
int E[n_mx];
 
int main() {
 int n,m;
  scanf("%d%d",&n,&m);
 int a,b;
  REP(i,m){
    scanf("%d%d",&a,&b);
 --a; --b;
    E[a]++;
    E[b]++;
 if(E[a] > 2 || E[b] > 2){
      puts("NO");
 return 0;
 }
 }
 //REP(i,n) printf("%d ",E[i]);
 //puts("");
 
  printf("YES\n%d\n",n-m);
 int x=0;
 while(x<n){
 //printf("D %d %d\n",x,E[x]);
 if (E[x] == 0){
      printf("%d %d\n",x+1,x+1);
      x++;
 } else if (E[x]==1){
 int ox=x++;
 while(E[x]==2) x++;
      printf("%d %d\n",ox+1,x+1);
      E[x]++;
 } else {
      x++;
 }
 }
 return 0;
}
