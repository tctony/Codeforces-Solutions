#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

int dir(int x1, int y1, int x2, int y2) {
  if (x1 != x2) {
    return x2 > x1 ? 0 : 2;
  }
  else {
    return y2 > y1 ? 1 : 3;
  }
}

void solution() {
  int n, x1, y1, x2, y2;
  int p, q;
  int k, l, m;
  cin >> n;
  cin >> x1 >> y1 >> x2 >> y2;
  p = dir(x1, y1, x2, y2);
  cin >> x1 >> y1;
  q = dir(x2, y2, x1, y1);
  k = l = m = 0;
  k += (q == 2);
  l += (q == 0);
  p = q;
  for (int i=2; i<n; ++i) {
    cin >> x2 >> y2;
    q = dir(x1, y1, x2, y2);
    k += (q == (p+1)%4);
    l += (q == (p+3)%4);
    m += (p==0 && q==3);
    m -= (p==3 && q==0);
    x1 = x2;
    y1 = y2;
    p = q;
  }
  cout << ((m > 0) ? k : l) << endl;
}
