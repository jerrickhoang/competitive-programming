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
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        int n;
        cin >> n;
        int a[n];
        int even = 0;
        int odd = 0;
        for (int j = 0; j < n ; j++)
        {
            cin >> a[j];
            if (a[j] % 2 == 0) even ++;
            else odd ++;
        }
        if (even % 2 == 0 && odd % 2 == 0)  
        {
            cout << "YES" << endl;
            continue;
        }
        if (even % 2 == 0 && odd % 2 != 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (even % 2 != 0 && odd % 2 == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        sort(a, a + n);
        int yes = false;
        for (int j = 1; j < n; j++)
        {
            if (a[j] - a[j-1] == 1) 
            {
                yes = true;
                break;
            }
        }
        if (yes) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}