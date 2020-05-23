#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	int temp=t;
	int n,r,c,sr,sc;
	while(t--)
	{
	cin>>n>>r>>c>>sr>>sc;
	string s;
	cin>>s;
	sr=sr-1;
	sc=sc-1;
	bool vis[r+1][c+1];
	memset(vis,0,sizeof(vis));
	vis[sr][sc]=1;
	int i;
	for(i=0;i<s.length();i++)
	{
		if(s[i]=='N')
		{
			while(vis[sr-1][sc]!=0)
				sr--;
			sr--;
			vis[sr][sc]=1;



		}
		if(s[i]=='S')
		{
			while(vis[sr+1][sc]!=0)
				sr++;
			sr++;
			vis[sr][sc]=1;

		}
		if(s[i]=='E')
		{
			while(vis[sr][sc+1]!=0)
				sc++;
			sc++;
			vis[sr][sc]=1;

		}
		if(s[i]=='W')
		{
			while(vis[sr][sc-1]!=0)
				sc--;
			sc--;
			vis[sr][sc]=1;

		}
	}
	cout<<"Case #"<<temp-t<<": "<<sr+1<<" "<<sc+1<<endl;
}
}