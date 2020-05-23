#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ff first
#define ss second
#define eb emplace_back
#define MP make_pair
#define pb push_back
#define pf push_front
#define ins insert
#define endl '\n'
#define all(v) (v).begin(), (v).end()
#define mset(m,v) memset(m,v,sizeof(m))
#define tr(c,it) for(auto it=c.begin();it!=c.end();it++)
#define fr(i,n) for(lli i=0;i<(n);i++)
#define inc(i,a,b) for(lli i=a;i<=b;i++)
#define dec(i,a,b) for(lli i=a;i>=b;i--)
#define fr2(i,n) for(int i=0;i<(n);i++)
#define inc2(i,a,b) for(int i=a;i<=b;i++)
#define dec2(i,a,b) for(int i=a;i>=b;i--)
#define ymin(a,b)  (a=min((a),(b)))
#define ymax(a,b)  (a=max((a),(b)))
#define sz(x) (lli)(x).size()
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr<< *it << " = " << a << endl;
	err(++it, args...);
}

typedef long long int lli;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef vector<int> vi;
typedef vector<vector<int>> grp;
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
lli hist(vector<lli>vec )
{
	stack<int>st;
	// fr2(i,n)
	// cin>>vec[i];
	lli sum=0,maxs=0;
	int i=0;
	int n=vec.size();
	while(i<n)
	{
		if(st.empty() || vec[i]>=vec[st.top()])
			st.push(i++);
		else
		{
			int tp=st.top();
			st.pop();
			sum=vec[tp]*(st.empty()? i:i-st.top()-1);//finding area in between (i-1) and t.top()+1
			maxs=max(sum,maxs);
		}
	}
	while(!st.empty())
	{
		int tp=st.top();
			st.pop();
			sum=vec[tp]*(st.empty()? i:i-st.top()-1);
			maxs=max(sum,maxs);

	}
	return maxs;
}
void solve()
{
	int r,c,k;
	cin>>r>>c>>k;
	int arr[r][c];
	fr2(i,r)
	{
		fr2(j,c)
		cin>>arr[i][j];
	}
	int dp[r][c]={0};
	for(int i=0;i<r;i++)
	{
		for(int col1=0;col1<c;col1++)
		{
			dp[i][col1]=1;
			int m1=arr[i][col1];
			int m2=arr[i][col1];
			for(int  col2=col1-1;col2>=0;col2--)
			{
				m1=max(m1,arr[i][col2]);
				m2=min(m2,arr[i][col2]);
			
			if(m1-m2<=k)
				dp[i][col1]++;
			else
				break;
		}
			
		}
	}
	// fr2(i,r)
	// {
	// 	fr2(j,c)
	// 	cout<<dp[i][j]<<" ";

	// 	cout<<endl;
	// }
	vector<lli>f(r);
	//lli f[r]={0};
	lli ans2=-MOD;
	for(int i=0;i<c;i++)
	{
		for(int j=0;j<r;j++)
		{
			f[j]=dp[j][i];

		}
		 lli ans=hist(f);
		  ans2=max(ans,ans2);
	
	}
	cout<<ans2<<endl;
}
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	// freopen("output.txt","w",stdout);
	// #endif
	IOS
	// clock_t start,end;
	// start=clock();
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve();

	}
	//solve();

	
	
	// end=clock();
	
	// double time_taken=double(end-start)/double(CLOCKS_PER_SEC);
	// cout<<fixed<<setprecision(10)<<time_taken<<" sec"<<endl;
	
}
