#include <iostream>
using namespace std;

int e(int p, int m, int n, int v) {
  if (v < (p*1 - m*n)) return -1;
  else if (v > (p*n - m*1)) return 1;
  return 0;
}

void f(bool s[], int i, int p, int m, int n, int v) {
  if (p == 0 && m == 0) return;

  bool isplus = s[i];
  if (i > 0)
    cout << (isplus ? "+ " : "- ");

  if (isplus) {
    int l = 1, h = n;
    while (l <= h) {
      int d = (l+h) / 2;
      switch(e(p-1, m, n, v-d)) {
      case 0:
        cout << d << " ";
        return f(s, i+1, p-1, m, n, v-d);
      case -1:
        h = d; break;
      case 1:
        l = d+1; break;
      }
    }
    exit(-1);
  }
  else {
    int l = 1, h = n;
    while (l <= h) {
      int d = (l+h) / 2;
      switch(e(p, m-1, n, v+d)) {
      case 0:
        cout << d << " ";
        return f(s, i+1, p, m-1, n, v+d);
      case -1:
        l = d+1; break;
      case 1:
        h = d; break;
      }
    }
    exit(-1);
  }
}

int main() {
  bool s[100];
  int n = 0, p = 0, m = 0;
  int v;

  bool isplus = true;
  bool end = false;
  while (!end) {
    switch(getchar()) {
    case ' ': break;
    case '?': {
      s[n] = isplus;
      if (s[n]) p++; else m++;
      n++;
      break;
    }
    case '+': isplus = true; break;
    case '-': isplus = false; break;
    case '=': end = true; break;
    }
  }
  cin >> v;

  if (e(p, m, v, v) == 0) {
    cout << "Possible" << endl;

    f(s, 0, p, m, v, v);
    cout << "= " << v;
  }
  else {
    cout << "Impossible" << endl;
  }

  return 0;
}
