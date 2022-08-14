#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define file "maxsum"

using namespace std;
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;

const ll oo = 2e18;
const int N = 1000003;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

ll Rand(ll l, ll h)
{
    //assert(l <= h);
    return l + mt() % (h - l + 1);
}

int n;
ll pre = 0, cur = 0, res = -oo;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    cin >> n;
    fu(i,1,n)
    {
        ll x;
        cin >> x;
        cur += x;
        res = max(res, cur - pre);
        pre = min(pre, cur);
    }
    cout << res;
    return 0;
}
