#include<bits/stdc++.h>
using namespace std;
signed main()
{
 int x;
    scanf("%d",&x);
 for(int i=0; i <=x;i++)
 {
        string str;
        getline(cin, str);
 if(i!=0)
 {
 int l = str.size();
 if(l%2==0)
        printf("YES\n");
 else
        printf("NO\n");
 }
 }
 return 0;
}
