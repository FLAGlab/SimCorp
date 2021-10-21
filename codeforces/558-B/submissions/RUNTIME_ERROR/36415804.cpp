#include<bits/stdc++.h>
using namespace std;
class longInt
{
public:
 int *start,*endd,*cnt;
    longInt (int n)
 {
        start=new int [n+1];
        endd=new int [n+1];
        cnt=new int [n+1];
 for(int i=0;i<=n;i++)
            cnt[i]=0;
 }
 
};
 
 
int main()
{
 long long int n,a,maxx=0,diff=-1,num;
    cin>>n;
    longInt p(n);
 
 for(int i=1;i<=n;i++)
 {
        cin>>a;
        p.cnt[a]++;
 if(p.cnt[a]==1) p.start[a]=i;
        p.endd[a]=i;
 if((maxx<p.cnt[a])||(maxx==p.cnt[a]&&diff>(p.endd[a]-p.start[a])))
 {
            maxx=p.cnt[a];
            diff=(p.endd[a]-p.start[a]);
            num=a;
 }
 }
    cout<<p.start[num]<<" "<<p.endd[num]<<endl;
 
 return 0;
}
 
 
