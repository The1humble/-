#include<bits/stdc++.h> 
using namespace std;
int n,h,s;
struct Node{
	int h,s,w;
}g[1005];
long long dp[305][305];  //注意开long long 确保数据长度 
int main()
{
	cin>>n>>h>>s;
	for(int i=0;i<n;i++)
	{
		cin>>g[i].h>>g[i].s>>g[i].w;
	}
	for(int i=0;i<n;i++)
	for(int j=h;j>g[i].h;j--) //体力不够就死了 
	for(int k=s;k>=0;k--)//耐力不够 体力来凑 
	{
		int temp=k-g[i].s;
		if(temp>=0)
		dp[j][k]=max(dp[j][k],dp[j-g[i].h][temp]+g[i].w);//每次比较得到的金币数留最大的 
		else
		if(j-g[i].h+temp>0)//先保证死不了 
		dp[j][k]=max(dp[j][k],dp[j-g[i].h+temp][0]+g[i].w);
	}
	for(int i=0;i<=h;i++){
	
	for(int j=0;j<=s;j++)
		printf("%d   ",dp[i][j]);
	printf("\n");
	}
	cout<<dp[h][s];
}
