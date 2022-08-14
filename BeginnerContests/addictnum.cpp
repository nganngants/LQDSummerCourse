#include <bits/stdc++.h>
#define ll long long
#define mid ((l+r)/2)
#define inf (ll)1e17
#define maxn 100001
#define mod (ll)(1e9+7)
#define pi pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define name "addictnum"
using namespace std;
string s;
ll n,a[maxn],x[maxn],sum;
bool is_true=0;
void input()
{
     freopen(name".inp","r",stdin);
     freopen(name".out","w",stdout);
}
void Boost()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
ll get(int pos,int num)
{
    ll tmp=0;
    while(num--)
    {
        tmp=tmp*10+int(s[pos]-'0');
        pos++;
    }
    return tmp;
}
bool check(int m)
{
    int pos=1;
    for(int i=1;i<=m;i++)
    {
        a[i]=get(pos,x[i]);
        pos+=x[i];
        if(a[i]!=a[i-1]+a[i-2]&&i>=3)return false;
    }
    return true;
}
void Try(int i, int sum)
{
    for(int k=1;k<=n;k++)
        if(i<=2||k>=x[i-1])
    {
        x[i]=k;
        if(sum+k>n)
         {
            return;
         }
        if(sum+k==n&&i>=3)
        {
            if (check(i)==true)
            {
                is_true=1;
                return;
            }
        }
        else Try(i+1,sum+k);
        x[i]=0;
    }
    return;
}
int main()
{
//     input();
	 cin>>s;
	 n=s.size();
	 s=" "+s;
	 Try(1,0);
	 if(is_true)cout<<"true";
	 else cout<<"false";
     return 0;
}
/*
1124
Read the code again
Check the limit
Check IO
*/
