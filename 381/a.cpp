#include <iostream>

using namespace std;

int nums[1000];
int scores[2];

int main() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> nums[i];
  }

  int left = 0;
  int right = n - 1;

  for (int i = 0; i < n; i++) {
    if (nums[left] > nums[right]) {
      scores[i % 2] += nums[left];
      left++;
    } else {
      scores[i % 2] += nums[right];
      right--;
    }
  }

  cout << scores[0] << " " << scores[1] << endl;
}
