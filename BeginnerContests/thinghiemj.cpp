#include<bits/stdc++.h>
#define maxn 21
#define ll long long
#define mod (ll)(1e9+7)
using namespace std;

int a[maxn],m,n;
bool b[maxn], flag[maxn][maxn];
int res = 0;

void upd ()
{
    int sum = 0;
    for (int i=1;i<=n;++i)
        if (b[i])
        {
            for (int j=i + 1;j<=n;++j)
                if (b[j] && flag[i][j]) return;
            sum += a[i];
        }
    res = max(res, sum);
}

void Try(int pos)
{
    if (pos == n + 1)
    {
        upd();
        return;
    }
    for (int j=0;j<=1;++j)
    {
        b[pos] = j;
        Try(pos + 1);
    }
}
int main()
{
//    freopen("test.inp","r",stdin);
//    freopen("test.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for (int i=1;i<=m;++i)
    {
        int u, v;
        cin >> u >> v;
        flag[u][v] = flag[v][u] = true;
    }
    Try(1);
    cout << res;
    return 0;
}
/*
5 3
3 2 4 5 3
1 3
3 4
1 5
*/
