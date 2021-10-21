#include <iostream>
 
using namespace std;
 
struct el{
 int a;
 int b;
 int oc;
};
int main()
{
  ios::sync_with_stdio(0);
 int n;
    cin>>n;
    el t[1000000];
 int mx=0;
 for(int i=0;i<=1000000;i++)
 {
      t[i].oc=0, t[i].a=0,t[i].b=0;
 }
 for(int i=1;i<=n;i++)
 {
 int x;
      cin>>x;
      t[x].oc++;
      mx=max(mx,t[x].oc);
 if (!t[x].a)
        t[x].a=i;
      t[x].b=i;
 }
 
 int mxa=0,mxb=n+1;
 for(int i=1;i<=1000000;i++)
 {
 if (t[i].oc==mx)
 {
 if (t[i].b-t[i].a<mxb-mxa)
          mxa=t[i].a,mxb=t[i].b;
 }
 }
     cout<<mxa<<" "<<mxb;
 
 return 0;
}
