#include <iostream>
#include <map>

using namespace std;

int bit_count[100001][20];
int n;
int query_count[20];
int query_sum[20];

map<int, int> layers;

void query(int l, int r) {
  l--;
  r--;
  int* L = bit_count[l];
  int* R = bit_count[r];
  for (int i = 0; i < 20; i++) {
    query_count[i] = R[i] - L[i];
  }
}

void xq(int l, int r, int x) {
  int sz = (r - l);
  for (int i = 0; i < 20; i++) {
    if ((x & (1 << i)) != 0) {
      query_count[i] = (sz - query_count[i]);
    }
  }
}

void addquery() {
  for (int i = 0; i < 20; i++) {
    query_sum[i] += query_count[i];
  }
}

void resetsum() {
  for (int i = 0; i < 20; i++) {
    query_sum[i] = 0;
  }
}

void outputsum() {
  unsigned long long sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += (1ULL << i) * query_sum[i];
  }
  cout << sum << endl;
}

map<int, int>::iterator leftof(int l) {
  map<int, int>::iterator it = layers.lower_bound(l);
  if (it->first > l) {
    it--;
  }
  return it;
}

map<int, int>::iterator rightof(int r) {
  map<int, int>::iterator it = layers.lower_bound(r);
  if (it->first == r) {
    it++;
  }
  return it;
}

int main() {
  cin >> n;

  for (int j = 0; j < 20; j++) {
    bit_count[0][j] = 0;
  }

  int a;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    for (int j = 0; j < 20; j++) {
      bit_count[i][j] = bit_count[i - 1][j];
      if ((a & (1 << j)) != 0) {
        bit_count[i][j]++;
      }
    }
  }

  int m;
  cin >> m;

  int t, l, r, x;
  map<int, int>::iterator lft, rgt, peek;

  layers[1] = 0;
  layers[n + 1] = 0;
  for (int i = 0; i < m; i++) {
    cin >> t >> l >> r;

    if (t == 1) {
      lft = leftof(l);
      peek = lft;
      rgt = rightof(r);

      resetsum();
      while (lft != rgt) {
        peek++;
        int ql = max(l, lft->first);
        int qr = min(r + 1, peek->first);
        query(ql, qr);
        xq(ql, qr, lft->second);
        addquery();
        lft++;
      }

      outputsum();
    } else {
      cin >> x;

      lft = leftof(l);
      if (layers.find(l) == layers.end()) {
        layers[l] = lft->second;
        lft = leftof(l);
      }
      if (layers.find(r + 1) == layers.end()) {
        rgt = leftof(r);
        layers[r + 1] = rgt->second;
      }
      rgt = rightof(r);

      while (lft != rgt) {
        lft->second = lft->second ^ x;
        lft++;
      }
    }

  }
}
