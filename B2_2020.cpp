#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int check(lli mm,lli d,lli vec[],lli n);
int main()
{
	int t;
	cin>>t;
	int temp=t;
	while(t--)
	{
		lli n,d,i;
		cin>>n>>d;
		//vector<lli>vec;
		lli vec[n+1];
		for(i=0;i<n;i++)
		{
			lli p;
			cin>>p;
			vec[i]=p;
		}
		lli lb=1,ub=d+1;
		lli ans=n+1;
		lli mm;
		while(lb<=ub)
		{
			mm=lb+(ub-lb)/2;
			if(check(mm,d,vec,n))
			{
				ans=mm;
				lb=mm+1;
				//cout<<ans<<" ";

			}
			else
				ub=mm-1;
		}
		// lli p=n;
		// while(p!=0)
		// {
		// 	//lli cnt=0;
		// 	while(d%vec[p-1]==0 && p>0 )
		// 	{
		// 		p--;
		// 		//cnt++;
		// 	}
		// 	//if(cnt==0)
		// 	d--;
		// }
		// lli ans=d+1;


		
		cout<<"Case #"<<temp-t<<": "<<ans<<endl;
	}

	}

int check(lli mm,lli d,lli vec[],lli n)
{
	lli curr=mm;
	lli i;
	for(i=0;i<n;i++)
	{
		curr=((curr+vec[i]-1)/vec[i])*vec[i];

	}
	return curr<=d;
}