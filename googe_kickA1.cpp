#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int check(lli mm,vector<lli>vec,lli dp[],lli b);

int main()
{
	lli t;
	cin>>t;
	lli temp=t;
	while(t--)
	{
		lli n,b;
		cin>>n>>b;
		vector<lli>vec;
		lli i;
		for(i=0;i<n;i++)
		{
			lli p;
			cin>>p;
			vec.push_back(p);
		}
		lli dp[n+1];
		dp[0]=0;

		sort(vec.begin(),vec.end());
		for(i=1;i<=n;i++)
			dp[i]=dp[i-1]+vec[i-1];

		lli lb=0,ub=n+1,ans=0;
		while(lb<=ub)
		{
			lli mm=lb+(ub-lb)/2;
			if(check(mm,vec,dp,b))
			{	ans=mm;
				lb=mm+1;
			}
			else
				ub=mm-1;
		}
		cout<<"Case #"<<temp-t<<": "<<ans<<endl;
	}
}
int check(lli mm,vector<lli>vec,lli dp[],lli b)
{
	if(dp[mm]<=b)
		return 1;
	else
		return 0;

}