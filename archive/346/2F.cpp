#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }


int n, m;
long long k;
vector<int> a, b;
map<int, int> e;
vector<int> f;
vector<bool> v;

bool cmp(int x, int j) {
  return a[x] > a[j];
}

int find(int i) {
  int fi = f[i];
  if (fi == -1) return -1;
  else if (fi == i) return i;
  else return (f[i] = find(fi));
}

void dfs(int ri, int i) {
  if (a[i] < a[ri]) return;
  else if (a[i] > a[ri]) {
    int fi = find(i);
    if (ri == fi) return;
    f[fi] = ri;
    e[ri] += e[fi];
    e.erase(fi);
  }
  else {
    if (v[i] != 0) return;
    v[i] = 1;
    f[i] = ri;
    e[ri] += 1;
    int x = i / m, y = i % m;
    if (y > 0) dfs(ri, i-1);
    if (x > 0) dfs(ri, i-m);
    if (y < m-1) dfs(ri, i+1);
    if (x < n-1) dfs(ri, i+m);
  }
}

void mark(int t, int i) {
  if (k == 0) return;
  if (a[i] < t) return;
  a[i] = 0;
  k -= t;
  int x = i / m, y = i % m;
  if (y > 0) mark(t, i-1);
  if (x > 0) mark(t, i-m);
  if (y < m-1) mark(t, i+1);
  if (x < n-1) mark(t, i+m);
}

void solution() {
  scanf("%d %d %lld", &n, &m, &k);
  for (int i=0, t; i<n*m; ++i) {
    scanf("%d", &t);
    a.emplace_back(t);
    b.emplace_back(i);
  }
  sort(b.begin(), b.end(), cmp);
  f.insert(f.end(), a.size(), -1);
  v.insert(v.end(), a.size(), 0);
  for (int i=0, j, t; i<a.size(); ++i) {
    j = b[i], t = a[j];
    if (v[j] != 0) continue;
    dfs(j, j);

    if (k % t == 0 && e[j] >= k / t) {
      printf("YES\n");
      mark(t, j);
      for (int i=0; i<n; ++i) {
        for (int j=0; j<m; ++j) {
          printf("%d%c",
                 a[i*m+j] == 0 ? t : 0,
                 j<m-1 ? ' ' : '\n');
        }
      }
      return;
    }
  }
  printf("NO\n");
}
