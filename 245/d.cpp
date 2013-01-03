#include <cstdio>

using namespace std;

int a[100];
int b[100][100];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &(b[i][j]));
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) {
      a[i] |= b[i][j];
      a[j] |= b[i][j];
    }
  }

  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}
