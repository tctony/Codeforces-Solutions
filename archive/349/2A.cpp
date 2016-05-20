#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

void solution() {
  int n, x, y, t;
  bool f = false;
  t = 0;
  cin >> n;
  y = 0;
  for (int i=0; i<n; ++i) {
    cin >> x;
    if (x - y > 15) {
      t += 15;
      f = true;
      break;
    }
    else {
      t += x - y;
      y = x;
    }
  }
  if (f == false && y < 90) {
    t += (90 - y) > 15 ? 15 : (90 - y);
  }
  cout << t;
}
