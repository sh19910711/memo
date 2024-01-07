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
    int n;
    cin >> n;
    string s;
    cin >> s;

    bool used[n];
    fill(used, used+n, false);
    stack<int> st;
    rep(i,n) {
      if(st.empty()) {
        st.push(i);
        continue;
      }
      if(s[st.top()] == s[i]) {
        st.push(i);
      } else {
        st.pop();
      }
    }

    cout << st.size() << endl;
  }

  return 0;
}