#include <bits/stdc++.h>

#define ll long long
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define mid ((l+r)>>1)
#define sz(a) (int)a.size()
#define file ""

using namespace std;

const ll oo = 2e18;
const int N = 43;
const ll mod = 1e9 + 7;
typedef pair<int,int> ii;

string s;
bool ok = false;
ll n, a[N], memo[N]; ///memo[i] lưu độ dài của số thứ i

///hàm lấy chuyển chuỗi con của s bắt đầu từ pos, có độ dài len sang số nguyên
ll getval(int pos, int len)
{
    if (len > 19) return 0;
    ll ans = 0;
    while (len--)
    {
        ans = ans * 10 + (s[pos] - '0');
        pos++;
    }
    return ans;
}

///kiểm tra xem các số đã chia có thỏa mãn điều kiện hay không
bool check(int m)
{
    int start = 1;
    for(int i=1;i<=m;i++)
    {
        a[i] = getval(start,memo[i]);
        start += memo[i];
        if (i < 3) continue;
        if (a[i] != a[i-1] + a[i-2]) return false;
    }
    return true;
}

///hàm quay lui
///chia đến số thứ i, với vị trí bắt đầu là pos
void backtrack (int i, int pos)
{
    if (s[pos] == '0') return; ///chữ số bắt đầu không thể là 0
    if (pos > n + 1) return;
    if (pos == n + 1)
    {
        ///nếu đã chia được ít nhất 3 số thì kiểm tra có phải cấp số cộng không
        if (i > 3 && check(i - 1))
            ok = true;
        return;
    }
    ///duyệt qua các độ dài có thể
    for (int len=1;len<=n;++len)
        if (i < 3 || (len >= memo[i - 1] && len >= memo[i - 2])) ///nếu số đang chia là 2 số đầu thì độ dài bao nhiêu cũng được
        ///nếu số đang chia không phải 2 số đầu thì độ dài buộc phải >= độ dài của 2 số liền trước
    {
        memo[i] = len;
        backtrack(i + 1, pos + len);
        memo[i] = 0;
    }
}
int main()
{
	 ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
//	 freopen (file".inp","r",stdin);
//   freopen (file".out","w",stdout);
    cin >> s;
    n = sz(s);
    s = "." + s; ///thêm này vào để tính chỉ số từ 1
    backtrack(1,1);
    if (ok) cout << "true";
    else cout << "false";
    return 0;
}
