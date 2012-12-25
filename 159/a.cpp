#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <utility>

using namespace std;

int A[1000];
int B[1000];
int T[1000];

bool friends[2000][2000];

string id_to_name[2000];
map<string, int> name_to_id;

int main() {
  int n, d;
  cin >> n >> d;

  string a, b;
  int t;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> t;
    if (name_to_id.find(a) == name_to_id.end()) {
      name_to_id[a] = cnt;
      id_to_name[cnt] = a;
      cnt++;
    }

    if (name_to_id.find(b) == name_to_id.end()) {
      name_to_id[b] = cnt;
      id_to_name[cnt] = b;
      cnt++;
    }

    A[i] = name_to_id[a];
    B[i] = name_to_id[b];
    T[i] = t;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (A[j] == B[i] && A[i] == B[j]) {
        if (T[i] - T[j] <= d && T[i] - T[j] > 0) {
          friends[A[i]][B[i]] = true;
          friends[B[i]][A[i]] = true;
        }
      }
    }
  }

  int fc = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (friends[i][j]) {
        fc++;
      }
    }
  }

  cout << fc << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      if (friends[i][j]) {
        cout << id_to_name[i] << " " << id_to_name[j] << endl;
      }
    }
  }
}
