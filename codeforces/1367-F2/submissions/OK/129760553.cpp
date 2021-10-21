#include<bits/stdc++.h>
using namespace std;
set< int >Set;
stack< int >Stack;
pair< int,int >A[200001];
size_t N;
int main(void)
{
 register size_t Case;scanf("%ld",&Case);while(Case--)
 {
 register int i,j;scanf("%ld",&N),Set.clear();
 for(;Stack.size();Stack.pop());
 register size_t Ret(0);
 for(i=0;i<N;i++)scanf("%d",&A[i].first),A[i].second=-i;
        sort(A,A+N);
 for(i=j=0;i<N;i++)
 {
 if(i&&A[i].first-A[i-1].first)for(;Stack.size();Stack.pop())Set.insert(Stack.top());
 Stack.push(A[i].second);
 for(;Set.size()&&*Set.begin()<A[i].second;j++)Set.erase(A[j].second);
 Ret=max(Ret,Set.size()+Stack.size());
 }
        printf("%ld\n",N-Ret);
 }
 return 0;
}
