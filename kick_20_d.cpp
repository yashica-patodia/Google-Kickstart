#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
template<class T> ostream& operator<<(ostream &os, vector<T> V) {os << "[ "; for(auto v : V) os << v << " "; return os << "]";}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {return os << "(" << P.first << "," << P.second << ")";}
template <typename T,typename U>pair<T,U> operator+(const pair<T,U> & l,const std::pair<T,U> & r) { return {l.first+r.first,l.second+r.second};}
typedef long long int ll;

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
const ll mod =998244353;
const ll MAX_NODES =200001;
const ll MAX_LOG =50;
const ll maxn = 3000000+10;
#define endl '\n'
#define int ll
ll power(ll x, ll n) {
	ll res = 1;
	for (; n > 0; n >>= 1) {
	if (n & 1) res = (res * x) % mod;
	x = (x * x) % mod;
	}
	return res;
}

struct FT {
	vector<ll> s;
	FT(int n) : s(n,0) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < (s).size(); pos |= pos + 1) s[pos] = (s[pos]+dif);
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res = (res+s[pos-1]);
		return res;
	}
};
int32_t main()
{   


    IOS 
    int testcases = 1;
    cin>>testcases;
    for(int test = 1;test<=testcases;test++)
    {
      cout<<"Case #"<<test<<": ";
      int n;
      cin>>n;
      int q;
      cin>>q;
      int a[n+1];
      for(int i = 1;i<=n;i++){
        cin>>a[i];
      }
      FT ft(n+2),ft1(n+2);
      for(int i = 1;i<=n;i++){
        if(i%2 == 1){
          ft.update(i,a[i]*i);
          ft1.update(i,a[i]);
        }
        else{
          ft.update(i,-a[i]*i);
          ft1.update(i,-a[i]);
        }
      }
      int ans =  0;
      while(q--){
        char ty;
        cin>>ty;
        if(ty == 'U'){
          int x,v;
          cin>>x>>v;
          if(x%2 == 1){
            ft.update(x,(v-a[x])*x);
            ft1.update(x,(v-a[x]));
          }
          else{
            ft.update(x,-1*(v-a[x])*x);
            ft1.update(x,-1*(v-a[x]));
          }
          a[x] = v;
        }
        else{
          int l,r;
          cin>>l>>r;
          if(l%2 == 1){
            ans+=ft.query(r+1) - ft.query(l);
            ans-=(ft1.query(r+1) - ft1.query(l))*(l-1);
          }
          else{
            ans-=ft.query(r+1) - ft.query(l);
            ans+=(ft1.query(r+1) - ft1.query(l))*(l-1);
          }
        }
       
      }
       cout<<ans<<endl;
    }
  
    
    
    
   
     
       
    

 
}



