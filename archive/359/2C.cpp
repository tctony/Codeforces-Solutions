#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

int a[] = { 0, 1, 2, 3, 4, 5, 6 };

int w(int x) {
  int c = 0;
  do {
    c++;
    x /= 7;
  } while(x >0);
  return c;
}

int i7(int s, int e) {
  int v = 0;
  while (s < e) {
    v = v * 7 + a[s];
    s++;
  }
  return v;
}

bool d(int s, int e) {
  static set<int> ds;
  int b = i7(s, e);
  if (ds.find(b) == ds.end()) {
    ds.insert(b);
    return true;
  }
  return false;
}

void solution() {
  int n, m;
  scanf("%d %d", &n, &m);
  int wn = w(n-1), wm = w(m-1);
  if ((n == 1 && m == 1)
      || (wn + wm > 7)) {
    printf("0");
    return;
  }
  else {
    int c = 0;
    do {
      if (d(0, wn+wm) && i7(0, wn) < n && i7(wn, wn+wm) < m) {
        ++c;
      }
    } while (next_permutation(a, a+7));
    printf("%d", c);
  }
}
