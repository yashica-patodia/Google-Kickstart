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
long long MOD=1000000000;
lli pwr(lli x,lli n)
{
	lli res=1;
	for(; n!=0;n>>=1)
	{
		if(n&1)
			res=(res*x)%MOD;
		x=(x*x)%MOD;
	}
	return res;
}
void solve();
plli delta(lli x,lli y);


string s;
int main()
{
	// 	#ifndef ONLINE_JUDGE
	// freopen("input2.txt","r",stdin);
	// freopen("output3.txt","w",stdout);
	// fclose("output2.txt");
	// #endif
	IOS
	lli t;
	cin>>t;
	inc(i,1,t)
	{
		cout<<"Case #"<<i<<": ";
		solve();

	}
	
}
void solve()
{
	cin>>s;
	plli  coor=delta(0,sz(s)-1);
	cout<<coor.ff+1<<" "<<coor.ss+1<<endl;

}
plli delta(lli x,lli y)
{
	plli curr=MP(0,0);
	inc(i,x,y)
	{
		if(s[i]>='0' && s[i]<='9')
		{
			lli j=i+2;
			lli lvl=1;
			while(j<=y)
			{
				if(s[j]=='(')
					lvl++;
				else if(s[j]==')')
					lvl--;
				if(lvl==0)
					break;
				j++;
			}
		
		plli coor=delta(i+2,j-1);
		lli val=s[i]-'0';
		coor.ff=coor.ff*val%MOD;
		coor.ss=coor.ss*val%MOD;
		curr.ff+=coor.ff;
		curr.ss+=coor.ss;
		i=j;
		}
	else if(s[i]=='N')
		curr.ss--;
	else if (s[i]=='S')
		curr.ss++;
	else if(s[i]=='W')
		curr.ff--;
	else if(s[i]=='E')
		curr.ff++;
	}
	curr.ff+=MOD;
	curr.ss+=MOD;
	curr.ff%=MOD;
	curr.ss%=MOD;
	return curr;

}
