#include <iostream>
#include <cmath>
//#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

void solution() {
  int x, y, n, xi, yi, vi;
  double t = 500;
  scanf("%d %d %d", &x, &y, &n);
  while(n--) {
    scanf("%d %d %d", &xi, &yi, &vi);
    if (xi == x && yi == y) {
      printf("0");
      return;
    }
    else {
      t = min(t, sqrt(pow((double)(xi-x), 2) + pow((double)(yi-y), 2)) / vi);
    }
  }
  printf("%lf", t);
}
