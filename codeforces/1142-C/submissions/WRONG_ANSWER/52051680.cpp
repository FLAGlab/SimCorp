 #include<bits/stdc++.h>
using namespace std;
int vertex,edge,u,v,w;
 
int main()
{
 int n,l=0,r=0;
    cin>>n;
 int x;
 for(int i=1; i<=n; i++){
        cin>>x;
 if(x==0)l=i;
 else r=i;
 }
    cout<<min(l,r);
 return 0;
}
