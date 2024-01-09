#include <bits/stdc++.h>
using namespace std;
#define loop ri(__num_cases); rep(__case,__num_cases)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define per(i, n) for (int i = n-1; i >= 0; --i)
template <class ...Args> auto& __ri(Args &...args) { return (cin >> ... >> args); }
#define ri(...) int_t __VA_ARGS__; __ri(__VA_ARGS__)
#define rin(arr,num) int_t arr[num]; rep(i,num) cin >> arr[i]
typedef long long int_t;
typedef vector<int_t> vi;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  loop {
    // ri(n);
    // rin(a,n);
    ri(n, m);
    vector<int_t> t[n];
    fill(t,t+n,vector<int_t>(m));
    rep(i,n) {
      rin(a, m);
      rep(j, m) t[i][j] = a[j];
    }

    vector<int_t> t2[n];
    rep(i,n) t2[i] = t[i];
    rep(i,n) sort(t2[i].begin(), t2[i].end());

    int pos[n][2];
    int npos[n];
    fill(npos, npos+n, 0);

    [&]() {
      rep(i,n) rep(j,m) {
        if(t[i][j] != t2[i][j]) {
          if (npos[i] >= 2) {
            cout << -1 << endl;
            return;
          }
          pos[i][npos[i]++] = j;
        }
      }

      int p = -1;
      [&]() {
        rep(i,n) if(npos[i] == 2) {
          p = i;
          rep(x,n) swap(t[x][pos[i][0]], t[x][pos[i][1]]);
          return;
        }
      }();

      if (p == -1) {
        cout << "1 1" << endl;
        return;
      }

      rep(i,n) rep(j,m) if(t[i][j] != t2[i][j]) {
        cout << -1 << endl;
        return;
      }

      cout << pos[p][0]+1 << " " << pos[p][1]+1 << endl;
    }();
  }

  return 0;
}

/***
auto f = [&](int x) -> int { return x; };
tuple<int,string> x(42, "foo"); auto [t1, t2] = x;

flags: -Wall -Wextra -Wshadow -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fmax-errors=2 -std=c++17
https://codeforces.com/blog/entry/79024
***/