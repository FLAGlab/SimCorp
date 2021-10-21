#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define ZERO (1e-10)
#define INF int(1e9+1)
#define CL(A,I) (memset(A,I,sizeof(A)))
#define DEB printf("DEB!\n");
#define D(X) cout<<"  "<<#X": "<<X<<endl;
#define EQ(A,B) (A+ZERO>B&&A-ZERO<B)
typedef long long ll;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
#define IN(n) int n;scanf("%d",&n);
#define FOR(i, m, n) for (int i(m); i < n; i++)
#define F(n) FOR(i,0,n)
#define FF(n) FOR(j,0,n)
#define FT(m, n) FOR(k, m, n)
#define aa first
#define bb second
void ga(int N,int *A){F(N)scanf("%d",A+i);}
#define MX 64
int C[MX],R[MX],W;
int gc(int a){return C[a]=(a==C[a]?a:gc(C[a]));}
bool con(int a,int b){
 if(gc(a)==gc(b))return 0;
 if(R[C[a]]>R[C[b]])C[C[b]]=C[a];
 else R[C[b]]+=R[C[a]]==R[C[b]],C[C[a]]=C[b];
 return --W,1;
}
#define CLR (iota(C,C+N,0),CL(R,0),W=N)
int a,b,N,M,D[MX];
vii o;
int main(void){
    scanf("%d%d",&N,&M),CLR;
    F(M){
        scanf("%d%d",&a,&b),con(--a,--b);
 if(++D[a]>2||++D[b]>2)return puts("NO");
 }
    puts("YES");
    F(N)FT(i+1,N)if(gc(i)^gc(k)&&D[i]<2&&D[k]<2)con(i,k),o.PB({i,k}),D[i]++,D[k]++;
    F(N)FT(i+1,N)if(D[i]==1&&D[k]==1)D[i]++,D[k]++,o.PB({i,k});
    F(N)FT(i,i+1)if(D[i]==1&&D[k]==1)D[i]++,D[k]++,o.PB({i,k});
    printf("%lu\n",o.size());
 for(auto&h:o)printf("%d %d\n",h.aa+1,h.bb+1);
 return 0;
}
