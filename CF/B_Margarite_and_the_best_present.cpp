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

// -1
// -1 + 2 = 1
// - 1 + 2 - 3 = -2
// -1 + 2 -3 + 4 = 2
// r = 2k , s_r = k
// r = 2 k + 1, s_r = -k - 1

int s(int r)
{
    return r %2 == 0? r/2 : -r/2 - 1;
}

int main() {
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r;
        cin >> l >> r;
        int m = l % 2 == 0? l : -l;
        cout << s(r) - s(l) + m << endl;
    }
    return 0;
}