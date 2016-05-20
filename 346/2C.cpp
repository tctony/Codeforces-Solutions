#include <bits/stdc++.h>
using namespace std;
void solution();
int main() { ios_base::sync_with_stdio(0); cin.tie(0); solution(); return 0; }

#define T 1000000001
bitset<T> bits;
vector<int> ans;

void solution() {
  int n, m, k;
  cin >> n >> m;
  for (int i=0; i<n; ++i) {
    cin >> k;
    bits[k] = 1;
  }
  for (int i=1; i<T; ++i) {
    if (bits[i] == 1) continue;
    if (m < i) break;
    bits[i] = 1;
    ans.emplace_back(i);
    m -= i;
  }
  cout << ans.size() << endl;
  for (int i=0; i<ans.size(); ++i)
    cout << ans[i] << " ";
}
