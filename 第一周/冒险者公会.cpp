#include<bits/stdc++.h> 
using namespace std;
int n,h,s;
struct Node{
	int h,s,w;
}g[1005];
long long dp[305][305];  //ע�⿪long long ȷ�����ݳ��� 
int main()
{
	cin>>n>>h>>s;
	for(int i=0;i<n;i++)
	{
		cin>>g[i].h>>g[i].s>>g[i].w;
	}
	for(int i=0;i<n;i++)
	for(int j=h;j>g[i].h;j--) //�������������� 
	for(int k=s;k>=0;k--)//�������� �������� 
	{
		int temp=k-g[i].s;
		if(temp>=0)
		dp[j][k]=max(dp[j][k],dp[j-g[i].h][temp]+g[i].w);//ÿ�αȽϵõ��Ľ���������� 
		else
		if(j-g[i].h+temp>0)//�ȱ�֤������ 
		dp[j][k]=max(dp[j][k],dp[j-g[i].h+temp][0]+g[i].w);
	}
	for(int i=0;i<=h;i++){
	
	for(int j=0;j<=s;j++)
		printf("%d   ",dp[i][j]);
	printf("\n");
	}
	cout<<dp[h][s];
}
