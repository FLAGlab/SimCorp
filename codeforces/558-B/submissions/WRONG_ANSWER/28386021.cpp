#include<bits/stdc++.h>
 
int arr[1234567],arr1[1234567];
 
signed main() 
{
 int i,n,j,st=-1,end=-1,l=0;
	scanf("%d",&n);
 for(i=0;i<n;i++)
 {
		scanf("%d",&j);
 if(!arr[j])
 {
			arr[j] = 1;
			arr1[j] = i;
 } 
 else
 {
			arr[j]++;
 } 
 if(arr[j] > l)
 {
			l = arr[j];
			st = arr1[j];
			end = i;
 } 
 } 
	printf("%d %d\n",st+1,end+1);
 return 0;
}
