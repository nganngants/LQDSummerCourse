#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define file "flower"

using namespace std;
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;

const ll oo = 2e18;
const int N = 1003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

ll Rand(ll l, ll h)
{
    //assert(l <= h);
    return l + mt() % (h - l + 1);
}

int n, m;
ll f[N][N], pas[N][N];

void buildPascal()
{
    for (int i=1;i<=n;++i)
        pas[0][i] = 1,
        pas[i][i] = 1;

    for (int i=2;i<=n;++i)
        for (int k=1;k<i;++k)
            pas[k][i] = pas[k - 1][i - 1] + pas[k][i - 1],
            pas[k][i] %= mod;
}

ll C(int k, int n)
{
    return pas[k][n];
}

ll solve(int pos, int pre)
{
    if (pos == m + 1) return 1;
    if (f[pos][pre] != -1) return f[pos][pre];

    ll &res = f[pos][pre];
    res = 0;
    ///trồng 1 loại
    res += (solve(pos + 1, pre) * n) % mod;
    res %= mod;

    ///trồng 2 loại
    res += (solve(pos + 1, pre) * C(2,n)) % mod;
    res %= mod;

    ///trồng 3 loại
    if (pre < C(3, n))
    {
        res += (solve(pos + 1, pre + 1) * (C(3, n) - pre)) % mod;
        res %= mod;
    }
    return res;
}


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n >> m;
    buildPascal();
    memset(f, -1, sizeof f);
    cout << solve(1, 0);
    return 0;
}
/*
1:1 = 16
1:2 = 24
1:3 = 16
2:1 = 24
2:2 = 36
2:3 = 24
3:1 = 16
3:2 = 24
3:3 = 12
*/
