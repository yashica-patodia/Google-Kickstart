#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
lli a[100010]={0};
int main()
{
	lli t,n,k,i;
	cin>>t;
	lli temp=t;
	while(t--)
	{
		cin>>n>>k;
		for(i=0;i<n;i++)
			cin>>a[i];
		lli lb=1,ub=a[n-1]-a[0];
		while(lb<ub)
		{
			lli mb=floor((lb+ub)/2);
			//cout<<mb<<endl;
			lli k2=0;
			for(i=1;i<n;i++)
			{
				lli diff=a[i]-a[i-1];
				k2+=(diff-1)/mb;
				//cout<<k2<<endl;
			}
			if(k2>k)
				lb=mb+1;
			else
				ub=mb;
		}
		cout<<"Case #"<<temp-t<<":"<<lb<<endl;
		
	}

}