#include<stdio.h>
long max(long a,long b){
	if(a>b)
		return a;
	return b;
} 
int n,h,s;
struct ytg{
	long h,s,q; 
}g[1005];
long long dp[305][305];
int main(){
	scanf("%d%d%d",&n,&h,&s);
	int t;
	for(int i=0;i<n;i++){
		scanf("%ld%ld%ld",&g[i].h,&g[i].s,&g[i].q);
	}
	for(int i=0;i<n;i++)
		for(int j=h;j>g[i].h;j--)
			for(long k=s;k>=0;k--){
				t=k-g[i].s;
				if(t>=0)
					dp[j][k]=max(dp[j][k],dp[j-g[i].h][t]+g[i].q);
				else
				if(j-g[i].h+t>0)
					dp[j][k]=max(dp[j][k],dp[j-g[i].h+t][0]+g[i].q); 
			}
	printf("%ld",dp[h][s]);
	return 0;
}
