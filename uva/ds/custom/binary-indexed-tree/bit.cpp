
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

int lsone(int b)
{
  return (b & -b);
}

class bit
{
public:
  VI ft;
  bit(int n) { ft.assign(n+1, 0); }
  int rsq(int b) {
    int res = 0;
    for (; b ; b -= lsone(b)) res += ft[b];
    return res;
  }

  int rsq(int a, int b)
  {
    return rsq(b) - ((a == 1) ? 0 : rsq(a-1));
  }

  void update(int b, int v)
  {
    for (; b < ft.size(); b += lsone(b)) ft[b] += v;
  }
};

int main() {
  int f[] = { 2, 4, 5, 5, 6, 6, 6, 7, 7, 8, 9 };
  bit ft(10);
  // dynamic frequency table
  REP(i, 11) ft.update(f[i], 1);

  printf("%d\n", ft.rsq(1, 1)); // 0 => ft[1] = 0
  printf("%d\n", ft.rsq(1, 2)); // 1 => ft[2] = 1
  printf("%d\n", ft.rsq(1, 6)); // 7 => ft[6] + ft[4] = 5 + 2 = 7
  printf("%d\n", ft.rsq(1, 10)); // 11 => ft[10] + ft[8] = 1 + 10 = 11
  printf("%d\n", ft.rsq(3, 6)); // 6 => rsq(1, 6) - rsq(1, 2) = 7 - 1
  ft.update(5, 2);
  printf("%d\n", ft.rsq(1, 10)); // now 13
}
