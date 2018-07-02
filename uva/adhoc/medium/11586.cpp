
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

// BEGIN CUT HERE
int main() {
  int n;
  cin >> n;
  REP(i, n)
  {
    std::string w, l;
    int total, cur;
    total= -1;
    getline(cin, l);
    stringstream ss(l);
    int valid = 1;
    while(ss >> w)
    {
      if (w == "MM") cur = 0;
      if (w == "MF") cur = 1;
      if (w == "FF") cur = 2;
      if (w == "FM") cur = 3;
      if (total == -1) continue;
      if ((total== 0 && (cur == 0 || cur == 1)) || 
          (total== 1 && (cur == 2 || cur == 3)) || 
          (total== 2 && (cur == 2 || cur == 3)) || 
          (total== 3 && (cur == 0 || cur == 1)))
      {
        valid = 0;
        break;
      }

      if (total == 0)
      {
        if (cur == 2) total = 1;
        else if (cur == 3) { total = 0; valid = 0;}
      }
      else if (total == 1)
      {
        if (cur == 0) { total = 0; valid = 0; }
        else if (cur == 1) total = 1;
      }
      else if (total == 2)
      {
        if (cur == 0) total = 3;
        else if (cur == 1) {total = 2; valid = 0;}
      }
      else if (total == 3)
      {
        if (cur == 2) {total = 2; valid = 0;}
        else if (cur == 3) total = 3;
      }
    }
    if (valid == 0)
    {
      cout << "NO LOOP" << endl;
    }
    else {
      cout << "LOOP" << endl;
    }
  }
}
