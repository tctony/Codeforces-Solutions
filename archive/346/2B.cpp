#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

#define M 10000
vector<pair<string, int> > r[M];

bool compare(const pair<string, int> & a,
             const pair<string, int> & b) {
  return a.second < b.second;
}

char s[11];

void solution() {
  int n, m;
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; ++i) {
    int k, p;
    scanf("%s %d %d", &s, &k, &p);
    r[k-1].emplace_back(string(s), p);
    push_heap(r[k-1].begin(), r[k-1].end(), compare);
  }

  for (int i = 0; i < m; ++i) {
    pair<string, int> x, y, z;
    x = r[i].front();
    pop_heap(r[i].begin(), r[i].end(), compare);
    r[i].pop_back();

    y = r[i].front();
    pop_heap(r[i].begin(), r[i].end(), compare);
    r[i].pop_back();

    if (r[i].size() > 0) {
      z = r[i].front();
      if (z.second == y.second) {
        printf("?\n");
      }
      else {
        printf("%s %s\n", x.first.c_str(), y.first.c_str());
      }
    }
    else {
      printf("%s %s\n", x.first.c_str(), y.first.c_str());
    }
  }
}
