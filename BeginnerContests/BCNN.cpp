#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define fu(i,a,b) for(int i=a;i<=b;++i)
#define fd(i,a,b) for(int i=a;i>=b;--i)
#define file "test"

using namespace std;

const ll oo = 2e18;
const int N = 100003;
const ll mod = 1e9 + 7;
const int M = 1000003;
typedef pair<int,int> ii;

int prime[M + 1];
int n, cnt[M + 1];
ll res = 1;

void sieve()
{
    memset(prime, -1, sizeof prime);
    for (int i=2;i*i<=M;++i)
        if (prime[i] == -1)
        for (int j=i*i;j<=M;j+=i)
            prime[j] = i;
    fu(i,2,M) if (prime[i] == -1) prime[i] = i;
}

ll Pow (int a, int p)
{
    ll ret = 1;
    fu(i,1,p) ret *= (ll)a, ret %= mod;
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);
    sieve();
    cin >> n;
    fu(i,1,n)
    {
        int x;
        cin >> x;
        while (x > 1)
        {
            int curPrime = prime[x];
            int curNum = 0;
            while (x % curPrime == 0)
            {
                curNum++;
                x /= curPrime;
            }
            cnt[curPrime] = max(cnt[curPrime], curNum);
        }
    }
    fu(i,2,M)
        if (prime[i] == i && cnt[i] > 0)
            res *= Pow(i, cnt[i]),
            res %= mod;
    cout << res;
    return 0;
}
