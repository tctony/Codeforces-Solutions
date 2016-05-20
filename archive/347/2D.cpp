#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

const int MAXN = 100000;
vector<pair<int, char>> v[MAXN];
char s[MAXN];
vector<int> part[3];
int n;

bool g(int t, int p, char c) {
  if (s[t] != 0)
    return s[t] == p;

  s[t] = p;
  part[p].push_back(t);

  for (auto x : v[t]) {
    if (g(x.first, x.second == c ? p : p^3, c) == false)
      return false;
  }

  return true;
}

vector<int> f(char c) {
  memset(s, 0, n);
  vector<int> ans;

  for (int i=0; i<n; ++i) {
    if (s[i] == 0) {
      part[1].clear();
      part[2].clear();

      if (g(i, 1, c) == false) {
        return vector<int>(n+1, -1);
      }

      int x = 1;
      if (part[2].size() < part[1].size()) x = 2;
      ans.insert(ans.end(), part[x].begin(), part[x].end());
    }
  }

  return ans;
}

void solution() {
  int m, i, j;
  char c;
  scanf("%d %d", &n, &m);
  while (m--) {
    scanf("%d %d %c", &i, &j, &c);
    --i, --j;
    v[i].emplace_back(j, c);
    v[j].emplace_back(i, c);
  }

  auto r = f('R');
  auto b = f('B');

  if (b.size() < r.size()) r = b;

  if (r.size() > n) {
    printf("-1\n");
  }
  else {
    printf("%d\n", (int)r.size());
    for (int x : r) printf("%d ", x+1);
    printf("\n");
  }
}
