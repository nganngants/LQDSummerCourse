#include<bits/stdc++.h>
#define ll long long
#define mod (ll)(1e9+7)
using namespace std;
ll ans,n,m;
int main()
{
//    freopen("test.inp", "r", stdin);
//    freopen("test.out", "w", stdout);
    ans = 1;
    cin>>n>>m;
//    if (n <= 0 || m <= 0) cout << "?";
    if(n>m)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        ans = ans*(m-i+1);
        ans%=mod;
    }
    cout<<ans;
    return 0;
}
