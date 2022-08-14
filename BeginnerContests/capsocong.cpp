#include<bits/stdc++.h>
#define maxn 1000003
#define ll long long
#define mod (ll)(1e9+7)
using namespace std;

ll a[maxn],n;

int main()
{
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i=2;i<n;++i)
        if (a[i + 1] - a[i] != a[2] - a[1])
    {
        cout << "NO";
        return 0;
    }
    cout << "YES";
    return 0;
}
