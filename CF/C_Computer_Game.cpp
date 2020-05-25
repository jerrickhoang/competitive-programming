/**
    __author__ : hta314 
    problems_ID:
*/

#include <bits/stdc++.h>
using namespace std;
#define mp             make_pair
#define pb             push_back
#define fi             first
#define se             second
#define sz(x)          (int)((x).size())
#define fill(x, y)     memset(x, y, sizeof(y))
#define all(x)         (x).begin(), (x).end()
#define sci(x)         int x;       scanf("%d", &x);
#define scii(x, y)     int x, y;    scanf("%d %d", &x, &y);
#define sciii(x, y, z) int x, y, z; scanf("%d %d %d", &x, &y, &z);
#define TC(x)          sci(x); while(x --)
#define eprintf(...)   fprintf(stderr, __VA_ARGS__)
#define debug(x)       { cerr << #x << " = " << x << endl; }
#define rep(i, x, y)   for (__typeof(x) i = x; i <= y; i ++)
#define repi(i, x, y)  for (__typeof(x) i = x; i >= y; i --)
#define fore(itr, x)   for (__typeof(x.begin()) itr = x.begin(); itr != x.end(); itr ++)
#define forei(itr, x)  for (__typeof(x.end()) itr = x.end() - 1; itr != x.begin() - 1; itr --)
typedef long long      ll;
typedef pair<int, int> ii;
typedef pair<ii, int>  iii;
typedef vector<int>    vi;
typedef vector<ii>     vii;
typedef vector<iii>    viii;
const   int            inf = 0;
const   double         eps = 0;
const   int            ms  = 0;
const   int            md  = 0;


// a * mid + a + b * (n - mid - 1) > k

ll solve(ll k, ll n, ll a, ll b)
{
    if (k - n*a > 0)
    {
        return n;
    }

    if (k <= n*b )
    {
        return -1;
    }

    ll lo = 0;
    ll hi = n - 1;
    while (lo <= hi)
    {
        ll mid = lo + ( hi - lo) / 2;
        if (k - mid * a - (n - mid) * b > 0 && k - (mid + 1) * a - (n - mid - 1) * b <= 0)
        {
            return mid;
        }
        if (k - mid * a - (n - mid) * b > 0)
        {
            lo = mid + 1;
        }
        else
        {
            hi = mid - 1;
        }
        
    }
    
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    ll q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        cout << solve(k, n, a, b) << endl;
    }
    return 0;
}