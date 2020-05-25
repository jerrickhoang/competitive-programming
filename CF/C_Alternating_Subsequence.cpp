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


ll solve(ll a[], int n)
{
    bool pos = a[0] > 0;
    ll max_pos = numeric_limits<ll>::lowest();
    ll max_neg = max_pos;
    ll res = 0;
    for (int i = 0; i < n; i ++)
    {
        if (a[i] > 0)
        {
            if (pos)
            {
                max_pos = max(max_pos, a[i]);
            }
            else {
                res += max_neg;
                max_pos = a[i];
                pos = true;
            }
        }
        else
        {
            if (pos)
            {
                res += max_pos;
                max_neg = a[i];
                pos = false;
            }
            else
            {
                max_neg = max(max_neg, a[i]);
            }
        }
    }
    if (pos) res += max_pos;
    else res += max_neg;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        ll a[n];
        for (int j = 0; j < n; ++j)
        {
            cin >> a[j];
        }
        auto res = solve(a, n);
        cout <<res <<endl;
    }
    return 0;
}