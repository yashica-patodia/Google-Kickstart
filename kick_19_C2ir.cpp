#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

typedef vector< int > vi;
typedef vector< vi > vvi;
typedef pair< int,int > ii;
typedef map<int,int> mii;
typedef map< long long int, long long int> mll;

#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for( auto i = (c).begin(); i != (c).end(); i++)
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())

#define edl '\n'
#define ll long long int
#define mp make_pair

#define in(n) int n; cin >> n;
#define inl(n) ll n; cin >> n;
#define forn(i,n) for ( int i=0 ; i<n ; i++ )
#define forni(i,j,n) for ( int i=j ; i<n ; i++ )
#define forr (i,n) for ( int i=n; i>=0; i-- )
#define numb(arr,i) (int)(arr[i]-'0')

#define filecode ifstream in;ofstream out;in.open("input.txt");out.open("output.txt");
#define Arr(n) int arr[n]={}; forn(i,n) cin>>arr[i];
#define setPrecision(n) cout << std::setprecision(n) << std::fixed;
#define outk(z,n) cout << "Case #" << z << ": " << n << endl;
#define MOD 1000000009
#define PI 3.14159265

int main()
{
    ios::sync_with_stdio(false) ;
	cin.tie(0); cout.tie(0);
    in(ts);
    int r,c,k;
    char t;
    forn(z,ts){
        cin >> r >> c >> k;
        int arr[r][c],tp;
        forn(i,r){
            forn(j,c) cin >> arr[i][j];
        }
        int mp[r][c],minn,maxx;
        forn(i,r){
            forn(j,c-1){
                tp = c-j;
                minn = arr[i][j];
                maxx = arr[i][j];
                forni(l,j+1,c){
                    minn = min(minn,arr[i][l]);
                    maxx = max(maxx,arr[i][l]);
                    if ( maxx-minn>k ){
                        tp = l-j;
                        break;
                    }
                }
                mp[i][j] = tp;
            }
            mp[i][c-1] = 1;
        }
        int mx = r,lim;
        forn(i,c){
            forn(j,r){
                tp = mp[j][i];
                lim = mp[j][i];
                forni(l,j+1,r){
                    if ( mp[l][i]>=lim ) tp += lim;
                    else if ( mp[l][i]<lim ){
                        tp += lim;
                        tp -= (l-j+1)*(lim-mp[l][i]);
                        lim = mp[l][i];
                    }
                    mx = max(mx,tp);
                }
                mx = max(mx,tp);
            }
        }
        outk(z+1,mx);

    }

}
