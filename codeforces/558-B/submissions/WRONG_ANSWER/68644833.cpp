#include<bits/stdc++.h>
using namespace std;
long long  q[1000005],arr[1000005],arr2[1000005],f;
int main()
{
 long long x,a,ma=0,max=0,pos1,pos2,num;
  cin>>x;
 for (int i=1 ; i<=x ; i++){
  cin>>q[i];
  f=q[i];
  arr[f]++;
 if(arr2[f]==0){arr2[f]=i;}
 
 if(f>ma){ma=f;}
 }
 
 for (int i=1 ; i<=ma ; i++){
 if (arr[i]>=max){max=arr[i];num=i;pos1=i;}}
 for(int i=x;i>=1;i--)
 {
 if(q[i]==num){pos2=i;break;}
 }
 {cout<<arr2[pos1]<<" "<<pos2; return 0;}
}
