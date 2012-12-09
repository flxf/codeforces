#include <iostream>
#include <fstream>

using namespace std;

int map[5001];

int main() {
  ifstream fin("input.txt");

  int n;
  fin >> n;

  int v;
  for (int i = 0; i < n; i++) {
    fin >> v;
    map[v]++;
  }
  for (int i = 1; i <= 5000; i++) {
    map[i] = map[i] + map[i - 1];
  }
  fin.close();

  int best = 0;
  for (int i = 0; i <= 5000; i++) {
    for (int j = i + 1; j <= 5000; j++) {
      if (2 * (i + 1) >= j && map[j] - map[i] > best) {
        best = map[j] - map[i];
      }
    }
  }

  ofstream fout("output.txt");
  fout << n - best << endl;
  fout.close();
}
