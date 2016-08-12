#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

void solution() {
  int n, q, x;
  vector<int> v;
  scanf("%d", &n);
  for (int i=0; i<n; ++i) {
    scanf("%d", &x);
    v.push_back(x);
  }
  sort(v.begin(), v.end());
  scanf("%d", &q);
  while(q--) {
    scanf("%d", &x);
    printf("%d\n", int(upper_bound(v.begin(), v.end(), x) - v.begin()));
  }
}
