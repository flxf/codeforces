#include <fstream>

using namespace std;

int main() {
  ifstream fin("input.txt");

  int n, m;
  fin >> n >> m;
  fin.close();

  ofstream fout("output.txt");
  if (n > m) {
    for (int i = 0; i < m; i++) {
      fout << "BG";
    }
    for (int i = 0; i < n - m; i++) {
      fout << "B";
    }
    fout << endl;
  } else {
    for (int i = 0; i < n; i++) {
      fout << "GB";
    }
    for (int i = 0; i < m - n; i++) {
      fout << "G";
    }
    fout << endl;
  }
  fout.close();
}
