#include<bits/stdc++.h>
int arr[1000000+10],n,ini[1000000+10],fin[1000000+10];
signed main(){
 int x,may=0;
    scanf("%d",&n);
 for(int i=0;i<n;i++){
        scanf("%d",&x);
        arr[x]++;
 if(arr[x]>arr[may])
            may=x;
 if(ini[x]==0)
            ini[x] = i+1;
        fin[x]=i+1;
 }
    printf("%d %d\n",ini[may],fin[may]);
}
