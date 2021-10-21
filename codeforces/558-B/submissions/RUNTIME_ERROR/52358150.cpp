#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f first
#define s second
#define bp push_back
#define mp make_pair
const int mx=1e5+10;
const double eps=1e-9;
const int inf=1e9;
map<int,int>m;
int a[mx];
main(){
 int n,pos1=0,pos2=0,maxx=0;
    scanf("%d",&n);
 for(int i=1;i<=n;i++){
 int x;
        scanf("%d",&x);
        m[x]++;
 if(!a[x]) a[x]=i;
 if(m[x]>maxx || m[x]==maxx && i-a[x]<pos2-pos1){
            maxx=m[x];
            pos1=a[x];
            pos2=i;
 }
 }
    printf("%d %d",pos1,pos2);
 
 
 
}
