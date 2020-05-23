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
//typedef  vector<vector<lli> >ncr(1001,vector<lli>(1001,0))
typedef vector<plli> vplli;
long long MOD=1000000009;
const int N=1001;
int n;
map<int,vector<int> >adj;
vector<int>cyc;
vector<int> par(N);
vector<bool>  vis(N,false);
vector<lli>dis(N);
void solve()
{
	//mset(vis,)
	cin>>n;
	adj.clear();
	cyc.clear();
	dis.clear();

	dis.resize(n+1);
	vis.resize(n+1);
	par.resize(n+1);

	//mset(vis,false);
	fr2(i,n)
	{
		int x,y;
		cin>>x>>y;
		adj[x].eb(y);
		adj[y].eb(x);
		par[i+1]=-1;
		vis[i+1]=false;
		dis[i+1]=MOD;

	}
	queue<int>q;
	q.push(1);
	vis[1]=true;
	int temp,curr;
	while(!q.empty())
	{
		int st=q.front();
		cout<<st<<endl;
		q.pop();
		for(auto j:adj[st])
		{
			cout<<j<<endl;
			if(!vis[j])
			{
				vis[j]=true;
				q.push(j);
				par[j]=st;
			}
			else if(par[j]!=st && j!=1)
			{
				cout<<st<<" "<<par[j]<<endl;
				curr=st;
				temp=j;
				break;
			}
		}
	}
	//temp=par[st];
	cyc.eb(curr);
	while(curr!=temp)
	{
		curr=par[curr];
		cyc.eb(curr);
	}
//	memset(vis,false,sizeof(vis));
	for(int i=1;i<=n;i++)
		vis[i]=false;
	for(auto j:cyc)
	{
		cout<<j<<" ";
		vis[j]=true;
		dis[j]=0;
	}

//	queue<int>q2;




	

}
int main()
{
		#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
	IOS
	clock_t start,end;
	start=clock();
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
