#include<bits/stdc++.h>
using namespace std;
int main() {
 int T;
	scanf("%d",&T);
 while(T--) {
 int x=0,y=0;
		string A="";
		cin>>A;
 for(int i=0; i<A.size(); i++) {
 if(A[i]=='A'||A[i]=='C')x++;
 if(A[i]=='B')y++;
 }
 if(x==y)printf("YES\n");
 else printf("NO\n");
 }
}
