#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

#define N 100001
bool f[N];

void solution() {
  int n, m, u, v, d1 = N, d2 = 0;
  cin >> n >> m;
  while (m--) {
    cin >> u >> v;
    if (u < v) swap(u, v);
    if (u > d2 && v < d1) {
      f[u] = f[v] = true;
      d1 = min(u, d1);
      d2 = max(v, d2);
    }
    else {
      cout << 0;
      return;
    }
  }
  int e = 0;
  for (int i=1; i<=n; ++i) {
    if (f[i] == true || i > d1 || i < d2) continue;
    ++e;
  }
  if (d1 != N) {
    cout << e+1;
  }
  else {
    cout << e-1;
  }
}
