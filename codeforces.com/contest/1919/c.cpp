#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  rep(_,t) {
    int n;
    cin >> n;
    int a[n];
    rep(i,n) cin >> a[i];

    int res = 0;
    int x, y;
    x = y = n+1;
    rep(i,n) {
      if(x>=y) swap(x,y);
      if(a[i] <= x) {
        x = a[i];
      } else if (a[i] <= y) {
        y = a[i];
      } else {
        x = a[i];
        res++;
      }
    }
    cout << res << endl;
  }

  return 0;
}