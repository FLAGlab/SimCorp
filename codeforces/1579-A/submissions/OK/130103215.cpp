#include<cstdio>
#include<cstring>
using namespace std;
int n,s;char c;
int main()
{
	scanf("%d",&n),getchar();
 while(n--)
 {
		s=0;
 while((c=getchar())!='\n')s+=(c=='B'?1:-1);
		printf(s?"NO\n":"YES\n");
 }
 return 0;
}
