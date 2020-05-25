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

bool check(ll a[], ll n, ll k, ll mid)
{
    ll s = 0ll;
    for (size_t i = n / 2; i < n; ++i )
    {
        s += max(0ll, mid - a[i]);
    }
    return s <= k;
}

ll solve(ll a[], ll n, ll k)
{
    ll lo = a[n/2];
    ll hi = lo + k;
    ll s;
    while (lo <= hi)
    {
        ll mid = lo + (hi - lo ) / 2;
        if (check(a, n, k, mid))
        {
            lo = mid + 1;
            s = mid;
        }
        else
        {
            hi = mid - 1;
        }
    }
    return s;
}

int main() {
    ios::sync_with_stdio(false);
    ll n, k;
    cin >> n >> k;
    ll a[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cout << solve(a, n, k) << endl;
}