#include<bits/stdc++.h>
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair

#define pb push_back
#define pf push_front
#define ins insert
#define all(v) (v).begin, (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;

typedef vector<plli> vplli;
long long MOD=1000000009;
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	int t;
	cin>>t;
	int temp=t;
	while(t--)
	{
		int n,r,c,sr,sc;
		cin>>n>>r>>c>>sr>>sc;
		string str;
		cin>>str;
		bool  vis[r+1][c+1];
		//int arr[r+1][c+1];
		mset(vis,0);
		int row=sr-1;
		int col=sc-1;
		vis[row][col]=1;
		fr2(i,n)
		{
			if(str[i]=='N')
			 {
			// 	if(vis[row-1][col]==0)
			// 	{
			// 		row=row-1;
			// 		vis[row][col]=1;
			// 	}
				//else
				//{
					while(vis[row-1][col]!=0)
					{
						row--;
					}
					row--;
					vis[row][col]=1;

				//}

			}
			if(str[i]=='S')
			{
				// if(vis[row+1][col]==0)
				// {
				// 	row=row+1;
				// 	vis[row][col]=1;
				// }
				// else
				// {
					while(vis[row+1][col]!=0)
					{
						row++;
					}
					row++;
					vis[row][col]=1;
				//}

			}
			if(str[i]=='E')
			{
				// if(vis[row][col+1]==0)
				// {
				// 		col=col+1;
				// 		vis[row][col]=1;
				// }
				// else
				// {
					while(vis[row][col+1]!=0)
					{
						col++;
					}
					col++;
					vis[row][col]=1;
				//}

			}
			if(str[i]=='W')
			{
				// if(vis[row][col-1]==0)
				// {
				// 		col=col-1;
				// 		vis[row][col]=1;
				// }
				// else
				// {
					while(vis[row][col-1]!=0)
					{
						col--;
					}
					col--;
					vis[row][col]=1;
				//}

			}

		}
		cout<<"Case #"<<temp-t<<": "<<row+1<<" "<<col+1<<endl;
	}
	
}

