#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

void solution() {
  int n, a, b;
  cin >> n >> a >> b;
  b = b % n;
  b = b >= 0 ? b : b + n;
  cout << (a + b - 1) % n + 1<< endl;
}
