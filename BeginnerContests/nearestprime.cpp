#include<bits/stdc++.h>
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
#define randomize mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count())
randomize;

const ll oo = 2e18;
const int N = 203;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

bool check(int n)
{
    if (n < 2) return false;
    for (int i=2;i*i<=n;++i)
        if (n % i == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    int l = n, r = n;
    while (l >= 2 && !check(l)) l--;
    while (!check(r)) r++;
    cout << (n - l > r - n ? r : l);
}
