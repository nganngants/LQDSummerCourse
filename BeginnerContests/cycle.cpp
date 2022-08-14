#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define file "cycle"

using namespace std;
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;

const ll oo = 2e18;
const int N = 300003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

ll Rand(ll l, ll h)
{
    //assert(l <= h);
    return l + mt() % (h - l + 1);
}

int n, m;
bool vis[N];
vector<int> a[N];

bool dfs(int u, int p)
{
    vis[u] = true;
    for (auto v : a[u])
        if (v != p)
        if (vis[v]) return true;
        else if (dfs(v, u)) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n >> m;
    fu(i,1,m)
    {
        int u, v;
        cin >> u >> v;
        a[u].pb(v);
        a[v].pb(u);
    }
    fu(i,1,n)
        if(!vis[i])
        {
            if (dfs(i, 0))
            {
                cout << "YES";
                return 0;
            }
        }
    cout << "NO";
    return 0;
}
/*
5 5
1 4
1 5
2 3
2 4
3 1
*/
