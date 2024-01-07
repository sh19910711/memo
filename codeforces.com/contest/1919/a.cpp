#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
typedef long long int_t;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int t;
  cin >> t;
  rep(_, t) {
    int_t a, b;
    cin >> a >> b;
    if ((a + b) % 2 == 0) {
      cout << "Bob" << endl;
    } else {
      cout << "Alice" << endl;
    }
  }

  return 0;
}