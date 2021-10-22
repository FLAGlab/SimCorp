#include<bits/stdc++.h>
using namespace std;
vector<int> vec[1000005];
signed main()
{
 int n,a;
	scanf("%d",&n);
 for(int i=1;i<=n;i++)
 {
		scanf("%d",&a);
		vec[a].push_back(i);
 }
 int maxcnt=0;
 int ansl=1,ansr=n;
 for(int i=1;i<=1000000;i++)
 {
 if(maxcnt<vec[i].size())
 {
			ansl=*vec[i].begin();
			ansr=*vec[i].rbegin();
			maxcnt=vec[i].size();
 }
 else if(maxcnt==vec[i].size())
 {
 int templ=*vec[i].begin();
 int tempr=*vec[i].rbegin();
 if(tempr-templ+1<ansr-ansl+1)
 {
				ansl=templ;
				ansr=tempr;
 }
 }
 }
	printf("%d %d\n",ansl,ansr);
 return 0;
}
