
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

class uf
{
public:
  VI p, h;
  uf(int n) { 
    h.assign(n, 0);
    p.assign(n, 0);
    REP(i, n) p[i] = i;
  }

  int find(int i) { return p[i] == i ? i : (p[i] = find(p[i])); }
  bool same_set(int i, int j) { return find(i) == find(j) ; }
  void join(int i, int j)
  {
    if (!same_set(i, j))
    {
      int x = find(i);
      int y = find(j);
      if (h[x] > h[y]) p[y] = x;
      else {
        p[x] = y;
        if (h[x] == h[y]) h[y]++;
      }
    }
  }

};

// BEGIN CUT HERE
int main() {
  uf u(5);
  cout << "Joining 0 and 1" << endl;
  cout << "before joining " << u.same_set(0, 1) << endl;
  u.join(0, 1);
  cout << "after joining " << u.same_set(0, 1) << endl;

  cout << "Joining 2 and 3" << endl;
  cout << "before joining " << u.same_set(2, 3) << endl;
  u.join(2, 3);
  cout << "after joining " << u.same_set(2, 3) << endl;
  
  cout << "Joining 2 and 4" << endl;
  cout << "before joining " << u.same_set(2, 4) << endl;
  u.join(2, 4);
  cout << "after joining " << u.same_set(2, 4) << endl;

  cout << "3 and 4 should also be in the same set " << u.same_set(3, 4) << endl;
  
  cout << "Joining 1 and 3" << endl;
  cout << "before joining " << u.same_set(1, 3) << endl;
  u.join(1, 3);
  cout << "after joining " << u.same_set(1, 3) << endl;

  cout << "0 and 3 should also be in the same set " << u.same_set(0, 3) << endl;
  cout << "0 and 2 should also be in the same set " << u.same_set(0, 2) << endl;
  cout << "0 and 4 should also be in the same set " << u.same_set(0, 4) << endl;
}
