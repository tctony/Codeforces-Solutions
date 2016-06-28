#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

int n;
vector<int> p;
vector<vector<int>> t;
vector<int> h;
vector<int> f;
vector<int> r;

void count(int k) {
  for (int j=0; j<t[k].size(); ++j) {
    count(t[k][j]);
    if (f[t[k][j]] > f[h[k]])
      h[k] = t[k][j];
    f[k] += f[t[k][j]];
  }
  if (f[k] <= 2) r[k] = k;
  if (f[h[k]] <= f[k]/2) r[k] = k;
}

int find(int s, int k) {
  if (s == k) {
    if (r[k] > 0) return r[k];
    return (r[k] = find(k, h[k]));
  }
  else {
    int fk = find(k, k);
    while (f[s] - f[fk] > f[s]/2)
      fk = p[fk];
    return fk;
  }
}

void solution() {
  int m;
  scanf("%d %d", &n, &m);
  p.resize(n+1);
  t.resize(n+1);
  h.resize(n+1);
  f.resize(n+1, 1);
  f[0] = 0;
  r.resize(n+1);

  for (int i=2, k; i<=n; ++i) {
    scanf("%d", &k);
    p[i] = k;
    t[k].emplace_back(i);
  }

  count(1);

  for (int i=0, k; i<m; ++i) {
    scanf("%d", &k);
    printf("%d\n", find(k, k));
  }
}
