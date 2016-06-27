#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

int n, a[101];

void solution() {
  scanf("%d", &n);
  for (int i=1; i<=n; ++i)
    scanf("%d", &a[i]);

  for (int k=1; k<n; ++k) {
    int j = k;
    for (int i=j+1; i<=n; ++i)
      if (a[i] < a[j])
        j = i;
    while (j > k) {
      printf("%d %d\n", j-1, j);
      swap(a[j], a[j-1]);
      --j;
    }
  }
}
