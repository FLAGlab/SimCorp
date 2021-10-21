#include<iostream>
using namespace std;
int n,c[100005],mi[100005],ma[100005];
int main()
{
    cin>>n;
 int a[n];
 for(int i=1;i<100005;i++)
 {
        ma[i]=-1;
        mi[i]=100005;
 }
 for(int i=0;i<n;i++)
 {
        cin>>a[i];
        c[a[i]]++;
        mi[a[i]]=min(mi[a[i]],i);
        ma[a[i]]=max(ma[a[i]],i);
 }
 int m=0,f=-1;
 for(int i=1;i<=100004;i++)
 {
 if(c[i]>=m)
 {
            m=c[i];
            f=i;
 }
 }
    cout<<mi[f]+1<<' '<<ma[f]+1<<endl;
 
 return 0;
}
