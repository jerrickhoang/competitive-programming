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


int main() {
    ios::sync_with_stdio(false);
   	int n; scanf("%d",&n);
    vector<ii> p;
    ll ans = 1ll * n * n;
    for (int i = 0; i < n; i++)
    {
		int l; scanf("%d",&l);
        vector<ll> a(l);
		for(int j=0; j<l; j++) scanf("%d",&a[j]);
        reverse(all(a));
        if (is_sorted(all(a)))
        {
            p.emplace_back(a[0], a.back());
        }
    }
    sort(all(p));
    for (int i = 0; i < p.size(); ++i)
    {
        ans -= p.end() - lower_bound(all(p), ii(p[i].second, -1));
    }
    cout << ans << endl;
}