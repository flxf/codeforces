#include <iostream>

using namespace std;


int main() {
  int n;
  cin >> n;

  int queue_size = 0;
  int max_queue = 0;

  int last_t = -1;
  for (int i = 0; i < n; i++) {
    int t, c;
    cin >> t >> c;

    int can_be_sent = t - last_t;
    last_t = t;
    queue_size = max(0, queue_size - can_be_sent);
    queue_size += c;

    max_queue = max(queue_size, max_queue);
  }

  cout << last_t + queue_size << " " << max_queue << endl;
}
