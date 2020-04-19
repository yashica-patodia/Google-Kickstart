#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	int t;
	cin>>t;
	int temp=t;
	while(t--)
	{
		lli n,p,k;
		cin>>n>>k>>p;
		lli sum[n+1][k+1];
		memset(sum,0,sizeof(sum));
		lli i,j,x;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=k;j++)
			{
				lli arr;
				cin>>arr;
				sum[i][j]=arr+sum[i][j-1];
			}
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=k;j++)
				cout<<sum[i][j]<<" ";
			cout<<endl;
		}
		lli dp[n+1][p+1];
		memset(dp,0,sizeof(dp));
		for(i=1;i<=n;i++)
		{
			for(j=0;j<=p;j++)
			{
				dp[i][j]=0;
				for(x=0;x<=min(j,k);x++)
					dp[i][j]=max(dp[i][j],sum[i][x]+dp[i-1][j-x]);

			}
		}
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=p;j++)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}
		cout<<"Case #"<<temp-t<<": "<<dp[n][p]<<endl;
	}
}