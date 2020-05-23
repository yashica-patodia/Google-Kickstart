//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"
#define mod 998244353
//#define int long long
#define inf (1LL << 55)
const int maxnodes=1005;
#define ll long long
#define N 501
#define EPS 0.01
int n,r,c;
map<pair<int,int>,int> dpwest,dpeast,dpnorth,dpsouth;
map<pair<int,int>,int> vis;
pair<int,int> move_west(pair<int,int> p)
{
    if(vis[p] == 0)
    {
        vis[p] = 1;
        return p;
    }
    if(dpwest[p] == 0)
    {
        pair<int,int> ans = move_west({p.first,p.second - 1});
        dpwest[p] = ans.second;
    }
    else
    {
        pair<int,int> ans = move_west({p.first,dpwest[p]});
        dpwest[p] = ans.second;

    }
    return {p.first,dpwest[p]};
}
pair<int,int> move_east(pair<int,int> p)
{
    if(vis[p] == 0)
    {
        vis[p] = 1;
        return p;
    }
    if(dpeast[p] == 0)
    {
        pair<int,int> ans = move_east({p.first,p.second + 1});
        dpeast[p] = ans.second;
    }
    else
    {
        pair<int,int> ans = move_east({p.first,dpeast[p]});
        dpeast[p] = ans.second;

    }
    return {p.first,dpeast[p]};
}
pair<int,int> move_south(pair<int,int> p)
{
    //cerr << p.first << "  " << p.second << " " << vis[p]  << endl;;
    if(vis[p] == 0)
    {
        vis[p] = 1;
        return p;
    }
    if(dpsouth[p] == 0)
    {
        //cerr << dpsouth[p];
        pair<int,int> ans = move_south({p.first + 1,p.second});
        dpsouth[p] = ans.first;
    }
    else
    {
        pair<int,int> ans = move_south({dpsouth[p],p.second});
        dpsouth[p] = ans.first;

    }
    return {dpsouth[p],p.second};
}
pair<int,int> move_north(pair<int,int> p)
{
    if(vis[p] == 0)
    {
        vis[p] = 1;
        return p;
    }
    if(dpnorth[p] == 0)
    {
        pair<int,int> ans = move_north({p.first - 1,p.second});
        dpnorth[p] = ans.first;
    }
    else
    {
        pair<int,int> ans = move_north({dpnorth[p],p.second});
        dpnorth[p] = ans.first;

    }
    return {dpnorth[p],p.second};
}
int32_t main()
{
    IOS;

    int t;
    cin >> t;
    for(int tc = 1;tc <= t;tc++)
    {
        cout << "Case #" << tc << ": " ;
        cin >> n >> r >> c;
        int sx,sy;
        cin >> sx >> sy;
        dpwest.clear();
        dpsouth.clear();
        dpnorth.clear();
        dpeast.clear();
        vis.clear();
        vis[{sx,sy}] = 1;
        for(int i = 0;i < n;i++)
        {
            char c;
            cin >> c;
            pair<int,int> p;
            if(c == 'N')
            {
                p = move_north({sx-1,sy});
            }
             if(c == 'S')
            {
                p = move_south({sx+1,sy});
            }
             if(c == 'E')
            {
                p = move_east({sx,sy+1});
            }
             if(c == 'W')
            {
                p = move_west({sx,sy-1});
            }
            sx = p.first;
            sy = p.second;
            //cerr << sx << " " << sy << endl;
        }
        cout << sx << " " << sy;

        cout << endl;
    }
    return  0;
}