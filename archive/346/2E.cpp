#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

int n;
vector<int> f;
vector<array<int, 2> > p;

int find(int x) {
  int fx = f[x];
  if (fx == 0) return 0;
  else if (fx < 0) return x;
  else return (f[x] = find(fx));
}

void solution() {
  scanf("%d", &n);
  f.insert(f.end(), n+1, 0);

  int m;
  scanf("%d", &m);
  for (int i=0; i<m; ++i) {
    int u, v, fu, fv, pu, pv;
    scanf("%d %d", &u, &v);
    fu = find(u); fv = find(v);
    pu = f[fu]; pv = f[fv];
    if (pu == 0 && pv == 0) {
      p.push_back(array<int, 2>{2, 1});
      f[u] = -p.size();
      f[v] = u;
    }
    else if (pu == 0 || pv == 0) {
      if (pu == 0) pu = pv, fu = fv, v = u;
      p[-pu-1][0]++;
      p[-pu-1][1]++;
      f[v] = fu;
    }
    else if (pu == pv) {
      p[-pu-1][1]++;
    }
    else {
      p[-pu-1][0] += p[-pv-1][0];
      p[-pu-1][1] += p[-pv-1][1] + 1;
      f[fv] = fu;
      p[-pv-1][0] = 0;
    }
  }

  int k=0;
  for (int i=1; i<=n; ++i) {
    k += (f[i] == 0);
  }
  for (int i=0; i<p.size(); ++i) {
    k += (p[i][0] > 0 && p[i][1] == p[i][0]-1);
  }

  printf("%d\n", k);
}
