#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
int main()
{
	// #ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	int t;
	cin>>t;
	int temp=t;

	while(t--)
	{
		int n;
		cin>>n;
		vector<int>vec;
		int i;
		for(i=0;i<n;i++)
		{
			int p;
			cin>>p;
			vec.push_back(p);
		}
		int cnt=0;
		for(i=1;i<n-1;i++)
		{
			if(vec[i]>vec[i-1] && vec[i]>vec[i+1])
				cnt++;
		}
		cout<<"Case #"<<temp-t<<": "<<cnt<<endl;

	}
}