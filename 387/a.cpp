#include <iostream>
#include <cstdio>

using namespace std;

#define MIN_IN_DAY 60 * 24

int str_to_int(string time) {
  int hours = (time[0] - '0') * 10 + (time[1] - '0');
  int minutes = (time[3] - '0') * 10 + (time[4] - '0');

  return hours * 60 + minutes;
}

void int_to_str(int time) {
  int hours = time / 60;
  int minutes = time % 60;
  printf("%02d:%02d\n", hours, minutes);
}

int main() {
  string s, t;
  cin >> s >> t;

  int wake = str_to_int(s);
  int len = str_to_int(t);

  int start = wake - len;
  if (start < 0) {
    start += MIN_IN_DAY;
  }

  int_to_str(start);
}
