#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

void solution() {
  int n, c = 0;
  long long x;

  scanf("%d %lld", &n, &x);
  while (n--) {
    char s;
    int d;
    scanf("\n%c %d", &s, &d);
    if (s == '+') {
      x += d;
    }
    else {
      if (x >= d) {
        x -= d;
      }
      else {
        ++c;
      }
    }
  }

  printf("%lld %d\n", x, c);
}
