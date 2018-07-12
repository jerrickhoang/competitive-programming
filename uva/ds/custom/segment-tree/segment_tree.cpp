
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>
#include <queue>

using namespace std;

//conversion
//------------------------------------------
inline int toInt(string s) {int v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) {ostringstream sout;sout<<x;return sout.str();}

//math
//-------------------------------------------
template<class T> inline T sqr(T x) {return x*x;}

//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL;

//container util
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())

//repetition
//------------------------------------------
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)

//constant
//--------------------------------------------
const double EPS = 1e-10;
const double PI  = acos(-1.0);

//clear memory
#define CLR(a) memset((a), 0 ,sizeof(a))

//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

class segment_tree
{
  public:
    VI a;
    int n;
  segment_tree(int N) {
    a.assign(2*N, 0);
    n = N;
  }

  void build(int b[])
  {
    REP(i, n) a[i+n] = b[i];
    for (int i = n - 1; i > 0; i --) a[i] = a[i<<1] + a[i<<1 | 1];
  }

  void update(int p, int value)
  {
    a[p+n] = value;
    p = p + n;
    for (int i = p; i > 1; i >>=1)
    {
      a[i>>1] = a[i] + a[i^1];
    }
  }

  int query(int l, int r)
  {
    int res = 0;
    for (r += n, l+= n; l < r; l >>= 1, r >>= 1)
    {
      if (r & 1)
        res += a[--r];
      if (l & 1)
        res += a[l++];
    }
    return res;
  }

};

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    segment_tree st(12);
    st.build(a);
    cout << st.query(1, 3)<<endl;
    st.update(2, 1);
    cout << st.query(1, 3)<<endl;

    return 0;
}
