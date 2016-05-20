#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

void solution() {
  int n;
  char s[15];
  int k, y, f, p;
  scanf("%d", &n);
  while (n--) {
    scanf(" %s", s);
    k = strlen(s + 4);
    y = atoi(s + 4);
    f = 0;
    p = 10;
    for (int i=1; i<k; ++i) {
      f += p;
      p *= 10;
    }

    while (y < 1989 + f) y += p;

    printf("%d\n", y);
  }
}
