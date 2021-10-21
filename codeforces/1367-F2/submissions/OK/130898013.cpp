#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int Read()
{
 int Output=0;
 char Input=getchar();
 while(Input<'0'||Input>'9')
 Input=getchar();
 while(Input>='0'&&Input<='9')
 {
 Output=Output*10+Input-'0';
 Input=getchar();
 }
 return Output;
}
int T;
int N;
int Copy[200001];
vector<int>Vec[200001];
int A[200001];
int Ans;
int DP[200001];
int main()
{
	T=Read();
 while(T--)
 {
 Ans=0;
		N=Read();
 for(int i=1;i<=N;++i)
 Copy[i]=A[i]=Read();
		sort(Copy+1,Copy+N+1);
 int Lon=unique(Copy+1,Copy+N+1)-Copy-1;
 for(int i=1;i<=N;++i)
 {
			A[i]=lower_bound(Copy+1,Copy+Lon+1,A[i])-Copy;
 Vec[A[i]].push_back(i);
 }
 Ans=Vec[1].size();
 for(int i=0;i<Vec[1].size();++i)
		DP[Vec[1][i]]=i+1;
 for(int i=2;i<=Lon;++i)
 {
 int j;
 int Lastsize=Vec[i-1].size();
 int Size=Vec[i].size();
 int Past=Vec[i-1][Lastsize-1];
 int Last;
 for(j=0;j<Size;++j)
 {
 int Pos=Vec[i][j];
 if(Pos>Past)break;
 Last=lower_bound(Vec[i-1].begin(),Vec[i-1].end(),Pos)-Vec[i-1].begin();
				DP[Pos]=max((j?DP[Vec[i][j-1]]+1:0),Last+1);
 Ans=max(DP[Pos],Ans);
 }
 Last=DP[Vec[i-1][0]];
 if(j<Size)
 {
				DP[Vec[i][j]]=max(Last+Lastsize,(j?DP[Vec[i][j-1]]+1:0));
 for(++j;j<Size;++j)
				DP[Vec[i][j]]=DP[Vec[i][j-1]]+1;
 Ans=max(Ans,DP[Vec[i][Size-1]]);
 }
 }
 for(int i=1;i<=N;++i)
 {
			DP[i]=0;
 Vec[i].clear();
 }
		printf("%d\n",N-Ans);
 }
 return 0;
}
